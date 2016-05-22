//include "hw8.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;


struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
	int getData() {
		if(this)
			return data; 
		return -1;
	}
};
class Polynomial {
private:
	Node* headPtr;
	int degree;
public:
	Polynomial(Node* headPtr = nullptr, int degree=0): headPtr(headPtr), degree(degree){}
	Polynomial(vector<int> coefficients) : headPtr(nullptr), degree(-1) {
		for (int coef : coefficients) {
			headPtr = new Node(coef, headPtr);
			degree++;
		}
	}
	Node* getHeadPtr() { return headPtr; }
	virtual ~Polynomial() { clear(headPtr); }
	Polynomial(const Polynomial& rhs) {
		if(headPtr!=nullptr){
			headPtr = new Node(rhs.headPtr->data, rhs.headPtr->next);
			degree = rhs.degree;
		}
	}
	void displayPoly();
	int getDegree() { return degree; }
	friend ostream& operator<<(Polynomial* rhs, std::ostream& os) {
		if (rhs->getDegree() == -1) {
			os << "no Polynomial" << endl;
		}
		else {
			Node * temp = rhs->getHeadPtr();
			while (temp->next != nullptr) {
				os << temp->getData() << ",";
			}
		}
		return os;
	}
	friend Polynomial& operator+(Polynomial& rhs, Polynomial& lhs);
	friend void clear(Node*& headPtr) {
		while(headPtr){
			Node* temp = headPtr->next;
			headPtr=temp;
		}
	}
	friend Polynomial& operator+=(Polynomial& lhs,const Polynomial& rhs) {
		Node* listOne = lhs.headPtr;
		Node* listTwo = rhs.headPtr;
		for (int i = 0; i <= rhs.degree; ++i) {
			if (!listOne) {
				listOne = new Node(0);
			}
			listOne->data += listTwo->data;
			lhs.headPtr = listOne;
			listTwo = listTwo->next;
			listOne = listOne->next;

		}
		
		return lhs;
	}
	bool operator==(const Polynomial& rhs) {
		if (rhs.headPtr == nullptr && headPtr == nullptr)
			return true;
		Node* temp = rhs.headPtr;
		Node* temp2 = headPtr;
		while (temp) {
			if (!temp2)return false;
			if (temp->data != temp2->data)return false;
			temp = temp->next;
			temp2 = temp2->next;
		}
		if (temp2)return false;
		return true;

	}
};
/* ostream& operator<<(Polynomial rhs, ostream& os) {
	if (rhs.getDegree() == -1) {
		os << "no Polynomial" << endl;
	}
	else {
		Node * temp=rhs.getHeadPtr();
		while (temp->next != nullptr) {
			os << temp->getData() << ",";
		}
	}
	return os;
}*/
Polynomial& operator+(Polynomial& lhs, Polynomial& rhs) {
	vector<int> intVec;
	Node* temp = lhs.headPtr;
	while (temp) {
		intVec.push_back(temp->data);
		temp = temp->next;
	}
	Polynomial result(intVec);
	result += rhs;
	return result;
}
/*Polynomial& operator+(Polynomial& rhs, Polynomial& lhs) {
	vector<int> intVec;
	Node* temp = rhs.getHeadPtr();
	Node* temp2 = lhs.getHeadPtr();
	while (temp != nullptr || temp2 != nullptr) {
			intVec.push_back(temp->data + temp2->data);	
			temp = temp->next;
			temp2 = temp2->next;
	}
	Polynomial* temp3 = new Polynomial(intVec);
	
	return *temp3;
}*/

void Polynomial::displayPoly(){
	while (headPtr != nullptr) {
		if (degree == 0) {
		cout << headPtr->getData();
		return;
		}
		else if(degree==1){ 
		cout << headPtr->getData() << "x"<<" + "; 
		headPtr = headPtr->next;
		}
		else{
		cout << headPtr->getData() << "x^" << degree<<" + ";
		headPtr = headPtr->next;
		}
		degree--;
	}
}

int main() {
	string nothing;
	vector<int> intVec = { 1,2,3,4,5,6 };
	vector<int> intVec2 = { 1,2,3,4,5,6 };
	Polynomial p(intVec);
	Polynomial* pPtr= new Polynomial(intVec2);
	//Polynomial p3 = p+p2;
	//p3.displayPoly();
	cout << *&pPtr;
	cin >> nothing;
	cout << endl;
}