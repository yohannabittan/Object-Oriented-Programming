
#include "Noble.h"
#include <iostream>

using namespace std;

namespace WarriorCraft
{
    Noble::Noble(const std::string &nm) : name(nm) {}
    std::string Noble::getName() const { return name; }
    void Noble::battle(Noble& otherNoble) {
		double totalStrength1;
		double totalStrength2;
		double strengthFactor;
		double individualStrength;

		totalStrength1 = (getArmyStr());
		totalStrength2 = (otherNoble.getArmyStr());

		if (totalStrength1 == 0 && totalStrength2 == 0) {//if both armies have no strength
			cout << name << " battles " << otherNoble.getName() << endl;
			cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
		}
		else if (totalStrength1 == 0) {
			cout << name << " battles " << otherNoble.getName() << endl;
			cout << " He's dead " << otherNoble.getName() << endl;
		}
		else if (totalStrength2 == 0) {
			cout << name << " battles " << otherNoble.getName() << endl;
			cout << "he's dead " << name << endl;
		}

		else if (totalStrength1 == totalStrength2) {//if both armies have the same total strength they annihilate
			cout << name << " battles" << otherNoble.getName() << endl;
			cout << "mutual annihilation " << name << " and " << otherNoble.getName() << " die at each other's hands" << endl;
			setArmyStr(0);
			otherNoble.setArmyStr(0);
		}

		else if (totalStrength1 > totalStrength2) {//if the first army is stronger
			cout << name << " battles " << otherNoble.getName() << endl;
			cout << name << " defeats " << otherNoble.getName() << endl;
			strengthFactor = (totalStrength2 / totalStrength1);
			for (size_t i = 0; i < army.size(); i++) {
				individualStrength = army[i]->getStrength();
				army[i]->setStrength(individualStrength - (individualStrength*strengthFactor));
			}
			for (size_t i = 0; i < otherNoble.army.size(); i++)
				otherNoble.army[i]->setStrength(0);
		}
		else if (totalStrength2 > totalStrength1) {//if the second army is stronger
			cout << otherNoble.getName() << " defeats " << name << endl;
			strengthFactor = (totalStrength1 / totalStrength2);
			for (size_t i = 0; i < army.size(); i++) {
				individualStrength = otherNoble.army[i]->getStrength();
				otherNoble.army[i]->setStrength(individualStrength - (individualStrength*strengthFactor));
			}
			for (size_t i = 0; i < otherNoble.army.size(); i++)
				otherNoble.army[i]->setStrength(0);
		}
	}
    void Noble::display() const
    {
        if (army.size() == 0)
            cout << name << "'s army is empty :-(\n";
        else
        {
            cout << name << " has an army of " << army.size() << endl;
            for (size_t i = 0; i < army.size(); i++)
            {
                cout << "\t";
                army[i]->display();
            }
        }
    }
    void Noble::hire(Warrior &warriorName)
    {
		army.push_back(&warriorName);
		warriorName.setPointer(*this);
    }
	void Noble::fire(Warrior& badWarrior) {
		cout << badWarrior.getName() << ", you are fired!" << name << endl;
		for (size_t i = 0; i < army.size(); i++) {
			if (badWarrior.getName() == army[i]->getName()) {
				while (i + 1 <army.size()) {	//while the warrior who has to be fired is not the last one in the vector, switch it with the next one
					army[i] = army[i + 1];
				}
				army.pop_back();//when the right warrior is last, pop him out
			}
		}
		badWarrior.getFired();
	}
	double Noble::getArmyStr()const {
		double armyStr = 0;
		for (size_t i = 0; i < army.size(); i++) {
			armyStr += (army[i]->getStrength());
		}
		return armyStr;
	}
	void Noble::setArmyStr(double strengthFactor) {
		if (strengthFactor == 0) {
			for (size_t i = 0; i < army.size(); i++) {
				army[i]->setStrength(strengthFactor);
			}
		}
		else {
			for (size_t i = 0; i < army.size(); i++) {
				army[i]->setStrength(army[i]->getStrength() - army[i]->getStrength()*strengthFactor);
			}
		}

	}
    ostream& operator<<(ostream &os, const Noble &noble)
    {
        noble.display();
        return os;
    }
}
