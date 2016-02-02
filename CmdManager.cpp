#include <iostream>
#include <map>
#include <utility>
#include <string>
#include "CourseManager.h"
#include "CmdManager.h"
using namespace std;

void CmdManager::Init() {
	fstream file;
	file.open("Course.dat", ios::in);
	if (!file) {
		manager.AddCourse("Linux");
		manager.AddCourse("NodeJS");
		manager.AddCourse("C++");
		manager.AddCourse("Python");
		manager.AddCourse("Spark");
		manager.AddCourse("Hadoop");
		manager.AddCourse("Ruby");
		manager.AddCourse("Java");
		manager.ReadFile();
		file.close();
	} else {
		file.close();
		manager.ReadFile();
	}
	cmdMap.insert(pair<CourseCmd, string>(Cmd_PrintHelp, "Help Info"));
	cmdMap.insert(pair<CourseCmd, string>(Cmd_PrintCourse, "Course List"));
	cmdMap.insert(pair<CourseCmd, string>(Cmd_PrintCourseNum, "Course Number"));
	cmdMap.insert(pair<CourseCmd, string>(Cmd_PrintLongName, "Longest Course Name"));
	cmdMap.insert(pair<CourseCmd, string>(Cmd_RemoveLastCourse, "Remove Last Course"));
	cmdMap.insert(pair<CourseCmd, string>(Cmd_RemoveCourseByName, "Remove Course By Name"));
	cmdMap.insert(pair<CourseCmd, string>(Cmd_RemoveCourseById, "Remove By Course Id"));
	cmdMap.insert(pair<CourseCmd, string >(Cmd_AddCourse, "Add Course"));
	cmdMap.insert(pair<CourseCmd, string>(Cmd_SavaFile, "Save File"));
	cmdMap.insert(pair<CourseCmd, string>(Cmd_Exit, "Exit"));
}

void CmdManager::PrintAllHelp() const {
	cout << "Cmd List: " << endl;
	for (auto iter = cmdMap.begin(); iter != cmdMap.end(); ++iter)
		cout << iter->first << ":" << iter->second << endl;
}

void CmdManager::PrintCmdHelp(const CourseCmd cmd) const {
	auto iter = cmdMap.find(cmd);
	if (iter != cmdMap.end())
		cout << iter->first << ":" << iter->second << endl;
	else
		cout << "NOT FOUND" << endl;
}

bool CmdManager::HandleCmd(const CourseCmd cmd) {
		
	auto iter = cmdMap.find(cmd);
	if (iter == cmdMap.end()) {
		cout << "NOT FOUND" <<endl;
		return true;
	}

	switch (cmd) {
		case Cmd_PrintHelp:
			PrintAllHelp();
			break;
		case Cmd_PrintCourse:
			manager.PrintAllCourse();
			break;
		case Cmd_PrintCourseNum:
			cout << manager.GetCourseNum() << endl;
			break;
		case Cmd_PrintLongName:
			manager.PrintLongNameCourse();
			break;
		case Cmd_RemoveLastCourse:
			manager.RemoveLast();
			break;
		case Cmd_RemoveCourseByName:
		{
			string name;
			cin >> name;
			cout << "input the name of the course to be removed" << endl;
			manager.RemoveByName(name);
			break;
		}
		case Cmd_RemoveCourseById:
		{
			int id;
			cin >> id;
			cout << "input the id of course to be removed" << endl;
			manager.RemoveById(id);
			break;
		}
		case Cmd_AddCourse:
		{
			cout << "input the name of the course to be added" << endl;
			string name;
			cin >> name;
			manager.AddCourse(name);
			break;
		}
		case Cmd_SavaFile:
			manager.StoreFile();
			break;
		case Cmd_Exit:
			return false;
			break;
		default:
			break;

	}
	return true;
}


