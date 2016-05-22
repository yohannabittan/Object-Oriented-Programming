/*
Filename: Hw05.cpp
Programmer: Yohann Abittan
netID: yaa243

The aim of this program is to simulate medieval times through a game of warriors.
Now with nobles who direct armies! 
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
	Warrior(const string warriorName = "", double warriorStrength = 0) : name(warriorName), strength(warriorStrength) {}
	void display() const { cout << name << ": " << strength; }//made constant because the display method must not change any data
	//setter 
	void setStrength(double newStrength) { strength = newStrength; }
	//getter
	string getName() const { return name; }
	double getStrength() const { return strength; }
};
class Noble {
private:
	const string name;
	vector<Warrior*> army;
public:
	Noble(const string nobleName = "") : name(nobleName) {}
	void display()const;
	string getName() { return name; }
	void hire(Warrior* aWarrior) { army.push_back(aWarrior); }
	void fire(Warrior* badWarrior);
	void battle(Noble* otherNoble);
	double getArmyStrength();
	void setArmyStrength(double strengthFactor);
};

void newNoble(ifstream& ifs, vector<Noble*>& nobles) {
	string name;
	ifs >> name;
	nobles.push_back(new Noble(name));//creates a noble on the heap
}
void newWarrior(ifstream& ifs, vector<Warrior*>& unemployed, vector<Warrior*>& warriors) {
	string name;
	double strength;
	ifs >> name >> strength;
	Warrior* warriorPtr = new Warrior(name, strength);//creates a warrior on the heap
	unemployed.push_back(warriorPtr);//puts the warrior into the unemployed vector
	warriors.push_back(warriorPtr);
}
void Noble::display() const {
	cout << name << " has an army of " << army.size() << endl;
	for (size_t i = 0; i < army.size(); i++) {
		cout << "\t" << army[i]->getName() << ": " << army[i]->getStrength() << endl;
	}
}
void displayStatus(vector <Noble*>& nobles, vector <Warrior*>& unemployed) {
	cout << "Status\n" << "============" << endl;
	cout << "Nobles: " << endl;
	if (nobles.size() == 0) {
		cout << "NONE" << endl;
	}
	else {
		for (size_t i = 0; i < nobles.size(); i++) {
			nobles[i]->display();
		}
	}
	cout << "Unemployed Warriors: " << endl;
	if (unemployed.size() == 0) {
		cout << "NONE" << endl;
	}
	else {
		for (size_t j = 0; j < unemployed.size(); j++) {
			unemployed[j]->display();
		}
	}
	cout << endl;
}


void hireWarrior(ifstream& ifs, vector<Warrior*>& unemployed, vector<Noble*>& nobles) {
	string noble;
	string newWarrior;
	ifs >> noble >> newWarrior;
	for (size_t i = 0; i < nobles.size(); i++) {
		if (nobles[i]->getName() == noble) {
			for (size_t j = 0; j < unemployed.size(); j++) {
				if (unemployed[j]->getName() == newWarrior) {
					nobles[i]->hire(unemployed[j]);
				}
			}
		}
	}
	for (size_t k = 0; k < unemployed.size(); k++) {
		if (unemployed[k]->getName() == newWarrior) {
			while (k + 1 < unemployed.size()) {
				unemployed[k] = unemployed[k + 1]; //Puts the warrior at the back of the unemployed vector, so that he may be employed
				k++;
			}
		}
	}
	unemployed.pop_back();
}

void Noble::fire(Warrior* badWarrior) {
	for (size_t i = 0; i < army.size(); i++) {
		if (army[i] == badWarrior) {
			army[i] = army[army.size() - 1];
			army.pop_back();//this warrior is forced to leave his army
		}
	}
}
void fireWarriors(ifstream& ifs, vector <Warrior*>& warriors, vector <Warrior*>& unemployed, vector <Noble*>& nobles) {
	string warriorName;
	string nobleName;

	ifs >> nobleName >> warriorName;
	cout << "You dont work for me anymore anymore " << warriorName << "! -- " << nobleName<< endl;
	for (size_t i = 0; i < nobles.size(); i++) {
		if (nobles[i]->getName() == nobleName) {
			for (size_t j = 0; j < warriors.size();j++) {
				if (warriors[j]->getName() == warriorName) {
					nobles[i]->fire(warriors[j]);
					unemployed.push_back(warriors[j]);//makes the warrior unemployed, now he can get benefits! 
				}
			}
		}
	}
}
double Noble::getArmyStrength() {//gets the total strength of a noble's army
	double totalStrength1=0;
	for (size_t i = 0; i < army.size(); i++) {
		totalStrength1 += (army[i]->getStrength());
	}
	return totalStrength1;
}
void Noble::setArmyStrength(double strengthFactor) {
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
void Noble::battle(Noble* otherNoble) {
	if (this->getArmyStrength() == 0 && otherNoble->getArmyStrength() == 0) {//if both armies have no strength
		cout << name << " battles " << otherNoble->getName();
		cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
	}
	else if (this->getArmyStrength() == 0) {//if one party is dead
		cout << "He's dead " << otherNoble->getName()<<endl;
	}
	else if (otherNoble->getArmyStrength() == 0) {//if the other party is dead
		cout << "He's dead " << this->getName() << endl;
	}
	else if (this->getArmyStrength() == otherNoble->getArmyStrength()) {//if both armies have the same total strength they annihilate
		cout << "mutual annihilation " << name << " and " << otherNoble->getName() << " die at each other's hands"<<endl;
		this->setArmyStrength(0);
		otherNoble->setArmyStrength(0);
	}

	else if (this->getArmyStrength() > otherNoble->getArmyStrength()) {//if the first army is stronger
		cout << name << " defeats " << otherNoble->getName() << endl;
		this->setArmyStrength(otherNoble->getArmyStrength() / this->getArmyStrength());
		otherNoble->setArmyStrength(0);
	}
	else if (otherNoble->getArmyStrength() > this->getArmyStrength()) {//if the second army is stronger
		cout << otherNoble->getName() << " defeats " << name<<endl;
		otherNoble->setArmyStrength(this->getArmyStrength() / otherNoble->getArmyStrength());
		this->setArmyStrength(0);
	}
}
	void battleNoble(ifstream& ifs, vector<Noble*>& nobles) {
		string firstNoble;
		string otherNoble;

		ifs >> firstNoble >> otherNoble;

		for (size_t i = 0; i < nobles.size(); i++) {
			if (nobles[i]->getName() == firstNoble) {
				for (size_t j = 0; j < nobles.size(); j++) {
					if (nobles[j]->getName() == otherNoble) {
						nobles[i]->battle(nobles[j]);
					}
				}
			}
		}
	}
	void status(vector <Noble*>& nobles, vector <Warrior*>& unemployed) {
		cout << "Status\n" << "============" << endl;
		cout << "Nobles: " << endl;
		if (nobles.size() == 0) {cout << "NONE" << endl;}
		else {
			for (size_t i = 0; i < nobles.size(); i++) {nobles[i]->display();}//calls the noble display method on the nobles
		}
		cout << "Unemployed Warriors: " << endl;
		if (unemployed.size() == 0) {cout << "NONE" << endl;}
		else {
			for (size_t j = 0; j < unemployed.size(); j++) {unemployed[j]->display();}//calls the warrior display method on the unemployed warriors
		}
		cout << endl;
	}
	void clearVectors(vector<Noble*>& nobles, vector<Warrior*>& warriors, vector<Warrior*>& unemployed) {
		for (Noble* noblePtr : nobles) {//goes through the noble vector deleting all the noble pointers
			delete noblePtr;
		}
			nobles.clear();

		for (Warrior* warriorPtr : warriors) {//goes through the warrior vector deleting all the warrior pointers
			delete warriorPtr;
		}
		warriors.clear();
		unemployed.clear();
	}
	void checkFile(ifstream& ifs) { //checks if the file is working
		if (!ifs) {
			cerr << "File not found, please enter a correct file path";
			exit(1);
		}
	}
void readFromFile(ifstream& ifs, vector<Warrior*>& warriors, vector<Warrior*>& unemployed, vector<Noble*>& nobles) {
	string cmd;//reads the command provided by the file into this variable
	while (ifs >> cmd) {
		if (cmd == "Noble") { newNoble(ifs, nobles); }
		else if (cmd == "Battle") { battleNoble(ifs, nobles); }//if the command is battle then the battle function is used
		else if (cmd == "Status") { status(nobles,unemployed); }//if the command is status then the status function is used
		else if (cmd == "Warrior") { newWarrior(ifs, warriors,unemployed); }//if the command is warrior then the warrior function is used
		else if (cmd == "Noble") { newNoble(ifs, nobles); }//if cmd = noble then noble()
		else if (cmd == "Hire") { hireWarrior(ifs, unemployed, nobles); }//if cmd = hire then hire()
		else if (cmd == "Fire") { fireWarriors(ifs, warriors, unemployed, nobles); }//if cmd = fire then fire()
		else if (cmd == "Clear") { clearVectors(nobles, warriors, unemployed); }//if cmd = clear then clear()
	}
}
int main() {
	vector<Warrior*> warriors;
	vector<Warrior*> unemployed;
	vector<Noble*> nobles;

	ifstream ifs("nobleWarriors.txt");
	checkFile(ifs);
	readFromFile(ifs, warriors, unemployed, nobles);
}