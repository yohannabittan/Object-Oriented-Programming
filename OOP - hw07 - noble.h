#pragma once

#ifndef NOBLE_H
#define NOBLE_H

#include <string>
#include <vector>
#include "Warrior.h"

namespace WarriorCraft {

	class Noble {
	public:
		Noble(const std::string& name);

		void display() const;

		void hire(Warrior& warrior);

		void fire(Warrior& badWarrior);

		//getters

		std::string getName() const;

		void battle(Noble& noble);

		double getArmyStr() const;

		//setters

		void setArmyStr(double strengthFactor);

	private:
		std::string name;

		std::vector <Warrior*> army;
	};

	std::ostream& operator<<(std::ostream& os, const Noble& noble);
}

#endif