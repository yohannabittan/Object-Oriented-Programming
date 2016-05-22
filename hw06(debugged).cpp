#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Noble {
private:
	const string nobleName;
	bool isFighter;
public:
	Noble(const string name) : nobleName(name) {}

	string getNobleName() const { return nobleName; }

	virtual double getArmyStr();

	virtual void display() const {}

	virtual void setArmyStr(double strengthFactor) {}

	void battle(Noble& opponent);
};

class Warrior {
private:
	string name;
	string lordName;
	double strength;
public:
	Warrior(const string warriorName = "", double warriorStrength = 0) : name(warriorName), strength(warriorStrength) {}
	void display() const { cout << name << ": " << strength; }//made constant because the display method must not change any data
															  //setter 
	void setStrength(double newStrength) { strength = newStrength; }
	void setLordName(string newLordName) { lordName = newLordName; }
	//getter
	string getName() const { return name; }
	double getStrength() const { return strength; }
};

class NobleFighter: public Noble{
private:
	bool isFighter=true;
	double strength; 
public:
	NobleFighter(const string name, double strength) : Noble(name), strength(strength) {}
	double getArmyStr() const { return strength; }
	virtual void display() const { cout << "I am the great " << getNobleName() << "and my strength is " << strength << "!" << endl; }
	virtual void setArmyStr(double strengthFactor);
};

class NobleLord: public Noble{
private:
	bool isFighter=false;
	vector<Warrior*> army;
public:
	NobleLord(const string name) : Noble(name) {}
	virtual void setArmyStr(double ratio);
	double getArmyStr()const;
	void hire(Warrior& aWarrior) { 
		aWarrior.setLordName = getNobleName();
		Warrior* wPtr = &aWarrior;
		army.push_back(wPtr); }
	void fire(Warrior* aWarrior);
	virtual void display() const {
		for (Warrior* warrior : army) {

		}
	}
};


class Magician: public Warrior{
private:

public:
	Magician(const string magicianName = "", double magicianStrength = 0) : Warrior(magicianName, magicianStrength) {}
	virtual void display() const {
		cout << "POOF" << endl;
	}
};
class Swordsman: public Warrior{
private:
	string lordName;
public:
	Swordsman(const string swordsmanName = "", double swordsmanStrength = 0) : Warrior(swordsmanName, swordsmanStrength) {}
	virtual void display() const {
		cout << "CLANG! " << getName() << "says: Take that in the name of my lord" << lordName << endl;
	}
};
class Archer: public Warrior{
private:
	string lordName;
public:
	Archer(const string archerName = "", double archerStrength = 0) : Warrior(archerName, archerStrength) {}
	virtual void display() const {
		cout << "TWANG! " << getName() << "says: Take that in the name of my lord" << lordName << endl;
	}

};
double NobleLord::getArmyStr()const {//gets the total strength of a noble's army
	double totalStrength1 = 0;
	for (size_t i = 0; i < army.size(); i++) {
		totalStrength1 += (army[i]->getStrength());
	}
	return totalStrength1;
}
void NobleLord::setArmyStr(double strengthFactor) {
	if (strengthFactor == 0) {	//This kills the warriors by setting their strengths=0
		for (size_t i = 0; i < army.size(); i++) {
			army[i]->setStrength(strengthFactor);
		}
	}
	else {	//every warrior loses a fraction of his strength proportional to the fraction of the total army that the opposing army made up
		for (size_t i = 0; i < army.size(); i++) {
			army[i]->setStrength(army[i]->getStrength() - army[i]->getStrength() * strengthFactor);
		}
	}
}
void NobleFighter::setArmyStr(double strengthFactor) {
	strength = strength*strengthFactor;
}
void NobleLord::fire(Warrior* badWarrior) {
	for (size_t i = 0; i < army.size(); i++) {
		if (army[i] == badWarrior) {
			army[i] = army[army.size() - 1];
			army.pop_back();//this warrior is forced to leave his army
		}
	}
}
void Noble::battle(Noble& opponent) {
	Noble* otherNoble = &opponent;
	if(this->isFighter=false) {
		for (Warrior* warrior : this->army) {
			warrior->display()
		}
	}
		if (this->getArmyStr() == 0 && otherNoble->getArmyStr() == 0) {//if both armies have no strength
		cout << nobleName << " battles " << otherNoble->getNobleName();
		cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
	}
	else if (this->getArmyStr() == 0) {//if one party is dead
		cout << "He's dead " << otherNoble->getNobleName() << endl;
	}
	else if (otherNoble->getArmyStr() == 0) {//if the other party is dead
		cout << "He's dead " << this->getNobleName() << endl;
	}
	else if (this->getArmyStr() == otherNoble->getArmyStr()) {//if both armies have the same total strength they annihilate
		cout << "mutual annihilation " << nobleName << " and " << otherNoble->getNobleName() << " die at each other's hands" << endl;
		this->setArmyStr(0);
		otherNoble->setArmyStr(0);
	}

	else if (this->getArmyStr() > otherNoble->getArmyStr()) {//if the first army is stronger
		cout << nobleName << " defeats " << otherNoble->getNobleName() << endl;
		this->setArmyStr(otherNoble->getArmyStr() / this->getArmyStr());
		otherNoble->setArmyStr(0);
	}
	else if (otherNoble->getArmyStr() > this->getArmyStr()) {//if the second army is stronger
		cout << otherNoble->getNobleName() << " defeats " << nobleName << endl;
		otherNoble->setArmyStr(this->getArmyStr() / otherNoble->getArmyStr());
		this->setArmyStr(0);
	}
}
int main() {
	NobleLord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hire(samantha);
	NobleLord joe("Joe");
	NobleFighter randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	NobleLord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hire(hardy);
	janet.hire(stout);
	NobleFighter barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hire(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Magician merlin("Merlin", 150);
	janet.hire(pethora);
	janet.hire(thora);
	sam.hire(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
}