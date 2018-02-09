#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int humanTurn(int humanTotalScore)
{
	int newhumanscore, totalrolls, roll;//Declares the variables
	char answer;//Declares the variables

	totalrolls = 0;//Declares the variables
	newhumanscore = humanTotalScore;//Declares the variables
	answer = 'r';//Declares the variables

	while(answer == 'r' || answer == 'R')
	{
		cout << "(R)oll or (H)old?: " << endl;
		cin >> answer;

		if(answer == 'H' || answer == 'h')
		{
			newhumanscore += totalrolls; //Adds the total rolls to the new score
			cout << "Your score is now " << newhumanscore << endl;
			return newhumanscore;//Returns the new score
		}

		roll = rand() % 6 + 1; //rolls the dice
		totalrolls += roll; //Totals the rolls
		cout << "You rolled a " << roll << endl; //Declares the roll

		if(roll == 1)
		{
			cout << "Your turn ends!" << endl;
			return newhumanscore;//Returns the new score
		}
	}
}

int computerTurn(int computerTotalScore)
{
	int newcomputerscore, roll, totalrolls;//Declares the variables
	newcomputerscore = computerTotalScore;//Declares the variables
	totalrolls = 0;//Declares the variables

	while(totalrolls <= 20)
	{
		roll = rand() % 6 + 1;
		totalrolls += roll;

		if(roll == 1)
		{
			cout << "The computer rolled a 1 and its turn ends." << endl;
			cout << "The computer's score is " << computerTotalScore << endl;
			return newcomputerscore;//Returns the new score
		}
		if(totalrolls >= 20)
		{
			newcomputerscore += totalrolls;
			cout << "The computer's score is " << computerTotalScore << endl;
			return newcomputerscore;//Returns the new score
		}
	}

}

int main()
{
	int humanTotalScore, computerTotalScore;//Declares the variables
	bool winner = false;//Declares the variables
	humanTotalScore = 0;//Declares the variables
	computerTotalScore = 0;//Declares the variables

	while(winner != true)
	{
		humanTotalScore = humanTurn(humanTotalScore);//Runs the method and sets the new score
		computerTotalScore = computerTurn(computerTotalScore);//Runs the method and sets the new score

		if(computerTotalScore >= 100)//Checks to see if the computer wins
		{
			cout << "computer wins!" << endl;
			winner = true;
		}
		if(humanTotalScore >= 100)//Checks to see if the human wins
		{
			cout << "human wins!" << endl;
			winner = true;
		}
	}
	return 0;
}