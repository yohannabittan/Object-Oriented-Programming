/*
FileName: rec05
Programmer: Yohann Abittan

The aim of this program is to simulate the grading system used at poly
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Student {
private:
	const string name;
	vector<int> grades;
public:
	Student(const string studentName) : name(studentName), grades(13,-1) {}
	void getNumberOfGrades() {
		int gradesSize;
		for (int grade : grades) {
			gradesSize = 0;
			gradesSize++;
		}
	}
	void displayStudent()const {
		cout << "Student: " << name << "; Grades: ";
		for (int grade : grades) {
			cout << grade;
		}
	}
	string getName() const { return name; }
	void setGrade(const int& week, const int& grade) { grades[week] = grade; }
};
class TimeSlot {
private:
	string day;
	const unsigned hour;
public:
	TimeSlot(string dayOfTheWeek, const unsigned hourOfTheDay) : day(dayOfTheWeek), hour(hourOfTheDay) {}
		void displayTimeSlot()const;
};
class Section {
private:
	const TimeSlot slot;
	const string& name;
	vector<Student*> students;
public:
	Section(const string& dayOfTheWeek, const string& sectionName,const unsigned hourOfTheDay) : name(sectionName), slot(dayOfTheWeek,hourOfTheDay) {}
	void reset() { 
		for (size_t i = 0; i < students.size(); i++) {
			delete students[i];
		}
		students.clear();
	}
	void addStudent(const string& studentName){
		Student* studentPtr = new Student(studentName);
		students.push_back(studentPtr);
	}
	void display()const {
		cout << "Section:" << name << "; ";
		slot.displayTimeSlot();
		for (size_t i = 0; i < students.size(); i++) {
			students[i]->displayStudent();
		}
	}
	void addGrade(const string& studentName, const int& week, const int& grade) {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == studentName) {
				students[i]->setGrade(week, grade);
			}
		}
	}
};
class LabWorker {
private:
	const string name;
	const Section* labSection;
public:
	LabWorker(const string& workerName) : name(workerName) {}
	
	void addGrade(const string& studentName, const int& grade, const int& week) {
		labSection->addGrade(studentName, grade, week);
	}
	void addSection(Section& newSection) {
		labSection = &newSection;
	}
	void displayGrades()const {
		labSection->display();
	}
};

void TimeSlot::displayTimeSlot()const {
	cout << " " << day << " " << hour << endl;
}

int main() {

	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");

	// sections and setup and testing
	Section secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


							   // setup is complete, now a real world scenario can be written in the code
							   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

							   // week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();

} // main