#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	int number; //Declares the variables
	string professor, name, food, adjective, color, animal; //Declares the variables

	cout << "Professors name: " << endl; //Asks for input
	cin >> professor;
	cout << "Your name: " << endl; //Asks for input
	cin >> name;
	cout << "Food: " << endl; //Asks for input
	cin >> food;
	cout << "Adjective: " << endl; //Asks for input
	cin >> adjective;
	cout << "Color: " << endl; //Asks for input
	cin >> color;
	cout << "Animal: " << endl; //Asks for input
	cin >> animal;
	cout << "Number(Between 100-120): " << endl; //Asks for input
	cin >> number;


	cout << "Dear Professor " << professor << //Declares the madlibs paragraph and also formatted the cout in the paragraph order.
	"\n\nI am sorry that I am unable to turn in my homework at this time. \n" <<
	"First, I ate a rotten " << food << ", which made me turn " << color << " and \n" <<
	"extremely ill. I came down with a fever of " << number << "\n" <<
	"Next, my " << adjective << " pet " << animal << " must have smelled the remains\n" <<
	"of the " << food << " on my homework, because he ate it. I am currently \n" <<
	"rewriting my homework and hope you will accept it late. \n\n" <<

	"Sincerely, \n" <<
	name << endl;

	return 0; //Ends the program
}