//Tyler Champagne
//Ser 221
//Version 1
//11/20/14

#include <iostream>//Include files to make the program function
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

void convert(string inputName, string outputName) //Creates the function
{
	string leftArrow, rightArrow, line, leftArrowReplacement, rightArrowReplacement; //Delcares basic variables used in the function
	string::size_type s = 0;

	leftArrow = "<";
	rightArrow = ">";
	leftArrowReplacement = "&lt;";
	rightArrowReplacement = "&gt;";

	ofstream outputFile;
	ifstream inputFile;

	outputFile.open(outputName.c_str());//Opens the files
	inputFile.open(inputName.c_str());

	if(inputFile.fail())//Declares if the file opening failed
	{
		cout << "Input file opening failed.\n" << endl;
		exit(1);
	}

	outputFile << "<PRE>" << endl; //Prints out the pre

	while(!inputFile.eof())//Runs until the end of the file
	{
		while(getline(inputFile, line)) //Continues to retrieves lines while possible
		{

			while((s = line.find(leftArrow,s)) != string::npos) //Checks for the left arrow
			{
				line.replace(s, leftArrow.size(), leftArrowReplacement); //Replaces it if found
				s += leftArrowReplacement.size(); //Sets the new size so positioning can change
			}

			s = 0; //Resets the positioning

			while((s = line.find(rightArrow,s)) != string::npos)//Checks for the right arrow
			{
				line.replace(s, rightArrow.size(), rightArrowReplacement);//Replaces it if found
				s += rightArrowReplacement.size();//Sets the new size so positioning can change
			}
			s = 0;//Resets the positioning

			outputFile << "\t" << line << endl;//Prints out the changes to the line to the new file.
		}
	}
	outputFile << "</PRE>" << endl;//Prints out the ending of pre

	inputFile.close();//closes the files
	outputFile.close();
}

int main(int argc, char const *argv[])
{
	string inputName,outputName;//Delcares string names
	inputName = "test.cpp";
	outputName = "test.html";

	convert(inputName,outputName);

	return 0;
}