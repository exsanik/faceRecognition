//UPDATE: 25.06.19
#pragma once
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
#include <algorithm>
namespace fs = std::experimental::filesystem;

//OpenCV
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


class faceDetection
{
private:
	std::fstream log;
	cv::VideoCapture cap;
	size_t inWidth;
	size_t inHeight;
	double inScaleFactor;
	cv::Scalar meanVal;
	bool detect = false;
	bool save = false, saved = false;
	cv::Mat tempMat;
	float coeffSimil;
	int deviceID;
	std::string source;
	// Initialize network
	cv::dnn::Net net = cv::dnn::readNetFromCaffe("net/deploy.prototxt", "net/res10_300x300_ssd_iter_140000.caffemodel");
public:
	faceDetection();
	~faceDetection();
	void detectFace(System::Windows::Forms::PictureBox^ pictureBox1);
	void stopDetection();
	void saveFace();
	void setCoeffSimil(float coeff);
	void setWidth(size_t width);
	void setHeight(size_t height);
	void setCamId(int cid);
	void setSource(std::string path);
	std::string getSource();
	int getCamId();
	size_t getWidth();
	size_t getHeight();
	float getCoeffSimil();
	int getSaveState();
	bool getState();
	cv::Rect detectPerson(cv::Mat &frame);
	cv::Mat getTempMat();
};

class Person
{
private:
	static int id;
	int currId;
	std::string name;
	std::string famName;
	std::vector<std::string> path;
	std::fstream data;
public:
	Person();
	Person(const Person &obj);
	~Person();
	void saveToFile();
	void readFromFile();
	void readFromFile(std::string pathname);
	int getCurrId() const;
	static int getId();
	void addImage(std::string p);
	int getPicAmount();
	void setName(std::string n);
	void Person::setfamName(std::string fN);
	std::vector<std::string> getImages();
	std::string getFullName();
	friend std::ostream& operator <<(std::ostream& out, Person& obj);
	friend std::istream& operator >>(std::istream& in, Person& obj);
};

std::ostream& operator <<(std::ostream& out, Person& obj);
std::istream& operator >>(std::istream& in, Person& obj);

