#include "CmdManager.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	CmdManager commond;
	commond.Init();
	commond.PrintAllHelp();
	unsigned int cmd;
	cout << "New Command:";
	while (cin >> cmd) {
		if (cin.good()) {
			bool exitCode = commond.HandleCmd(CourseCmd(cmd));
			if (!exitCode) {
				return 0;
			}
		}
		cout << "-----------------" << endl;
		cout << "New Command:";
		cin.clear();
		cin.ignore();
	}
	return 0;
}
