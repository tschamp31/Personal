//Tyler Champagne
//SER 221
//Assignment 3
//11/1/14
//1.0
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

string reversestring(string input)
{
	int i, o, stringlength;//Declaration of Variables
	stringlength = input.size();
	char stringprocessor[stringlength], temp[1];
	string output;

	for(i = 0; i <= stringlength; i++)//Converts to character array
	{
		stringprocessor[i] = input[i];
	}

	for(i = 0, o = stringlength - 1; o > stringlength/2 ; i++, o--)//reverses the character array
	{
		temp[0] = stringprocessor[i];
		stringprocessor[i] = stringprocessor[o];
		stringprocessor[o] = temp[0];
	}
	output = string(stringprocessor);//Turns array into a string

	return output;
}

int main(int argc, char const *argv[])
{
	string inputstring, outputstring;//Declaration of Variables

	cout << "What is the string you would like to have reversed?" << endl;//Input
	getline(cin, inputstring);

	outputstring = reversestring(inputstring);//Method to reverse the string

	cout << "The string reversed is: " << outputstring << endl;//Reads the output
	system("PAUSE");

	return 0;
}
