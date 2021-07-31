#include "Libs.h"

void HideConsole() { ::ShowWindow(::GetConsoleWindow(), SW_HIDE); }

faceRecognition::faceRecognition()
{
	res.open("res.txt");
	deserialize("net/dlib_face_recognition_resnet_model_v1.dat") >> net;
}

faceRecognition::~faceRecognition()
{
	res.close();
}

void faceRecognition::recognizeFace()
{
	std::vector<matrix<rgb_pixel>> faces;
	for (auto &i : img)
		faces.push_back(i);

	std::vector<matrix<float, 0, 1>> face_descriptors = net(faces);
	for (size_t i = 0; i < face_descriptors.size(); ++i)
		for (size_t j = i+1; j < face_descriptors.size(); ++j)
		{
			double len = length(face_descriptors[i] - face_descriptors[j]);
			res << len << ' ' << i << ' ' << ' ' << j << endl;
		}
}


void faceRecognition::setImg(char ** imgPath, int amount)
{
	std::vector<cv::Mat> mat;
	std::vector<cv_image<bgr_pixel>> image;
	img.resize(amount - 1);

	for (int i = 1; i < amount; i++)
	{
		mat.push_back(cv::imread(imgPath[i]));
		cv::resize(mat[i-1], mat[i-1], cv::Size(150, 150));
		image.push_back(cv_image<bgr_pixel>(mat[i - 1]));
		assign_image(img[i-1], image[i-1]);
	}
}
