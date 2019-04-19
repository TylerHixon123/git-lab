/****************************************
*
*	Tyler Hixon
*	CS 2400 
*	April 16, 2019
*	Lab 13
*	This program is a tollbooth where it tracks when cars have passed and if they paid the toll or not
*
*
*
******************************************/

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Tollbooth{
	public:
		//default constructor
		Tollbooth();			//sets car to 0,answer to *,amount to 0
		//getters
		int getCars();			//accesses int cars
		double getAmount();		//accesses double amount
		string getAnswer();		//accesses string answer
		//setters
		void payinCar();		//updates cars and amount variable
		void nopayCar();		//updates just cars variable
		void setAnswer(string ans);	//updates answer variable
		//helper functions
		void display(ostream& fileout);	//displays the total number of cars and amount of money
	
	private:
		int cars;			//number of cars passed variable
		double amount;			//amount of money collected variable	
		string answer;
	};




int main(){
	Tollbooth t;		//intializes Tollbooth class
	string answer;		//intializes string answer
	cout << "P - paid    N - Not paid    Q - Quit:" << endl;
	cin >> answer;		//inputs the answer into answer
	t.setAnswer(answer);	//sets answer
	while(t.getAnswer() != "q"){	//this is a while loop, it loops, there is also a condition that it doesn't equal q
		if(t.getAnswer() == "p"){	//checks to see if answer equals p
			t.payinCar();	//cals payincar function
		}	//end of if statements
		if(t.getAnswer() == "n"){	//checks to see if answer equals n
			t.nopayCar();	//calls nopaycar function
		}	//end of if statement
		if(t.getAnswer() == "q"){	//checks to see if answer equals q
			exit(1);	//exits
		}	//end of if statement
		cout << "P - paid    N - Not paid    Q - Quit:" << endl;	//shows up on screen to user
		cin >> answer;
		t.setAnswer(answer);
	}//this is the end of the while loop
	

	t.display(cout);		//display
}	//end of main

Tollbooth::Tollbooth(){			//default constructor
	cars = 0;
	amount = 0;
	answer = "***";
}

void Tollbooth::payinCar(){		//updates car and amount
	cars = cars + 1;		//adds 1 to cars
	amount = amount + 0.50;		//adds 0.5 to amount 
}

void Tollbooth::nopayCar(){		//updates car
	cars = cars + 1;		//adds 1 to cars
}

void Tollbooth::setAnswer(string ans){	//sets the answer
	answer = ans;			//sets string answer to ans
}

int Tollbooth::getCars(){		//gets the cars
	return cars;			//returns cars variable
}

double Tollbooth::getAmount(){		//gets the amount
	return amount;			//returns the amount
}

string Tollbooth::getAnswer(){		//gets the answer variable
	return answer;			//returns answer
}

void Tollbooth::display(ostream& fileout){	//displays the output and the total number of cars and amount of money$$
	cout << "Total number of cars: " << cars << endl;
	cout << "Total amount collected: $" << amount << endl;
}






