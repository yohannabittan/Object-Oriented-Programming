
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include "Course.h"
#include "Student.h"
using namespace BrooklynPoly;

Course::Course(string name) {

	Course::name = name;
}

Course::~Course() {

	for (int i = 0; i < students.size(); i++) {
		dropStudent(students[i]);
	}
	students.clear();
	name.clear();
}

void Course::addStudent(Student* student) {
	for (int i = 0; i < students.size(); i++)
		if (students[i] == student)
			return;
	students.push_back(student);
}

string Course::getName() {
	return name;
}

vector<Student*> Course::getStudents() {
	return students;
}

void Course::dropStudent(Student* student) {
	for (int i = 0; i < students.size(); i++)
		if (students[i] == student) {

			students[i]->dropCourse(this);

			students[i] = students[students.size() - 1];

			students.pop_back();
		}
}