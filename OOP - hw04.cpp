/*
Filename: Hw04.cpp
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
	double strength;
public:
	Warrior(string warriorName, double warriorStrength) : name(warriorName), strength(warriorStrength) {}
	void display() const;
	//setter 
	void setName(string& newName) { name = newName; }
	void setStrength(double newStrength) { strength=newStrength; }

	//getter
	string getName() const { return name; }
	double getStrength() const { return strength; }
};
class Noble {
private:
	string name;
	vector<Warrior*> army;
public:
	Noble(string nobleName = "") : name(nobleName) {}
	void display() const;
	//getters
	string getName()const { return name; }
	double getArmyStr()const;
	//setters
	void setName(string& newName) { name = newName; }
	void setArmyStr(double newArmyStr);
	void hire(Warrior& warriorName);
	void fire(Warrior& badWarrior);
	void battle(Noble& otherNoble);
};

void Noble::display() const {
		cout << name << " has an army of  " << army.size() << endl;
		for (size_t i = 0; i < army.size(); i++) {
			army[i]->display();
		}
}

void Noble::hire(Warrior& warriorName) {
	army.push_back(&warriorName);
}

void Noble::fire(Warrior& badWarrior) {
	cout << badWarrior.getName() << ", you are fired!" << name << endl;
	for (size_t i = 0; i < army.size(); i++) {
		if (badWarrior.getName() == army[i]->getName()) {
			while (i+1 <army.size()) {	//while the warrior who has to be fired is not the last one in the vector, switch it with the next one
				army[i] = army[i + 1];
			}
			army.pop_back();//when the right warrior is last, pop him out
		}
	}
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
void Noble::battle(Noble& otherNoble) {
	double totalStrength1;
	double totalStrength2;
	double strengthFactor;
	double individualStrength;
	
	totalStrength1 = (getArmyStr());
	totalStrength2 = (otherNoble.getArmyStr());

	if (totalStrength1 == 0 && totalStrength2 == 0) {//if both armies have no strength
		cout << name << " battles " << otherNoble.getName()<<endl;
		cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
	}
	else if (totalStrength1 == 0) {
		cout << name << " battles " << otherNoble.getName()<<endl;
		cout << " He's dead " << otherNoble.getName()<<endl;
	}
	else if (totalStrength2 == 0) {
		cout << name << " battles " << otherNoble.getName()<<endl;
		cout << "he's dead " << name<< endl;
	}

	else if (totalStrength1 == totalStrength2) {//if both armies have the same total strength they annihilate
		cout << name << " battles" << otherNoble.getName() << endl;
		cout << "mutual annihilation " << name << " and " << otherNoble.getName() << " die at each other's hands"<<endl;
		setArmyStr(0);
		otherNoble.setArmyStr(0);
	}

	else if (totalStrength1 > totalStrength2) {//if the first army is stronger
		cout << name << " battles " << otherNoble.getName() << endl;
		cout << name << " defeats " << otherNoble.getName()<<endl;
		strengthFactor = (totalStrength2 / totalStrength1);
		for (size_t i = 0; i < army.size(); i++) {
			individualStrength = army[i]->getStrength();
			army[i]->setStrength(individualStrength - (individualStrength*strengthFactor));
		}
		for (size_t i = 0; i < otherNoble.army.size(); i++)
			otherNoble.army[i]->setStrength(0);
	}
	else if (totalStrength2 > totalStrength1) {//if the second army is stronger
		cout << otherNoble.getName() << " defeats " << name<<endl;
		strengthFactor = (totalStrength1 / totalStrength2);
		for (size_t i = 0; i < army.size(); i++) {
			individualStrength = otherNoble.army[i]->getStrength();
			otherNoble.army[i]->setStrength(individualStrength - (individualStrength*strengthFactor));
		}
		for (size_t i = 0; i < otherNoble.army.size(); i++)
			otherNoble.army[i]->setStrength(0);
	}
}
double Noble::getArmyStr() const {
	double armyStr=0;
	for (size_t i = 0; i < army.size(); i++) {
		armyStr += (army[i]->getStrength());
	}
	return armyStr;
}
void Warrior::display() const{
	cout <<"\t"<< name << " :" << strength<<endl;
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