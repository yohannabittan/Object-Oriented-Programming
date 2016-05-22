#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Hydrocarbon {
	vector <string> names;
	char carbons;
	int carbonNumber;
	char hydrogens;
	int hydrogenNumber;
};

string getFileName() { //can easily be changed into taking a file name
	string fileToRead = "hydrocarbons.txt";
	//cout<<"What is the name of the file you would like to read?"<<endl;
	//cin>>fileToRead;
	return fileToRead;
}
void checkFile(ifstream& ifs, string fileToRead) { //checks if the file opens
	while (!ifs) {
		cerr << "Failed to open the file, please enter the correct filename\n";
		cin >> fileToRead;
	}

}
// checks for duplicates i.e. isomers , if they are present, the name of the isomer is added to the vector of names
size_t checkForDuplicates(vector <Hydrocarbon>& hydrocarbons, int localCarbonNumber, int localHydrogenNumber) {
	size_t sizeOfVector = hydrocarbons.size();
	for (size_t i = 0; i < sizeOfVector; i++) {
		int localCarbonNumber = hydrocarbons[i].carbonNumber;
		int localHydrogensNumber = hydrocarbons[i].hydrogenNumber;
		if (hydrocarbons[i].carbonNumber == localCarbonNumber && hydrocarbons[i].hydrogenNumber == localHydrogenNumber) {
			return i;
		}
	}
	return sizeOfVector;
}
void fillVector(ifstream& ifs, vector <Hydrocarbon>& hydrocarbons) {//pushes back the hydrocarbons into a vector to be displayed later

	Hydrocarbon hydrocarbon;
	string localName;
	char localCarbons;
	int localCarbonNumber;
	char localHydrogens;
	int localHydrogenNumber;

	while (ifs >> localName >> localCarbons >> localCarbonNumber >> localHydrogens >> localHydrogenNumber) {
		size_t index = checkForDuplicates(hydrocarbons, localCarbonNumber, localHydrogenNumber);
		if (index == hydrocarbons.size()) {
			hydrocarbon.carbonNumber = localCarbonNumber;
			hydrocarbon.hydrogenNumber = localHydrogenNumber;
			hydrocarbons.push_back(hydrocarbon);
		}
		else {
			hydrocarbons[index].names.push_back(localName);
		}
	}

}
void printHydrocarbons(vector<Hydrocarbon>& hydrocarbons) { //displays the hydrocarbons in order of carbon number
		int maximum = hydrocarbons[0].carbonNumber;
		for (size_t i = 0; i < hydrocarbons.size(); i++) {
			if (hydrocarbons[i].carbonNumber) {
				maximum = hydrocarbons[i].carbonNumber;
			}
		}
		for (int x = 1; x <= maximum; x++) {
			for (size_t y = 0; y < hydrocarbons.size(); y++) {
			if (x == hydrocarbons[y].carbonNumber) {
				cout << endl << 'C' << hydrocarbons[y].carbonNumber << 'H' << hydrocarbons[y].hydrogenNumber;
				for (size_t z = 0; z < hydrocarbons[y].names.size(); z++) {
					cout << ' ' << hydrocarbons[y].names[z];
				}
			}
		}
	}
}
void main() {
	vector <Hydrocarbon> hydrocarbons;
	string fileName;
	ifstream ifs;
	fileName = getFileName();
	checkFile(ifs, fileName);
	ifs.open(fileName);
	fillVector(ifs, hydrocarbons);
	printHydrocarbons(hydrocarbons);
}
