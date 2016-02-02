#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H
#include "Course.h"
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <string>

class CourseManager {
public:
	CourseManager() = default;
	CourseManager(const std::list<std::shared_ptr<Course>>& courseVect);
	inline int GetCourseNum() {
		return courseList.size();
	}

	void AddCourse(const Course &course);
	void AddCourse(const string& courseName);
	list<std::shared_ptr<Course>>::iterator FindByName(const std::string &name);
	list<std::shared_ptr<Course>>::iterator FindById(int id);
	void RemoveLast();
	void RemoveByName(const std::string& name);
	void RemoveById(int id);
	void PrintAllCourse();
	void PrintCourse(const std::string &name);
	void PrintCourse(int id);
	void PrintLongNameCourse();
	void StoreFile();
	void ReadFile();

private:
	std::list< std::shared_ptr<Course> > courseList;
};
#endif
