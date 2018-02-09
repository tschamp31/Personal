#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int decider(char Player1, char PlayerR) //Setup for checking who wins
{
	if ((Player1 == 'S' || Player1 == 's') && (PlayerR == 'P' || PlayerR == 'p')) //scissors win Player 1 Wins
	{
		return 1;
	}
	if ((Player1 == 'R' || Player1 == 'r') && (PlayerR == 'S' || PlayerR == 's')) //Rock wins Player 1 Wins
	{
		return 1;
	}
	if ((Player1 == 'P' || Player1 == 'p') && (PlayerR == 'R' || PlayerR == 'r')) //Paper wins Player 1 Wins
	{
		return 1;
	}
	if ((Player1 == 'S' || Player1 == 's') && (PlayerR == 'R' || PlayerR == 'r')) //Rock wins Player 2 Wins
	{
		return 2;
	}
	if ((Player1 == 'R' || Player1 == 'r') && (PlayerR == 'P' || PlayerR == 'p')) //Paper wins Player 2 wins
	{
		return 2;
	}
	if ((Player1 == 'P' || Player1 == 'p') && (PlayerR == 'S' || PlayerR == 's')) //scissors win Player 2 Wins
	{
		return 2;
	}
	else
	{
		return 0; //returns an error or tie
	}
}


int main()
{
	string winner; //Declares the variables
	char Player1, Player2, answer;//Declares the variables
	int winnerint, P1S, P2S;//Declares the variables

	P1S = 0;//Declares the variables
	P2S = 0;//Declares the variables
	answer = 'y';//Declares the variables

	while(answer == 'y' || answer == 'Y') //Checks to see the response if the player wants to play
	{
		cout << "Player 1: Please enter either (R)ock, (P)aper, or (S)cissors: " << endl; //Asks for input player 1
		cin >> Player1;
		cout << "Player 2: Please enter either (R)ock, (P)aper, or (S)cissors: " << endl; //Asks for input player 2
		cin >> Player2;

		winnerint = decider(Player1, Player2); // Returns who wins

		switch(winnerint) //swtiches to the winner
		{
			case 1: //Declares player 1 wins and adds a point
				winner = "\nPlayer 1";
				P1S += 1;
				break;
			case 2: //Declares player 2 wins and adds a point
				winner = "\nPlayer 2";
				P2S += 1;
				break;
			case 0: //Declares no one wins
				winner = "\nNo one ";
				break;
		}

		cout << winner << " wins.\n" << endl; //Declares the winner

		cout << "Scores after this play:" << endl; //Declares the scores
		cout << "\tPlayer 1: " << P1S << endl;
		cout << "\tPlayer 2: " << P2S << endl;

		cout << "Thanks!!\n" << endl;

		cout << "Play again? Y/y continues, other quits: " << endl; //Asks if the player wants to play again.
		cin >> answer;
		cout << endl;
	}
	return 0;
}