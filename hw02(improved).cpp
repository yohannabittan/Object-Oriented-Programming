/*
Filename: Hw02.cpp
Programmer: Yohann Abittan
netID: yaa243

The aim of this program is to simulate medieval times through a game of warriors
*/

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

struct Warrior{
		 string name;
		 int strength;
};

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
	Warrior newWarrior;
	string warriorName;
	int warriorStrength;
	ifs >> warriorName >> warriorStrength;//reads the strength and name into a new warrior
	newWarrior.strength = warriorStrength;
	newWarrior.name = warriorName;
	warriors.push_back(newWarrior);
	
}
void status(vector <Warrior>& warriors) {//displays the number of warriors, their names, and their strengths

	cout << "There are currently " << warriors.size() << " warriors"<<endl;
	for (size_t i = 0; i < warriors.size(); i++) {
		cout << "Warrior: " << warriors[i].name << " and his strength is: " << warriors[i].strength << endl;
	}
}

void battle(vector <Warrior>& warriors, ifstream& ifs ){//makes the two warriors fight, and outputs the result of the fight, also changes their strength if need be
	string fighter1;
	string fighter2;
	size_t fighterIndex1=0;
	size_t fighterIndex2=0;

	ifs >> fighter1 >> fighter2;

	for (size_t i = 0; i < warriors.size(); i++) {
		if (fighter1 == warriors[i].name) {//finds which warrior is called in the vector
			fighterIndex1 = i;
			for (size_t j = 0; j < warriors.size(); j++) {
				if (fighter2 == warriors[j].name) {//finds his opponent
					fighterIndex2 = j;
				}
			}
		}
	}

	if (warriors[fighterIndex1].strength == 0 && warriors[fighterIndex2].strength == 0) {//checks if theyre both dead
	cout << fighter1 << " battles " << fighter2 << endl;
	cout << "Oh, NO!They're both dead! Yuck!" << endl;
	}
	else if (warriors[fighterIndex1].strength == 0) {//checks if one of them is dead
	cout << fighter1 << " battles " << fighter2 << endl;
	cout << "He's dead" << fighter2 << endl;
	}
	else if (warriors[fighterIndex2].strength == 0) {//checks if the other one is dead
	cout << fighter1 << " battles " << fighter2 << endl;
	cout << "He's dead " << fighter1 <<endl;
	}
	else if (warriors[fighterIndex1].strength == warriors[fighterIndex2].strength) {//checks if they are alive but have equal strength
	cout << fighter1 << " battles " << fighter2 << endl;
	cout << "Mutual Annihilation : " << fighter1 << " and " << fighter2 << " die at each other's hands" << endl;
	warriors[fighterIndex1].strength = 0;
	warriors[fighterIndex2].strength = 0;
	}
	else if (warriors[fighterIndex1].strength > warriors[fighterIndex2].strength) {//checks if the first warrior wins
	cout << fighter1 << " battles " << fighter2 << endl;
	cout << fighter1 << " defeats " << fighter2 << endl;
	warriors[fighterIndex1].strength = ((warriors[fighterIndex1].strength) - (warriors[fighterIndex2].strength));
	warriors[fighterIndex2].strength = 0;//makes the second warrior dead
	}
	else if (warriors[fighterIndex1].strength < warriors[fighterIndex2].strength) {//checks if the second warrior wins
	cout << fighter1 << " battles " << fighter2 << endl;
	cout << fighter2 << " defeats " << fighter1 << endl;
	warriors[fighterIndex2].strength = ((warriors[fighterIndex2].strength) - (warriors[fighterIndex1].strength));
	warriors[fighterIndex1].strength = 0;//makes the first warrior dead

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