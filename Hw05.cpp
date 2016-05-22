/*
Filename: Hw05.cpp
Programmer: Yohann Abittan
netID: yaa243

The aim of this program is to simulate medieval times through a game of warriors
*/

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Warrior {
private:
	string name;
	int strength;
public:
	Warrior(string warriorName = "", int warriorStrength = 0) : name(warriorName), strength(warriorStrength) {}
	void display() const {//made constant because the display method must not change any data
		cout << this.getName() << ": " << this.getStrength();
	}
	//setter 
	void setName(const string& newName) { name = newName; }
	void setStrength(int newStrength) { strength=newStrength); }

	//getter
	string getName() const { return name; }
	int getStrength() const { return strength; }
};
class Noble {
private:
	string name;
	vector<Warrior>* army;
public:
	Noble(string nobleName = "", vector<warrior>* nobleArmy = nullptr) : name(nobleName), army(nobleArmy) {}
};

void Noble::display() const {
	if (army != nullptr) {
		cout << this.name() << " has an army of  " << this.army.size();
		for (size_t i = 0, i < army.size(); i++) {
			this.army[i]->display();
		}
	}
	else {
		cout << this.name() << " has no army";
	}
}

void Noble::hire(Warrior& newWarrior) {
	Warrior* warriorPtr;
	warriorPtr = newWarrior;
	this.army.push_back(warriorPtr);
}

void Noble::fire(Warrior& badWarrior) {
	this.army.pop_back(badWarrior);
}

void Noble::battle(Noble otherNoble) {
	int totalStrength1;
	int totalStrength2;
	int strengthFactor;
	int individualStrength;

	for (size_t i = 0, i < this.army.size(); i++) {
		totalStrength1 += (this.army[i]->getStrength());
	}
	for (size_t i = 0, i < otherNoble.army.size(); i++) {
		totalStrength2 += (otherNoble.army[i]->getStrength());
	}
	if (totalStrength1 == 0 && totalStrength2 == 0) {//if both armies have no strength
		cout << this.name() << " battles " << otherNoble.name();
		cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
	}

	if (totalStrength1 == totalStrength2) {//if both armies have the same total strength they annihilate
		cout << "mutual annihilation " << this.name() << " and " << otherNoble.name() << " die at each other's hands";
		for (size_t i = 0, i < this.army.size(); i++) {
			this.army[i]->setStrength(0);
		}
		for (size_t i = 0, i < otherNoble.army.size(); i++) {
			this.army[i]->setStrength(0);
		}	
	}

	else if (totalStrength1 > totalStrength2) {//if the first army is stronger
		cout << this.name() << " defeats " << otherNoble.name();
		(totalStrength2 / totalStrength1) = strengthFactor;
		for (size_t i = 0, i < this.army.size(); i++) {
			this.army[i]->getStrength() = individualStrength;
			this.army[i]->setStrength(individualStrength - (individualStrength*strengthFactor));
		}
		for (size_t i = 0, i < otherNoble.army.size(); i++)
			otherNoble.army[i]->setStrength(0);
	}
	else if (totalStrength2 > totalStrength1) {//if the second army is stronger
		cout << otherNoble.name() << " defeats " << this.name();
		(totalStrength1 / totalStrength2) = strengthFactor;
		for (size_t i = 0, i < this.army.size(); i++) {
			otherNoble.army[i]->getStrength() = individualStrength;
			otherNoble.army[i]->setStrength(individualStrength - (individualStrength*strengthFactor));
		}
		for (size_t i = 0, i < otherNoble.army.size(); i++)
			otherNoble.army[i]->setStrength(0);

	}
}

int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}