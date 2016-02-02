#include <iostream>
#include "Course.h"
using namespace std;
int Course::currentId = 0;

Course::Course() {
	id = ++currentId;
	name = "";
}
Course::Course(const string& cName, int ID) : name(cName), id(ID){}


Course::Course(const string& cName) : name(cName), id(++currentId){}

Course::Course(const Course& course) : 
	name(course.name), id(course.id) {	
}

ostream &operator<< (ostream &os, const Course& course) {
	os << "Course: " << course.GetId() << " : " << course.GetName();
	return os;
}

void read(istream &inputStream, Course &course) {
	inputStream >> course.name;
}

void Course::PrintInfo() const {
	cout << "Course:: "  << id << " : " << name <<  endl;
}

void ProjectCourse::PrintInfo() const {
	
	cout << "ProjectCourse:: " << id << " : " << name << " : " << tag << endl;
}
