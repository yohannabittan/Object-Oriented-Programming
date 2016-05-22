#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getFileName();
void openFile(ifstream&, string);
void readType(ifstream&);
void readChar(ifstream&);
void readWord(ifstream&);
void readLine(ifstream&);

string getFileName(){
    string fileToRead="jabberwocky.txt";
    //cout<<"What is the name of the file you would like to read?"<<endl;
    //cin>>fileToRead;
    return fileToRead;
}

void openFile(ifstream& ifs, string fileToRead) {
	while (!ifs) {
		cerr << "Failed to open the file, please enter the correct filename\n";
		cin >> fileToRead;
	}
}
void readType(ifstream& ifs){
	string affirmative = "y";
	string positive = "Y";
    string typeDecision1;
    string typeDecision2;
    string typeDecision3;

    cout<<"Would you like to read this file character by character? (y/n)"<<endl;
	cin >> typeDecision1;
    if (typeDecision1 == affirmative||typeDecision1==positive){readChar(ifs);}
	else {
		cout << "Would you like to read this file word by word? (y/n)" << endl;
		cin >> typeDecision2;
	}
    if (typeDecision2 == affirmative || typeDecision1 == positive){readWord(ifs);}
	else {
		cout << "Would you like to read this file line by line? (y/n)" << endl;
		cin >> typeDecision3;
	}
    if (typeDecision3 == affirmative || typeDecision1 == positive){readLine(ifs);}
}

void readChar(ifstream& ifs) {

	char c;
	int charcount=0;
	while (ifs >> c) {
		charcount+=1;
		cout << c << endl;
	}
}
void readWord(ifstream& ifs) {

	string word;
	int wordcount=0;
	while (ifs >> word) {
		wordcount+=1;
		cout << word << endl;
	}
}
void readLine(ifstream& ifs) {

string line;
int linecount=0;
while (getline(ifs, line)) {
	linecount+=1;
	cout << line << endl;
    }
}
void main() {
string any;
any=getFileName();
ifstream ifs;
ifs.open(any);
getFileName();
openFile(ifs, any);
readType(ifs);
}


