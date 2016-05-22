/*
Name: Yohann Abittan
date: 5/6/2016
fileName: rec14.cpp

*/
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

void iteratorPrint(const list<int>& intList) {
	cout << endl << "iterator function to print list: " << endl;
	for (list<int>::const_iterator iter = intList.begin(); iter != intList.end(); ++iter) {
		cout << *iter;
	}
}
void rangedForPrint(const list<int>& intList) {
	cout << endl << "ranged for function to print list: " << endl;
	for (int num : intList){
		cout << num;
	}
}
auto itemFinder(const list<int>& intList, int target) {
	cout << endl << "item finder:" << endl;
	for (auto iter = intList.begin(); iter != intList.end(); ++iter) {
		if (*iter == target) {
			cout << "Target found" << endl;
			return iter;
		}
	}
	cout << "No target found" << endl;
	return intList.end();
}
	
auto itemFinderAlgorithm(const list<int>& intList, int target) {
	cout << endl << "item finder using an algorithm:" << endl;
	auto temp = find(intList.begin(), intList.end(), 10);
	if (temp == intList.end()) {cout << "Target not found" << endl;}
	else {cout << "Target found" << endl;}
}
bool isOdd(int target) {
	if (target % 2 == 0) {
		return false;
	}
	else return true;
}

auto itemFinderAlgorithmEven(const list<int>& intList) {
	cout << endl << "item finder for even numbers using an algorithm:" << endl;
	auto temp = find_if(intList.begin(), intList.end(), isOdd);
	if (temp == intList.end()) { cout << "Target not found" << endl; }
	else { cout << "Target found" << endl; }
}

auto ourFind(const list<int>& intList, int target) {
	cout << "This is our find function:";
	itemFinder(intList, target);
}

template<typename L, typename I>
L templateFind(L listStart,L listEnd, I target) {
	cerr << "in Template\n";
	for (auto i = listStart; i != listEnd; i++) {
		if (target == *i) {
			cout << "Target found" << endl;
			return i;
		}
	}
	cout << "Target not found" << endl;
	return listEnd;
}

void uniqueWords(ifstream& ifs) {
	string word;
	bool isFound=false;
	vector<string> sVector;
	ifs >> word;
	sVector.push_back(word);
	while (ifs >>skipws>>word) {
		for (size_t i = 0; i < sVector.size(); i++) {
			if (word == sVector[i]) {
				isFound = true;
			}
		}

			if (isFound != true) {
				sVector.push_back(word);
			}
		
	}
	for (string words : sVector) {
		cout << words;
	}
}

int main() {
	string nothing;
	int counter = 1;
	cout << "Original vector: " << endl;
	vector<int> intVec = { 1,5,3,4,5,6 };
	int localArr[6];
	for (int num : intVec) {
		cout << num;
	}
	cout << endl << "List from vector: " << endl;
	list<int> intList(intVec.begin(),intVec.end());
	for (int num : intList) {
		cout << num;
	}
	cout << endl << "Sorted vector: " << endl;
	sort(intVec.begin(),intVec.end());
	for (int num : intVec) {
		cout << num;
	}
	cout << endl << "Loop through list: " << endl;
	for (list<int>::iterator iter = intList.begin(); iter != intList.end();++iter) {
		cout << *iter;
	}
	cout << endl << "Odd elements of vector: " << endl;
	for (vector<int>::iterator iter = intVec.begin(); iter != intVec.end(); iter+=2) {
		cout << *iter;
	}
	cout << endl << "Odd elements of the list: " << endl;
	/*for (list<int>::iterator iter = intList.begin(); iter != intList.end(); iter++) {
		if (counter % 2 == 0) {
			cout << "";
			counter++;
		}
		else {
		cout << *iter;
		counter++;
		}
	}*/
	for (auto iter = intList.begin(); iter != intList.end(); iter++) {
		if (counter % 2 == 0) {
			cout << "";
			counter++;
		}
		else {
			cout << *iter;
			counter++;
		}
	}

	iteratorPrint(intList);
	rangedForPrint(intList);
	itemFinder(intList, 1);
	itemFinder(intList, 10);
	itemFinderAlgorithm(intList, 1);
	itemFinderAlgorithmEven(intList);

	cout << "Copying from array and displaying" << endl;
	copy(intVec.begin(), intVec.end(), localArr);
	for (size_t i = 0; i < 6; i++) {
		cout << localArr[i];
	}
	cout << endl;

	ourFind(intList, 3);

	cout << "Using template Find on vector:" << endl;
	templateFind(intVec.begin(),intVec.end(),3);

	cout << "Using template Find on list:" << endl;
	templateFind(intList.begin(), intList.end(), 3);

	cout << endl << "=====TASK 19=====" << endl;
	ifstream ifs; 
	ifs.open("pooh-nopunc.txt");

	uniqueWords(ifs);


	cin >> nothing;
	cout << "Press any key to exit";
}