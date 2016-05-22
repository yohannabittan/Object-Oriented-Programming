/*
filename: rec11.cpp
made by Yohann Abittan
netid: yaa243
*/
#include <cstdlib> // To allow NULL if no other includes
#include <iostream>

using namespace std;

class LList;

struct Node{
    int data;
    Node * next;
    Node(int newData = 0, Node* newNext = nullptr): data(newData), next(newNext){}
};
void push_front(int newData, Node*& head){head = new Node(newData, head);}
void push_back(int newData, Node*& head){
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = new Node(newData);
}
void spliceLList( Node*& splicePoint, Node* otherLList ){
    Node* temp = splicePoint->next;
    splicePoint->next = otherLList;
    while( otherLList->next != nullptr ){
        otherLList = otherLList->next;
    }
    otherLList->next = temp;
}
Node* searchNode( int data, Node* llist ){
    Node* temp = llist;
    while( temp != nullptr ){
        if( temp->data == data )
            return temp;
        temp = temp->next;
    }
    return nullptr;
}
ostream& operator<<(ostream& os, Node* rhs){
    if( rhs == nullptr )
        os << "No Matching Linked List" << endl;
    else{
        Node* temp = rhs;
        while( temp != nullptr ){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
    return os;
}
Node* searchList( Node* mainLList, Node* subList ){
    Node* outputLList = nullptr;
    Node* temp = mainLList;
    Node* temp2 = mainLList;
    Node* tempSub = subList;
    
    while (tempSub != nullptr && temp != nullptr){
        if (temp->data == tempSub->data){
            if (!outputLList)
                outputLList = temp;
            if (temp->next){
                temp = temp->next;
                tempSub = tempSub->next;
            }
            else{
                if(tempSub->next != nullptr)
                    outputLList = nullptr;
                break;
            }
        }
        else{
            if (outputLList){
                outputLList = nullptr;
                tempSub = subList;
                temp2 = temp2->next;
                temp = temp2;
            }
            else
                temp = temp->next;
        }
    }
    return outputLList;
}
int main(){
    

    cout << "Part One" << endl << endl;
    
    Node* llist1 = nullptr;
    push_front( 1, llist1 );
    push_front( 9, llist1 );
    push_front( 7, llist1 );
    push_front( 5, llist1 );
    
    cout << "L1: " << llist1;
    
    Node* llist2 = nullptr;
    push_front( 2, llist2 );
    push_front( 3, llist2 );
    push_front( 6, llist2 );
    
    cout << "L2: " << llist2;
    
    Node* aNode = searchNode( 7, llist1 );
    cout << "Target: " << aNode;
    
    cout << "Splicing L2 at target in L1" << endl;
    spliceLList( aNode, llist2 );
    cout << "L1: " << llist1;
    cout << "L2: " << llist2;

    
    cout << "\nPart two" << endl << endl;
    
    Node* llist3 = nullptr;
    push_front( 6, llist3 );
    push_front( 5, llist3 );
    push_front( 4, llist3 );
    push_front( 2, llist3 );
    push_front( 3, llist3 );
    push_front( 2, llist3 );
    push_front( 3, llist3 );
    push_front( 2, llist3 );
    push_front( 1, llist3 );
    
    cout << "Target: " << llist3;
    
    Node* llist4 = nullptr;
    push_front( 1, llist4 );
    
    cout << "\nAtempt match: " << llist4;
    Node* llist5 = searchList(llist3, llist4);
    cout << llist5;
    
    Node* llist6 = nullptr;
    push_front( 9, llist6 );
    push_front( 3, llist6 );

    cout << "\nAtempt match: " << llist6;
    Node* llist7 = searchList(llist3, llist6);
    cout << llist7;
    
    Node* llist8 = nullptr;
    push_front( 3, llist8 );
    push_front( 2, llist8 );
    
    cout << "\nAtempt match: " << llist8;
    Node* llist9 = searchList(llist3, llist8);
    cout << llist9;

    Node* llist10 = nullptr;
    push_front( 6, llist10 );
    push_front( 5, llist10 );
    push_front( 4, llist10 );
    push_front( 2, llist10 );
    
    cout << "\nAtempt match: " << llist10;
    Node* llist11 = searchList(llist3, llist10);
    cout << llist11;
    
    Node* llist12 = nullptr;
    push_front( 4, llist12 );
    push_front( 2, llist12 );
    push_front( 3, llist12 );
    push_front( 2, llist12 );
    
    cout << "\nAtempt match: " << llist12;
    Node* llist13 = searchList(llist3, llist12);
    cout << llist13;
    
    Node* llist14 = nullptr;
    push_front( 7, llist14 );
    push_front( 6, llist14 );
    push_front( 5, llist14 );
    
    cout << "\nAtempt match: " << llist14;
    Node* llist15 = searchList(llist3, llist14);
    cout << llist15;
    
}