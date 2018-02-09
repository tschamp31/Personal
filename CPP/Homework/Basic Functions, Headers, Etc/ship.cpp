//Tyler Champagne
//SER 221
//Assignment 3
//11/1/14
//1.0
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Ship//Class
{
	protected://Variables
		string name;
		int year;
	public://Default Constructor, Mutators, Accessors
		Ship(string inputName = "",int inputYear = 0);

		string getName()
		{
			return this->name;
		}
		int getYear()
		{
			return this->year;
		}
		void reset()
		{
			this->name = "";
			this->year = 0;
		}
		void set(string inputName, int inputYear)
		{
			this->name = inputName;
			this->year = inputYear;
		}
		void print()
		{
			cout << "Name: " << this->name << "\nYear Of Construction: "  << this->year << endl;
		}
};
		
Ship::Ship(string inputName, int inputYear)//Non-default constructor
{
	this->name = inputName;
	this->year = inputYear;
}


class CruiseShip: public Ship//Class with extension
{
	protected://Variables
		int maxPassengers;
	public://Default Constructor, Accessors, Mutators
		CruiseShip(int inputMaxPasse = 0, string inputName = "");
		int getMaxPasse()
		{
			return this->maxPassengers;
		}
		void reset()
		{
			this->name = "";
			this->maxPassengers = 0;
		}
		void set(int inputMaxPasse, string inputName)
		{
			this->name = inputName;
			this->maxPassengers = inputMaxPasse;
		}
		void print()
		{
			cout << "Name: " << this->name << "\nMax Passengers: " << this->maxPassengers << endl;
		}
};

CruiseShip::CruiseShip(int inputMaxPasse, string inputName)//Non-default constructor
{
	this->maxPassengers = inputMaxPasse;
	this->name = inputName;
}

class CargoShip: public Ship//Class with extension
{
	protected://Variable
		int cargoWeight;
	public://Default Constructor, Accessors, Mutators
		CargoShip(int inputCargoWeight = 0, string inputName = "");
		int getCargoWeight()
		{
			return this->cargoWeight;
		}
		void reset()
		{
			this->name = "";
			this->cargoWeight = 0;
		}
		void set(int inputCargoWeight, string inputName)
		{
			this->name = inputName;
			this->cargoWeight = inputCargoWeight;
		}
		void print()
		{
			cout << "Name: " << this->name << "\nWeight Max: " << this->cargoWeight << endl;
		}
};

CargoShip::CargoShip(int inputCargoWeight, string inputName)//Non default constructor
{
	this->cargoWeight = inputCargoWeight;
	this->name = inputName;
}

int main(int argc, char const *argv[])
{
	string inputstring, inputnumber;//Declaration of Variables
	bool valid = false;
	int myNumber = 0;

	Ship ship2;//Declaration of classes with default constructor
	CruiseShip crShip2;
	CargoShip caShip2;

///////////////////////////////Input with constructors/////////////////////////////////////////
	cout << "Name of the cargo ship?" << endl;
	getline(cin, inputstring);
	//Checks for numerical input////
	do
	{
	cout << "What is the max weight capacity of this cargo ship?" << endl;
	getline(cin, inputnumber);
	stringstream myStream(inputnumber);
	   if (myStream >> myNumber)
	     break;
	   cout << "Invalid Number: " << inputnumber << endl;
	}while(true);
	////////////////////////////////
	CargoShip caShip1(myNumber,inputstring);
	valid = false;

	cout << "Name of the cruise ship?" << endl;
	getline(cin, inputstring);
	do
	{
	cout << "What is the max capacity of this cruise ship?" << endl;
	getline(cin, inputnumber);
	stringstream myStream(inputnumber);
	   if (myStream >> myNumber)
	     break;
	   cout << "Invalid Number: " << inputnumber << endl;
	}while(true);
	CruiseShip crShip1(myNumber,inputstring);
	valid = false;

	cout << "Name of the regular ship?" << endl;
	getline(cin, inputstring);
	do
	{
	cout << "What year was this ship created?" << endl;
	getline(cin, inputnumber);
	stringstream myStream(inputnumber);
	   if (myStream >> myNumber)
	     break;
	   cout << "Invalid Number: " << inputnumber << endl;
	}while(true);
	Ship ship1(inputstring,myNumber);
	valid = true;

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Input with mutators//////////////////////////////////////////

	cout << "Name of the cargo ship?" << endl;
	getline(cin, inputstring);
	do
	{
	cout << "What is the max weight capacity of this cargo ship?" << endl;
	getline(cin, inputnumber);
	stringstream myStream(inputnumber);
	   if (myStream >> myNumber)
	     break;
	   cout << "Invalid Number: " << inputnumber << endl;
	}while(true);
	caShip2.set(myNumber,inputstring);
	valid = false;

	cout << "Name of the cruise ship?" << endl;
	getline(cin, inputstring);
	do
	{
	cout << "What is the max capacity of this cruise ship?" << endl;
	getline(cin, inputnumber);
	stringstream myStream(inputnumber);
	   if (myStream >> myNumber)
	     break;
	   cout << "Invalid Number: " << inputnumber << endl;
	}while(true);
	crShip2.set(myNumber,inputstring);
	valid = false;

	cout << "Name of the regular ship?" << endl;
	getline(cin, inputstring);
	do
	{
	cout << "What year was this ship created?" << endl;
	getline(cin, inputnumber);
	stringstream myStream(inputnumber);
	   if (myStream >> myNumber)
	     break;
	   cout << "Invalid Number: " << inputnumber << endl;
	}while(true);
	ship2.set(inputstring,myNumber);
	valid = true;
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Print Functions//////////////////////////////
	ship1.print();
	cout << "\n" << endl;
	crShip1.print();
	cout << "\n" << endl;
	caShip1.print();
	cout << "\n" << endl;
	ship2.print();
	cout << "\n" << endl;
	crShip2.print();
	cout << "\n" << endl;
	caShip2.print();
	cout << "\n" << endl;

	system("PAUSE");//Pauses the program waiting for user response
	return 0;
}