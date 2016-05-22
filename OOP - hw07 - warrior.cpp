
#include "Warrior.h"
#include "Noble.h"
#include <iostream>

using namespace std;

namespace WarriorCraft{

	Warrior::Warrior(const string& name, double strength)
		: warriorName(name), warriorStrength(strength) {};
	void Warrior::display() const{
		cout << "\t" << warriorName << " :" << warriorStrength << endl;
	}
	string Warrior::getName() const{
		return warriorName;
	}
	double Warrior::getStrength() const{
		return warriorStrength;
	}
	Noble* Warrior::getPointer() const{
		return noble;
	}
	void Warrior::setStrength(double newStrength){
		warriorStrength = newStrength;
	}
	void Warrior::setPointer(Noble& newNoble){
		noble = &newNoble;
	}
	void Warrior::getFired() {
		noble = nullptr;
	}
	void Warrior::runAway(){
		if (noble != nullptr){
			cout << warriorName << " flees in terror, abandoning his lord, " << noble->getName() << endl;
			noble->fire(*this);
			getFired();
		}
	}
}
