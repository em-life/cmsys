#include "CourseManager.h"
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
using namespace std;

CourseManager::CourseManager(const std::list< std::shared_ptr<Course> >& courseVect) :
	courseList(courseVect){}

void CourseManager::AddCourse(const Course &course) {
	shared_ptr<Course> ptr = make_shared<Course>(course);
	courseList.push_back(ptr);
}

void CourseManager::AddCourse(const string &name) {
	auto course = std::make_shared<Course>(name);
	courseList.push_back(course);
}

void CourseManager::RemoveLast() {
	try {
		if (!courseList.empty()) {
			courseList.pop_back();
		}
		else {
			throw runtime_error("Deleted error, there is no course!");
		}
	}
	catch (runtime_error err) {
		cout << err.what() << endl;
	}

}

void CourseManager::RemoveByName(const string &name) {
	auto iter = FindByName(name);
	if (iter == courseList.end())
		cout << "NOT FOUND" << endl;
	else
		courseList.erase(iter);

}

void CourseManager::RemoveById(int id) {
	auto iter = FindById(id);
	if (iter == courseList.end())
		cout <<	"NOT FOUND" << endl;
	else
		courseList.erase(iter);
}

void CourseManager::PrintAllCourse() {
	for(auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		cout << **iter << endl;
	}
}

void CourseManager::PrintCourse(const string &name) {
	for(auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		if ((*iter)->GetName() == name) {
			cout << **iter << endl;
			break;
		}
	}
}

void CourseManager::PrintCourse(int id) {
	for(auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		if ((*iter)->GetId() == id) {
			cout << **iter << endl;
			break;
		}
	}
}

void CourseManager::PrintLongNameCourse() {
	size_t len = 0;
	for(auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		if (len < (*iter)->GetName().size()) {
			len = (*iter)->GetName().size();
		}
	}
	for (auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		if (len == (*iter)->GetName().size()) {
			cout << **iter << endl;
		}
	}
}

list<std::shared_ptr<Course>>::iterator CourseManager::FindByName(const string& name) {
	for (auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		if (name == (*iter)->GetName())
			return iter;
	}
	return courseList.end();
}

list<std::shared_ptr<Course>>::iterator CourseManager::FindById(int id) {
	for (auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		if (id == (*iter)->GetId())
			return iter;
	}
	return courseList.end();
}

void CourseManager::StoreFile() {
	ofstream ofile("Course.dat");
	for (auto iter : courseList)
	{
		ofile << iter->GetName() << " " << iter->GetId() << "\n";
	}
	ofile.close();
}

void CourseManager::ReadFile() {
	ifstream ifile("Course.dat");
	string name;
	int id;
	while (ifile >> name >> id){
		std::shared_ptr<Course> ptr = std::make_shared<Course>(name, id);
		courseList.push_back(ptr);
		ifile.clear();
	}
	ifile.close();
}