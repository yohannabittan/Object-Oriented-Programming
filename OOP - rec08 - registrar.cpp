#include <string>						
#include <iostream>
#include <vector>
using namespace std;
#include "Course.h"
#include "Student.h"
#include "Registrar.h"
using namespace BrooklynPoly;



Registrar::Registrar() {} //constructor
Registrar::~Registrar() {}//destructor

Student* Registrar::findStudent(string name) {
	for (Student* student : allStudents)
		if (student->getName() == name)
			return x;
	return nullptr;
}

Course* Registrar::findCourse(string name) {
	for (Course* course : allCourses)
		if (course->getName() == name) {
			return course;
		}
	return nullptr;
}


void Registrar::addCourse(string name) {
	for (Course* course : allCourses)
		if (course->getName() == name)
			return;
	allCourses.emplace_back(new Course(name));
}

void Registrar::printReport() {
	cout << "report" << endl;
	for (Course* course : allCourses) {
		cout << "Course: " << course->getName() << endl << "Students: " << endl;
		vector<Student*> students = course->getStudents();
		for (Student* student : students) {
			cout << student->getName() << endl;
		}
	}
	cout << "end of report" << endl << endl;
}

void Registrar::addStudent(string name) {
	for (Student* students : allStudents)
		if (students->getName() == name)
			return;
	allStudents.emplace_back(new Student(name));
}

void Registrar::enrollStudentInCourse(string name, string course) {
	Course* theCourse = findCourse(course);
	Student* theStudent = findStudent(name);

	if (!theStudent&&tCourse) {
		Registrar::addStudent(name);
		theStudent = allStudents.back();
	}
	if (theCourse&&!theStudent->hasClass(theCourse)) { // checks the existence of the course and wether the student is enrolled
		theStudent->addCourse(theCourse);
	}
}

void Registrar::cancelCourse(string name) {
	for (int i = 0; i<allCourses.size(); i++)
		if (allCourses[i]->getName() == name) {
			delete allCourses[i];
			allCourses[i] = allCourses.back();
			allCourses.pop_back();
		}

}