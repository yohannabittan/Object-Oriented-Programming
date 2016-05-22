#pragma once
/*
Yohann Abittan
*/

#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>

namespace WarriorCraft {

	class Noble;

	class Warrior {
	public:
		Warrior(const std::string &warriorName, double warriorStrength);

		void display() const;

		//getters

		std::string getName() const;

		double getStrength() const;

		Noble* getPointer() const;

		//setters

		void setStrength(double newStrength);

		void setPointer(Noble& newNoble);

		void runAway();

		void getFired();

	private:
		std::string warriorName;

		double warriorStrength;

		Noble* noble;
	};
}

#endif