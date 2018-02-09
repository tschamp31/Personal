#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int input, position; //Declares the integer
	cout << "Enter an integer to calculate: "<<endl; //Reads out the prompt
	cin>>input;//Takes in the input
	vector<int> Fibonacci(input);//Declares vector
	position = 0;//Sets position to 0
	Fibonacci[0] = 0;//Sets the seed
	Fibonacci[1] = 1;//Sets the seed
	while(input != position)//Recursion to run until it runs X times
	{
		Fibonacci[position + 2] = Fibonacci[position] + Fibonacci[position + 1]; //Runs the formula
		position++;//Increases position
	}
	cout << Fibonacci[input] << endl;//Reads final number
	return 0;
}