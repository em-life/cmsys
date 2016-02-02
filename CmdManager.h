#ifndef CMDMANAGER_H
#define CMDMANAGER_H
#include <map>
#include <fstream>
#include "Cmd.h"
#include "CourseManager.h"
using namespace std;

class CmdManager {
public:
	CmdManager() = default;

	void Init();

	void PrintAllHelp() const;

	void PrintCmdHelp(const CourseCmd cmd) const;

	bool HandleCmd(const CourseCmd cmd);

	inline CourseManager& GetCourseManager() {
		return manager;
	}


private:
	CourseManager manager;
	map<CourseCmd, string> cmdMap;
};


#endif
