#pragma once


namespace BrooklynPoly {


	class Registrar {
	private:
		vector<Student*> allStudents;

		vector<Course*> allCourses;

		Course* findCourse(string name);

		Student* findStudent(string name);
	public:
		Registrar();

		~Registrar();

		void addCourse(string name);
		void printReport();
		void addStudent(string name);
		void enrollStudentInCourse(string name, string courseName);
		void cancelCourse(string);
	};
}