/*
Filename: Hw03.cpp
Programmer: Yohann Abittan
netID: yaa243

The aim of this program is to simulate medieval times through a game of warriors, now with weapons!
*/

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Weapon {
private:
	string weaponName;
	int weaponStrength;
public:
	Weapon(string theWeaponName = "", int theWeaponStrength = 0) : weaponStrength(theWeaponStrength), weaponName(theWeaponName) {}
	void setName(string name) { weaponName = name; }
	void setStrength(int strength) { weaponStrength = strength; }
	string getName() const { return weaponName; }
	int getStrength() const { return weaponStrength; }

};

class Warrior {
private:
	string name;
	Weapon weapon;
public:
	Warrior(string warriorName = "Anonymous", string weaponName = "", int weaponStrength = 0) : name(warriorName), weapon(weaponName, weaponStrength) {}
	void display() const {//made constant because the display method must not change any data
	}
	//setter 
	void setName(const string& newName) { name = newName; }
	void setStrength(int newStrength) { weapon.setStrength(newStrength); }
	void setWeaponName(string newWeaponName) { weapon.setName(newWeaponName); }
	//getter
	string getName() const { return name; }
	int getWeaponStrength() const { return weapon.getStrength(); }
	string getWeaponName() const { return weapon.getName(); }
};
/*void Weapon::displayWeapon() const {
cout<<
}

void Warrior::displayWarrior()const {
cout << "Warrior: " << name <<;
weapon.displayWeapon();
}*/

string getFileName();
void checkFile(ifstream& ifs, string& fileToRead);
void readFromFile(ifstream& ifs, vector<Warrior>& warriors);
void newWarrior(ifstream& ifs, vector<Warrior>& warriors);
void status(vector <Warrior>& warriors);
void battle(vector <Warrior>& warriors, ifstream& ifs);



string getFileName() { //can easily be changed into taking a file name
	string fileToRead = "warriors (1).txt";
	//cout<<"What is the name of the file you would like to read?"<<endl;
	//cin>>fileToRead;
	return fileToRead;
}

void checkFile(ifstream& ifs, string& fileToRead) { //checks if the file opens
	while (!ifs) {
		cerr << "Failed to open the file, please enter the correct filename\n";
		cin >> fileToRead;
	}

}

void readFromFile(ifstream& ifs, vector<Warrior>& warriors) {
	string cmd;//reads the command provided by the file into this variable
	while (ifs >> cmd) {
		if (cmd == "Battle") {//if the command is battle then the battle function is used
			battle(warriors, ifs);
		}
		else if (cmd == "Status") {//if the command is status then the status function is used
			status(warriors);
		}
		else if (cmd == "Warrior") {//if the command is status then the warrior function is used
			newWarrior(ifs, warriors);
		}
	}
}
void newWarrior(ifstream& ifs, vector<Warrior>& warriors) {//creates a new warrior and adds him to the vector of warriors
	string warriorName;
	string weaponName;
	int weaponStrength;

	ifs >> warriorName >> weaponName >> weaponStrength;//reads the strength and name into a new warrior
	Warrior newWarrior(warriorName, weaponName, weaponStrength);
	warriors.push_back(newWarrior);

}
void status(vector <Warrior>& warriors) {//displays the number of warriors, their names, and their strengths

	cout << "There are currently " << warriors.size() << " warriors" << endl;
	for (size_t i = 0; i < warriors.size(); i++) {
		cout << "Warrior: " << warriors[i].getName() << ", Weapon:" << warriors[i].getWeaponName() << " , " << warriors[i].getWeaponStrength() << endl;
	}
}

void battle(vector <Warrior>& warriors, ifstream& ifs) {//makes the two warriors fight, and outputs the result of the fight, also changes their strength if need be
	string fighter1name;
	string fighter2name;
	Warrior fighter1;
	Warrior fighter2;

	ifs >> fighter1name >> fighter2name;

	for (size_t i = 0; i < warriors.size(); i++) {
		if (fighter1name == warriors[i].getName()) {//finds which warrior is called in the vector
			fighter1 = (warriors[i]);
		}
	}
	for (size_t j = 0; j < warriors.size(); j++) {
		if (fighter2name == warriors[j].getName()) {//finds his opponent
			fighter2 = (warriors[j]);
		}
	}
	if (fighter1.getWeaponStrength() == 0 && fighter2.getWeaponStrength() == 0) {//checks if theyre both dead
		cout << fighter1name << " battles " << fighter2name << endl;
		cout << "Oh, NO!They're both dead! Yuck!" << endl;
	}
	else if (fighter2.getWeaponStrength() == fighter1.getWeaponStrength()) {//checks if they are alive but have equal strength
		cout << fighter1name << " battles " << fighter2name << endl;
		cout << "Mutual Annihilation : " << fighter1name << " and " << fighter2name << " die at each other's hands" << endl;
		fighter1.setStrength(0);
		fighter2.setStrength(0);
	}
	else if (fighter1.getWeaponStrength() == 0) {//checks if one of them is dead
		cout << fighter1name << " battles " << fighter2name << endl;
		cout << "He's dead " << fighter2name << endl;
	}
	else if (fighter2.getWeaponStrength() == 0) {//checks if the other one is dead
		cout << fighter1name << " battles " << fighter2name << endl;
		cout << "He's dead" << fighter1name << endl;

	}
	else if (fighter1.getWeaponStrength() > fighter2.getWeaponStrength()) {//checks if the first warrior wins
		cout << fighter1name << " battles " << fighter2name << endl;
		cout << fighter1name << " defeats " << fighter2name << endl;
		fighter1.setStrength((fighter1.getWeaponStrength() - fighter2.getWeaponStrength()));
		fighter2.setStrength(0);//makes the second warrior dead
	}
	else if (fighter1.getWeaponStrength() < fighter2.getWeaponStrength()) {//checks if the second warrior wins
		cout << fighter1name << " battles " << fighter2name << endl;
		cout << fighter2name << " defeats " << fighter1name << endl;
		fighter2.setStrength((fighter2.getWeaponStrength() - (fighter1.getWeaponStrength())));
		fighter1.setStrength(0);//makes the first warrior dead
	}
	for (size_t i = 0; i < warriors.size(); i++) {
		if (fighter1name == warriors[i].getName()) {//finds which warrior is called in the vector
			(warriors[i] = fighter1);
		}
	}
	for (size_t j = 0; j < warriors.size(); j++) {
		if (fighter2name == warriors[j].getName()) {//finds his opponent
			(warriors[j] = fighter2);
		}
	}
}



int main() {
	string nothing;
	string fileName;
	ifstream ifs;
	vector<Warrior> warriors;
	fileName = getFileName();
	ifs.open(fileName);
	checkFile(ifs, fileName);
	readFromFile(ifs, warriors);
	ifs.close();
	cin >> nothing;
}