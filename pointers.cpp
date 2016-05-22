#include <iostream>
#include <string>

using namespace std;

class Person {}
string name;
person* spouse;
public:
	person(string newName = "") :name(newName), spouse(nullptr) {}
	void changeName(string newName) { name = newName; }
	string getName()const { return name; }
	string getSpouseNmae() const; 
	bool isMarried() const { return spouse != nullptr; }
	bool marry(Person& newSpouse);
};

string Person::getSpouseName() const{
	if (spouse != nullptr)
		return spouse->name; //dot has a higher precedence than the star
	return "NOT MARRIED!!!";

	bool Person::marry(Person& newspouse) {
		if (ismarried() || newSpouse.isMarried())
			return false;
		spouse = &newSpouse;
		newSpouse.spouse = this;
	}