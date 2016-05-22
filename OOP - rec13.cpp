#include <iostream>
#include <string>

using namespace std;

void displayInBinary(int n) {
	if (n < 2) {
		cout << n % 2;
		return;
	}
	if (n % 2 == 1) {
		displayInBinary(n / 2);
		cout << "1";
	}
	else if (n % 2 == 0) {
		displayInBinary(n / 2);
		cout << "0";
	}
}

struct Node {
	int data;
	Node* next;
	Node(int data, Node* next=nullptr): data(data), next(next) {}
};

void pushFront(Node*& head, int entry) {
	head = new Node(entry,head);
}

Node* findLastNode(Node* headPtr) {
	Node* temp = headPtr;
	if (temp != nullptr) {
		while (temp->next != nullptr) {
			temp = temp->next;
		}
	}
	return temp;
}

void listAppend(Node*& list1, Node* list2) {
	if (list1 == nullptr) {
		list1 = list2;
	}
	Node* last = findLastNode(list1);
	last->next = list2;
}

void listDisplay(const Node* headPtr) {
	const Node* temp = headPtr;
	while (temp != nullptr) {
		cout << temp->data<< " ";
		temp = temp->next;
	}
}

Node* listOfSums(Node*& list1, Node*& list2) {
	if (list1 == nullptr) {
		cout << "empty list" << endl;
		return nullptr;
	}
	Node* list3 = new Node((list1->data+list2->data));
	if (list1->next == nullptr) {
		return list3;
	}
	else {
		// list 3 next 
		list3->next=listOfSums(list1->next,list2->next);
	}
	return list3;
}

int charSum(char* cstring) {
	if (*cstring == '\0')
		return 0;
	return int(*cstring) + charSum(cstring + 1);
}

int binSearch(int* arr, int target, int low, int high) {
	int mid = (low + (high - low)) / 2;
	if (target < arr[mid]) {
		return binSearch(arr, target, low, mid - 1);
	}
	else {
		return binSearch(arr, target, mid + 1, high);
	}
}
char charBinSearch(char* arr, char target, int len,int pos) {
	if (arr == '\0') {
		return -1;
	}
	int mid = len / 2;
	if (target == arr[mid]) {
		cout << "the following character has been found:";
		return arr[mid];
	}
	if (mid <= 1) {
		cout << "no match found" << endl;
		return -1;
	}
	else if (target < arr[mid]) {
		return charBinSearch(arr, target, mid, pos);
	}
	else {
		return charBinSearch(arr+(mid), target,mid, pos+=mid);
	}
}

void f(int n) {
	if (n > 1) {
		cout << 'a';
		f(n / 2);
		cout << 'b';
		f(n / 2);
	}
	cout << 'c';
}
int main() {
	string nothing;
	int n = 10;
	int number = 2;
	cout << "------PART-1------" << endl;
	cout << n << " in binary is :";
	displayInBinary(n);

	cout << endl << "------PART-2------" << endl;

	Node* headPtr1 = new Node(5);
	pushFront(headPtr1, 3);
	pushFront(headPtr1, 3);
	Node* headPtr2 = new Node(5);
	pushFront(headPtr2, 4);
	pushFront(headPtr2, 4);
	Node* newHeadPtr;
	cout << "list 1: ";
	listDisplay(headPtr1);
	cout << "list 2: ";
	listDisplay(headPtr2);
	cout << "list 3: ";
	newHeadPtr=listOfSums(headPtr1, headPtr2);
	listDisplay(newHeadPtr);

	cout << endl << "------PART-3------" << endl;
	cout << "In the file tree.cpp" << endl;

	cout  << "------PART-4------" << endl;
	cout << "the sum of this cstring is :" << charSum("abc");

	cout << endl << "------PART-5------" << endl;
	cout<<charBinSearch("AAABCCCCCCCCDDDDDDDDD", 'B', 21, 1);

	cout << endl << "------PART-6------" << endl;
	f(number);// larger than 1, therefore a is output
	//recursive call on 1, outputs c
	//first iteration now outputs b
	//recursive call on 1 outputs c
	//first iteration reaches the end outputing c
	std::cin >> nothing;
} 