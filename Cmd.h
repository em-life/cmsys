#ifndef CMD_H
#define CMD_H

enum CourseCmd {
	Cmd_PrintHelp = 0,
	Cmd_PrintCourse = 1,
	Cmd_PrintCourseNum = 2,
	Cmd_PrintLongName = 3,
	Cmd_RemoveCourseById = 4,
	Cmd_RemoveCourseByName = 5,
	Cmd_RemoveLastCourse = 6,
	Cmd_AddCourse = 7,
	Cmd_SavaFile = 8,
	Cmd_Exit = 9,
};

#endif
