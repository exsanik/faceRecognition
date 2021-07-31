#pragma once
#include "Libs.h"

faceDetection::faceDetection()
{
	inWidth = 200;
	inHeight = 200;
	inScaleFactor = 1.0;
	meanVal[0] = 104.0;
	meanVal[1] = 177.0;
	meanVal[2] = 123.0;
	deviceID = 1;
	log.open("logs/logDetection.txt", std::ios_base::app);
	source = "";

	coeffSimil = 0.5;
	if (net.empty())
	{
		log << "Can't load network by using the following files: net/res10_300x300_ssd_iter_140000.caffemodel, net/deploy.prototxt" << std::endl;
		return;
	}
}

faceDetection::~faceDetection()
{
	log.close();
}

void faceDetection::detectFace(System::Windows::Forms::PictureBox^ pictureBox)
{
	if (!cap.isOpened())
		if (source == "")
			cap.open(deviceID);
		else
		{
			try
			{
				if(source.find(".mp4") != std::string::npos)
					cap.open(source);
			}
			catch (std::exception &e)
			{
				log << e.what() << std::endl;
			}
		}
	if (!cap.isOpened() && (source.find(".jpg") == std::string::npos))
	{
		log << "Can not open caption. Device id:" << deviceID << std::endl;
		log << "or can not open:" << source << std::endl;
		cap.open(0);
		if (!cap.isOpened())
		{
			log << "Can not open caption. Device id:" << 0 << std::endl;
			return;
		}
	}
	pictureBox->Focus();
	detect = true;

	while (cv::waitKey(30) < 0 || detect)
	{
		if (detect == false)
			break;
		cv::Mat frame;
		if (source.find(".jpg") != std::string::npos)
			frame = cv::imread(source);
		else
			cap >> frame;
		if (frame.empty())
			break;
		cv::flip(frame, frame, 1);
		cv::Mat pic = frame.clone();
		cv::Rect obj = detectPerson(frame);

		if (!obj.empty() && save == true)
		{
			try
			{
				save = false;
				tempMat = pic(obj);
				saved = true;
				return;
			}
			catch (std::exception &e)
			{
				log << e.what() << std::endl;
				return;
			}
		}
		try
		{
			pictureBox->Image = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step1(), System::Drawing::Imaging::PixelFormat::Format24bppRgb, System::IntPtr(frame.data));
			pictureBox->Refresh();
		}
		catch (...)
		{
			cv::resize(frame, frame, cv::Size(frame.cols * 4, frame.rows * 4));
			pictureBox->Image = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step1(), System::Drawing::Imaging::PixelFormat::Format24bppRgb, System::IntPtr(frame.data));
			pictureBox->Refresh();
		}
	}
	cap.release();
}

void faceDetection::stopDetection() 
{
	detect = false; 
}

void faceDetection::saveFace()
{
	save = true;
}

void faceDetection::setCoeffSimil(float coeff)
{
	if (coeff >= 0 && coeff <= 1)
		coeffSimil = coeff;
}

void faceDetection::setWidth(size_t width)
{
	if (width > 0 && width < 1000)
		inWidth = width;
}

void faceDetection::setHeight(size_t height)
{
	if (height > 0 && height < 1000)
		inHeight = height;
}

void faceDetection::setCamId(int cid)
{
	if (cid >= 0)
		deviceID = cid;
}

void faceDetection::setSource(std::string path)
{
	source = path;
}

std::string faceDetection::getSource()
{
	return source;
}

int faceDetection::getCamId()
{
	return deviceID;
}

size_t faceDetection::getWidth()
{
	return inWidth;
}

size_t faceDetection::getHeight()
{
	return inWidth;
}

float faceDetection::getCoeffSimil()
{
	return coeffSimil;
}

int faceDetection::getSaveState()
{
	if (save == true && saved == false)
		return 0;
	if (saved == true)
	{
		saved = false;
		return 1;
	}
	else
		return -1;
}

bool faceDetection::getState()
{
	return detect;
}

cv::Rect faceDetection::detectPerson(cv::Mat & frame)
{
	if (frame.channels() == 4)
		cvtColor(frame, frame, cv::COLOR_BGRA2BGR);

	//! [Prepare blob]
	cv::Mat inputBlob = cv::dnn::blobFromImage(frame, inScaleFactor,
		cv::Size(inWidth, inHeight), meanVal, false, false); //Convert Mat to batch of images

	//! [Set input blob]
	net.setInput(inputBlob, "data"); //set the network input

	//! [Make forward pass]
	cv::Mat detection = net.forward("detection_out"); //compute output

	std::vector<double> layersTimings;
	double freq = cv::getTickFrequency() / 1000;
	double time = net.getPerfProfile(layersTimings) / freq;

	cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

	std::ostringstream ss;
	ss << "FPS: " << 1000 / time << " ; time: " << time << " ms";
	putText(frame, ss.str(), cv::Point(20, 20), 0, 0.5, cv::Scalar(0, 0, 255));

	float confidenceThreshold = 0.5;
	cv::Rect face;
	for (int i = 0; i < detectionMat.rows; i++)
	{
		float confidence = detectionMat.at<float>(i, 2);

		if (confidence > confidenceThreshold)
		{
			int xLeftBottom = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
			int yLeftBottom = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
			int xRightTop = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
			int yRightTop = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);

			cv::Rect object((int)xLeftBottom, (int)yLeftBottom,
				(int)(xRightTop - xLeftBottom),
				(int)(yRightTop - yLeftBottom));

			cv::rectangle(frame, object, cv::Scalar(0, 255, 0));

			ss.str("");
			ss << confidence;
			cv::String conf(ss.str());
			cv::String label = "Face: " + conf;
			int baseLine = 0;
			cv::Size labelSize = getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
			cv::rectangle(frame, cv::Rect(cv::Point(xLeftBottom, yLeftBottom - labelSize.height),
				cv::Size(labelSize.width, labelSize.height + baseLine)),
				cv::Scalar(255, 255, 255), cv::FILLED);
			putText(frame, label, cv::Point(xLeftBottom, yLeftBottom),
				cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));

			face = object;
		}
	}
	return face;
}

cv::Mat faceDetection::getTempMat()
{
	return tempMat;
}
