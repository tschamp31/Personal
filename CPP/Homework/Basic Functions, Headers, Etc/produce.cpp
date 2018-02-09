//Tyler Champagne
//Ser 221
//Assignment 2


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

class BoxOfProduce//Declares the class
{
private:
	vector<string> fruitBundle;
	vector<string> vegetableBundle;
public:
	BoxOfProduce()//Runs the constructor including the randomization
	{
		int boxMax, FruOrVeg, randomVeg, fruSize, vegSize; //Declares the variables
		boxMax = 0;
		fruSize = 0;
		vegSize = 0;
		string possibleFruits[] = {"Kiwi"};
		string possibleVegetables[] = {"Broccoli", "Tomato", "Kale", "Tomatillo"};

		while(boxMax != 3)//Fills the box to three items
		{
			FruOrVeg = rand() % 2;//Randomizes
			randomVeg = rand() % 4;

			if(FruOrVeg == 0)//Decides whether fruit or vegi then randomized which vegi
			{
				this->fruitBundle.push_back(possibleFruits[0]);
			}
			else if(FruOrVeg == 1)
			{
				this->vegetableBundle.push_back(possibleVegetables[randomVeg]);
			}
			boxMax++;
		}
	}
	void printBundle()//Prints out the contents of the fruit/vegi bundles
	{
		cout << "Fruits: ";
		for(int i = 0; i != fruitBundle.size(); i++)
		{
			cout << this->fruitBundle[i] << " ";
		}
		cout << endl;
		cout << "Vegetables: ";
		for(int i = 0; i != vegetableBundle.size(); i++)
		{
			cout << this->vegetableBundle[i] << " ";
		}
		cout << endl;

	}
	vector<string> getFruits()//Retrives the vector of fruits
	{
		return this->fruitBundle;
	}
	vector<string> getVegetables()//Retrives the vector of vegis
	{
		return this->vegetableBundle;
	}
	void setFruits(string fruitBundleInput, int position)//Sets a specific fruit and position
	{
		this->fruitBundle[position] = fruitBundleInput[position];
	}
	void setVegetables(string vegetableBundleInput, int position)//SEts a sepcific vegi and position
	{
		this->vegetableBundle[position] = vegetableBundleInput;
	}
};

int main(int argc, char const *argv[])
{
	string answerString;//Declares the variables
	char answer;
	int option, boxcount, position;
	string::size_type s = 0;

	while(true)//Loops until break
	{
	BoxOfProduce box1;//Constructs class

	cout << "The box's contents are as below" << endl;//displays the fruits
	box1.printBundle();

	cout << "Are the box's contents okay?(Y/N): " << endl;//Asks if they are okay
	cin >> answer;
	if(answer == 'Y' || answer == 'y') break;//If so then it ends the loop
	cout << endl;

		while (true)//Runs until it retrieves a digit answer.
		{
			cout << "Would you like to change the fruits or vegetables?(Fruit = 0, Vegetable = 1): " << endl;//Retrvies vegi/fruit answer
			cin.ignore();
			getline(cin, answerString);

			stringstream myStream(answerString);//Converts the class answer to a stream
			if (myStream >> option && (option == 0 || option == 1)) break;//Converts the stream to a possible valid number
			cout << "Invalid input, please enter numbers only." << endl;
		}
		while(true)//Loops until break
		{
			while (true)//Runs until it retrieves a digit answer.
			{
				cout << "Which position would you like changed? (Vegetable: x0 x1 x2): " << endl;//Retrvies position answer
				cin.ignore();
				getline(cin, answerString);

				stringstream myStream(answerString);//Converts the class answer to a stream
				if (myStream >> position && (position == 0 || position == 1 || position == 2)) break;//Converts the stream to a possible valid number
				cout << "Invalid input, please enter numbers only." << endl;
			}
			while(true)//Loops until break
			{
				s = 0;
				cout << "What would you like to replace that position with?(Fruit: Kiwi)(Vegetable:Broccoli, Tomato, Kale, Tomatillo): " << endl;//Gives string options to replace
				cin >> answerString;

				if(option == 0)//If they chose fruit earlier it checks to make sure kiwi is entered
				{
					if((s = answerString.find("Kiwi")) != string::npos) break;
				}
				else if(option == 1)//If they chose vegi it checks to see if it's an acceptable vegi answer
				{
					if((s = answerString.find("Broccoli")) != string::npos) break;
					else if((s = answerString.find("Tomato")) != string::npos) break;
					else if((s = answerString.find("Kale")) != string::npos) break;
					else if((s = answerString.find("Tomatillo")) != string::npos) break;
				}
				cout << "Invalid input, please enter numbers only." << endl;
			}
			if(option == 0)//If all checks out and they chose fruit it's added
			{
				box1.setFruits(answerString,position);
			}
			if(option == 1)//If all checks out and they chose vegi it's added
			{
				box1.setVegetables(answerString,position);
			}

			cout << endl;
			box1.printBundle();//Reprints the contents
			cout << "Is this final box okay?" << endl;//Asks if the new box is okay
			cin >> answer;
			if(answer == 'Y' || answer == 'y') break;//Ends the box editing
		}
	cout << endl;
	cout << "Are you done making boxes?" << endl;//Asks if the user wants to make another box
	if(answer == 'Y' || answer == 'y') break;//Ends it if so
	boxcount++;
	}
	cout << "Total boxes sent: " << boxcount << endl;//Displays end box count
	return 0;
}