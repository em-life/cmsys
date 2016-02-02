#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
class Course {
public:
	friend std::ostream& operator <<(std::ostream& out, const Course& course);
	friend void read(std::istream &inputStream, Course &course);
	Course();
	Course(const std::string& cName);
	Course(const std::string& cName, int ID);
	Course(const Course& course);
	~Course() {
	}
	virtual void PrintInfo() const;
	inline std::string GetName() const {
		return name;
	}
	inline void SetName(const std:: string& newName) {
		name = newName;
	}
	inline const int GetId() const {
		return id;
	}
protected:
	int id;
	std::string name;
	static int currentId;
private:
	

};

class ProjectCourse : public Course {
public:
	inline void SetTag(const std::string& newTag) {
		tag = newTag;
	}
	inline std::string GetTag() const {			
		return tag;
	}
	virtual void PrintInfo() const override;	//打印子类的信息
private:
	std::string tag;
};

#endif
