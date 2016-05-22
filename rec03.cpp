#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Sandwhich {

private:
	const int bread=2;
	int cheese;
	int tomato;
	float mayo;
	float mustard;
public:
	Sandwhich(int tomatoNumber = 2,int cheeseNumber=1, float mustardAmount = 0.5,float mayoAmount=0.1)
		: tomato(tomatoNumber),cheese(cheeseNumber), mustard(mustardAmount), mayo(mayoAmount){}
	void display() const {//made constant because the display method must not change any data
		cout << "bread: " << bread << " cheese: " << cheese << " tomato:" << tomato << " mayo:" << mayo << "oz mustard: " << mustard << "oz" << endl;
	}
	
	int getTomato()const {return tomato;}
	int getCheese()const {return cheese;}
	float getMustard()const {return mustard;}
	float getMayo()const {return mayo;}

	void setTomato(const int& newTomato) {tomato = newTomato;}
	void setCheese(const int& newCheese) {cheese = newCheese;}
	void setMustard(const float& newMustard) {mustard = newMustard;}
	void setMayo(const float& newMayo) {mayo = newMayo;}

	};
class sandwhichTruck {
private: vector<Sandwhich> firstTruck;
public:
void insertSandwhich(const Sandwhich& aSandwhich) {
		firstTruck.push_back(aSandwhich);
	}
void displayTruck()const {
	for (const Sandwhich aSandwhich : firstTruck) {
		aSandwhich.display();
	}
}
float getMustard(int i)const {
	return firstTruck[i].getMustard();
}
};
int main() {
	string nothing;
	Sandwhich aSandwhich;
	Sandwhich aSandwhich2;
	Sandwhich aSandwhich3;
	Sandwhich aSandwhich4;
	aSandwhich2.setMustard(0);
	aSandwhich3.setCheese(2);
	

	sandwhichTruck firstTruck;
	firstTruck.insertSandwhich(aSandwhich);
	firstTruck.insertSandwhich(aSandwhich2);
	firstTruck.insertSandwhich(aSandwhich3);
	firstTruck.insertSandwhich(aSandwhich4);
	firstTruck.displayTruck();

	cout <<"There is "<< firstTruck.getMustard(1) <<" ounces of mustard in this sandwhich"<<endl;
	

	cin>>nothing;
}