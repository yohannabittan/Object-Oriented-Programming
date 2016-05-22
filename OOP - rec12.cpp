/*
Yohann Abittan
netID: yaa243
4/24/2016
filename: rec12.cpp
*/

#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

class Sequence {
	Node* head;
	Node* current;
	void display(Node* top) const;

public:
	Sequence() : head(nullptr), current(nullptr) {}
	Sequence(const Sequence& rhs) : head(nullptr), current(nullptr) { *this = rhs; }
	virtual ~Sequence() { clear(); }
	Sequence& operator=(const Sequence& rhs);
	void reset() { current = head; }

	void add(int val);
	
	void remove();
	
	int data();
	
	void next();
	
	bool valid();
	
	void clear();
	
	void display() const;
};

Sequence& Sequence::operator=(const Sequence& rhs) {
	if (this != &rhs) 
	{
		clear();
		Node* temp = rhs.head;
		while (temp) 
		{
			add(temp->data);
			temp = temp->next;
		}
	}
	return *this;
}

void Sequence::add(int val) {
	if (!valid()) 
	{
		head = new Node(val);
		current = head;
	}
	else 
	{
		Node* temp = new Node(val);
		temp->next = current->next;
		current->next = temp;
		current = temp;
	}
}

void Sequence::remove() {
	if (current == head) 
	{
		head = current->next;
		delete current;
		current = head;
	}
	else {
		Node* nextPtr = current->next;
		Node* prevPtr = head;
		while (prevPtr->next != current) 
		{
			prevPtr = prevPtr->next;
		}
		prevPtr->next = current->next;
		delete current;
		current = nextPtr;
	}
}

int Sequence::data() {
	if (!valid())
		return 0;
	return current->data;
}

void Sequence::next() {
	if (!valid())
		return;
	current = current->next;
}

bool Sequence::valid() {
	return current != nullptr;
}

void Sequence::clear() {
	reset();
	while (head != nullptr) {
		remove();
	}
}


void Sequence::display()const {
	display(head);
	cout << endl;
}

void Sequence::display(Node* nodeP)const {
	if (nodeP == nullptr) {
		return;
	}
	cout << nodeP->data << " ";
	display(nodeP->next);
}

int main() {
	Sequence s;
	for (size_t i = 0; i < 6; ++i) 
		s.add(i);
	s.display();
	cout << "=========="<<endl;
	s.reset();
	for (size_t i = 0; i < 3; ++i)
		s.next();
	s.add(42);
	s.display();
	cout << "=========="<<endl;
	s.reset();
	for (size_t i = 0; i < 2; ++i) 
		s.next();
	s.remove();
	s.display();
	cout << "=========="<<endl;
	s.clear();
	s.display();
	cout << "=========="<<endl;
}
