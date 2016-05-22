/*
Hw01.cpp
Programmed by Yohann Abittan
yaa243

the aim of this program is to read through an encrypted file and output a decrypted version of said file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string getFileName();
void checkFile(ifstream& ifs, string fileToRead);
int intGetter(ifstream& ifs);
char charDecryptor(int encryptionInt, string encryptedString);
void dataPresenter(vector <string>& decryptedMessage);

string getFileName() {
	//asks the user for the filename
	cout << "What file would you like to read from?" << endl;
	string fileToRead = "encrypted.txt";
	cin >> fileToRead;
	return fileToRead;
}

void checkFile(ifstream& ifs, string fileToRead) {
	//checks if the path exists
	while (!ifs) {
		cerr << "Failed to open the file, please enter the correct filename\n";
		cin >> fileToRead;
	}
}
int intGetter(ifstream& ifs) {

	int encryptionInt = 0; //number of rotations
	string emptyLine; // will store the empty line after the number of rotations

	ifs >> encryptionInt;
	getline(ifs, emptyLine);
	cout << endl;
	cout << "the number of rotations is :" << encryptionInt << endl;
	cout << endl;
	return encryptionInt;
}
char charDecryptor(int encryptionInt, char encryptedChar) {

	char decryptedChar;//rotated character

	if (encryptedChar == ' ' || encryptedChar == ',' || encryptedChar == '.' || encryptedChar == ';')
	{
		decryptedChar = encryptedChar;
	}

	if (encryptedChar < 123 && encryptedChar >(96 + encryptionInt))
	{
		decryptedChar = encryptedChar - encryptionInt;
	}
	else if (encryptedChar < 102 && encryptedChar>96)
	{
		decryptedChar = ((encryptedChar + 26) - encryptionInt);
	}
	else 
	{
		decryptedChar = encryptedChar;
	}
	return decryptedChar;
}
void dataPresenter(vector <string>& decryptedMessage) {
	//outputs the decrypted message backwards line by line
	cout << endl;
	cout << "Here is the decrypted message :" << endl;
	for (size_t i = decryptedMessage.size()-1; i >= 0; i--) {
		cout << decryptedMessage[i] << endl;
	}
}
void main() {
	string fileName;
	string nothing;
	string encryptedString;
	string decryptedString;
	string line;
	char decryptedChar;
	vector <string> decryptedMessage;
	int encryptionInt;


	fileName = getFileName();
	ifstream ifs(fileName);
	checkFile(ifs, fileName);
	encryptionInt = intGetter(ifs);
	cout<<"Here is the coded message : " << endl;
	cout << endl;
	while (!ifs.eof())
	{
		//gets the lines from the file
		getline(ifs, line);
		cout << line << endl;
		decryptedMessage.push_back(line);
	}

	//loops through vector of strings and decrypts each char
	for (size_t i = 0; i < decryptedMessage.size(); i++) {
		for (size_t j = 0; j < decryptedMessage[i].size(); j++) {
			decryptedChar = charDecryptor(encryptionInt, decryptedMessage[i][j]);
			decryptedMessage[i][j] = decryptedChar;

		}
	}
	dataPresenter(decryptedMessage);
	cin >> nothing;
}
