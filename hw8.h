#include <vector>
#include <iostream>
#ifndef HW8_H
#define HW8_H

struct Node {
	Node(int data=0,Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};
class Polynomial{
private:

	Node* head;
	int<vector> coef;
public:
	Polynomial(Node* arr = {}) : arr(arr), degree(degree) {}
	Polynomial(const Polynomial& rhs);
	~Polynomial();
	void listDisplay(const Node* headPtr, std::ostream& = std::cout);


#endif 