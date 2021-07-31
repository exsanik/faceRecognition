#include "Libs.h"

std::ostream& operator <<(std::ostream& out, Person& obj)
{
	out << obj.currId << std::endl << obj.name << std::endl << obj.famName << std::endl;
	for (auto &path : obj.path)
		out << path << std::endl;
	return out;
}

std::istream& operator >>(std::istream& in, Person& obj)
{
	std::string tmp;
	getline(in, tmp);
	obj.currId = atoi(tmp.c_str());
	getline(in, obj.name);
	getline(in, obj.famName);
	while (!in.eof())
	{
		getline(in, tmp);
		if (tmp == "" || tmp.rfind(".jpg") == std::string::npos)
			break;
		obj.path.push_back(tmp);
	}
	return in;
}

Person::Person() :currId(id) { id++; }
Person::Person(const Person & obj)
{
	id++;
	currId = obj.currId;
	name = obj.name;
	famName = obj.famName;
	path = obj.path;
}
Person::~Person() { --id; }
int Person::id = 0;

void Person::saveToFile()
{
	std::string pathname = "people/" + std::to_string(currId) + ".txt";
	
	data.open(pathname, std::ios_base::out || std::ios_base::binary);
	data << (*this);
	data.close();
}

void Person::readFromFile()
{
	std::string pathname = "/people/" + std::to_string(currId) + ".txt";
	data.open(pathname, std::ios_base::in || std::ios_base::binary);
	data >> (*this);
	data.close();
}

void Person::readFromFile(std::string pathname)
{
	data.open(pathname, std::ios_base::in | std::ios_base::binary);
	data >> (*this);
	data.close();
}

int Person::getCurrId() const { return currId; }
int Person::getId() { return id; }

void Person::addImage(std::string p) { path.push_back(p); }
int Person::getPicAmount() { return path.size(); }
void Person::setName(std::string n) { name = n; }
void Person::setfamName(std::string fN) { famName = fN; }
std::vector<std::string> Person::getImages() { return path; }
std::string Person::getFullName() { return name + ' ' + famName; }
