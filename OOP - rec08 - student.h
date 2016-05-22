#include <string>
#include <iostream>


class Student {
private:
	std::string name;
public:
	Student(std::string name) : name(name) {}
	void displayStudent()const;
};