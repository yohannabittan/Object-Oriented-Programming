#include <string>				
#include <iostream>
#include <vector>
using namespace std;
#include "Course.h"
#include "Student.h"
using namespace BrooklynPoly;

Student::Student(string name) : name(name) {}//constructor
Student::~Student() {}//destructor
string Student::getName() {
		return name;
	}
bool Student::hasClass(Course* cptr) {
	for (Course* randomCourse : courses) {
		if (randomCourse == cptr) {
			return true;
		}
	}
	return false;
}

Course* Student::findCourse(string name) {
	for (Course* course : courses)
		if (course->getName() == name) {
			return course;
		}
	return nullptr;
	}

	void Student::addCourse(Course* course) {
		for (int i = 0; i < courses.size(); i++)
			if (courses[i] == course) {return;}
		courses.push_back(course);
		course->addStudent(this);
	}
	void Student::dropCourse(Course* course) {
		for (int i = 0; i < courses.size(); i++)
			if (courses[i] == course) {
				courses[i] = courses.back();
				courses.pop_back();
			}
	}
