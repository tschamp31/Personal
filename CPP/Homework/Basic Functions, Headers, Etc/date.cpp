//Tyler Champagne
//Ser 221
//Version 1
//11/20/14

#include <iostream> //Includes to cause the program to function
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class Date//Class Date
{
private:
	int Day;
	int Month;
	int Year;
public:
	Date(int Day, int Month,int Year)//Constructors
	{
		if(Day < 1 || Day > 31)
		{
			throw "Invalid Day";
		}
		if(Month < 1 || Month > 12)
		{
			throw "Invalid Month";
		}
		this->Day = Day;
		this->Month = Month;
		this->Year = Year;
	}
	int getDay()//Retrieves the day
	{
		return this->Day;
	}
	int getMonth()//Retrieves the month
	{
		return this->Month;
	}
	int getYear()//Retrieves the year
	{
		return this->Year;
	}
	void setDay(int inputDay)//Sets the day
	{
		if(inputDay < 1 || inputDay > 31)
		{
			throw "Invalid Day";
		}
		else
		{
			this->Day = inputDay;
		}
	}
	void setMonth(int inputMonth)//Sets the month
	{
		if(inputMonth < 1 || inputMonth > 12)
		{
			throw "Invalid Month";
		}
		else
		{
			this->Month = inputMonth;
		}
	}
	void setYear(int inputYear)//Sets the year
	{
		this->Year = inputYear;
	}
	void printLongDateUS()//Prints out xxxxxxx xx, xxxx
	{
		cout << monthToText() << " " << this->Day << ", " << this->Year << endl;
	}
	void printLongDateEU()//Prints out xx xxxxxxx xxxx
	{
		cout << this->Day << " " << monthToText() << " " << this->Year << endl; 
	}
	void printShortDate()//Prints out xx/xx/xx
	{
		string year = static_cast<ostringstream*>( &(ostringstream() << this->Year) )->str();

		cout << this->Month << "/" << this->Day << "/" << year[2] << year[3] << endl;
	}
	string monthToText()//Converts the numerical date to a text month
	{
		switch(this->Month)
		{
			case 1:
				return "January";
				break;
			case 2:
				return "Febuary";
				break;
			case 3:
				return "March";
				break;
			case 4:
				return "April";
				break;
			case 5:
				return "May";
				break;
			case 6:
				return "June";
				break;
			case 7:
				return "July";
				break;
			case 8:
				return "August";
				break;
			case 9:
				return "September";
				break;
			case 10:
				return "October";
				break;
			case 11:
				return "November";
				break;
			case 12:
				return "December";
				break;
		}
	}
};

int main(int argc, char const *argv[])
{
	Date date(25,12,2013);//Constructs the date class
	int day, month, year;//Declares the variables

	date.printShortDate();//First test with default construction
	date.printLongDateEU();
	date.printLongDateUS();

	cout << endl;

	date.setMonth(8); //Setups new variables for the Date class
	date.setYear(1879);
	date.setDay(5);
	date.printShortDate();//Prints out the new set of date class information
	date.printLongDateEU();
	date.printLongDateUS();

	cout << "Enter a valid day (1-31): " << endl; //Takes in user input
	cin >> day;
	cout << "Enter a valid month(1-12): " << endl;
	cin >> month;
	cout << "Enter a random year: " << endl;
	cin >> year;

	date.setMonth(month);//Sets the new user input
	date.setYear(year);
	date.setDay(day);

	cout << endl;

	cout << "Enter an invalid day (<1 or >31) to cause an exception: " << endl; //Causes an exception to end the program
	cin >> day;
	
	return 0;
}