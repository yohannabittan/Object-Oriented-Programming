/*
Programmer: Yohann Abittan
netID: yaa243
this program simulates an orchestra
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Instrument {
public:
	virtual void makeSound(){}
private:
};
class Percussion :public Instrument {
	virtual void makeSound() {}
};
class Cymbal :public Percussion {
	void makeSound() { cout << "tss" << endl; }
};
class Drum :public Percussion {
	void makeSound() { cout << "boom" << endl; }
};
class Brass :public Instrument {
private:
	int mouthPiece;
public:
	virtual void makeSound(){}
};
class Trumpet :public Brass {
private:
	int mouthPiece;
public:
	Trumpet(int mouthPiece) : mouthPiece(mouthPiece) {}
	void makeSound() { cout << "trump" << endl; }
};
class Trombone :public Brass {
private:
	int mouthPiece;
public:
	Trombone(int mouthPiece) : mouthPiece(mouthPiece) {}
	void makeSound() { cout << "praam" << endl; }
};
class String :public Instrument {
private:
	int pitch;
public:
	virtual void makeSound(){}
};
class Cello :public String {
private:
	int pitch;
public:
	Cello(int pitch) : pitch(pitch) {}
	void makeSound() { cout << "plang" << endl; }
};
class Violin :public String {
private:
	int pitch;
public:
	Violin(int pitch) : pitch(pitch) {}
	void makeSound() { cout << "pling" << endl; }
};

class MILL {
public:
	Instrument* loanOut() {
		Instrument* tmp;
		for (Instrument*& iPtr : inst) {
			if (iPtr != nullptr) {
				tmp = iPtr;
				iPtr = nullptr;
				return tmp;
			}
		}
		return NULL;
	}
	void receiveInstr(Instrument& instrument) {
		Instrument* iPtr = &instrument;
		for (size_t i = 0; i < inst.size(); i++) {
			if (inst[i] == nullptr) {
				inst[i] = iPtr;
				return;
			}
		}
		inst.push_back(iPtr);
	}
	void dailyTestPlay() {
		for (Instrument* iPtr : inst) {
			if (iPtr != nullptr) {
				iPtr->makeSound();
			}
		}
	}
private: vector<Instrument*> inst;
};




class Musician {
public:
	Musician() : instr(NULL) {}
	void acceptInstr(Instrument & i) { instr = &i; }
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if (instr)
			instr->makeSound();
		else
			cerr << "have no instr\n";
	}
private:
	Instrument* instr;
};

class Orch {
private:
	vector<Musician*> musicians;
public:
	void play() { 
		for (Musician* musician : musicians) {
			musician->testPlay();
		}
	}
	void addPlayer(Musician& player) {
		Musician* mPtr = &player;
		musicians.push_back(mPtr);
	}
};

// PART ONE
int main()
{
	string nothing;
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(violin);
	mill.receiveInstr(trpt);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
	cin >> nothing;
} // main
