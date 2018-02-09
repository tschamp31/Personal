#include <iostream>//Include files to make the program function
#include <cstdlib>
#include <string>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;//Namespace

bool isBalanced(const string& expression)//Program decides whether it's () [] and not (]) or [)] or ) or ].
{
	stack<char> infix;//Declares the stack 

	bool answer, processed, left;//Declares bool variables
	answer = false;
	processed = false;

	char leftPa, rightPa, leftBr, rightBr, add, subtract, multiply, divide;//Declare char variables
	vector<char> preprocessed(expression.begin(),expression.end());

	int i;//Declares int variable

	leftPa = '(';//Defines the declared chars
	rightPa = ')';
	leftBr = '[';
	rightBr = ']';
	add = '+';
	subtract = '-';
	multiply = '*';
	divide = '/';

	for(i = 0; i != preprocessed.size(); i++)//Runs through the line to check if balanced
	{
		if(preprocessed[i] == leftPa || preprocessed[i] == leftBr)
		{
			infix.push(preprocessed[i]);
		}
		else if(preprocessed[i] == rightPa || preprocessed[i] == rightBr)
		{
			if(infix.empty())
			{
				answer = false;
				break;
			}
			else if(infix.top() == leftPa && preprocessed[i] == rightPa)
			{
				infix.pop();
				answer = true;
			}
			else if(infix.top() == leftBr && preprocessed[i]  == rightBr)
			{
				infix.pop();
				answer = true;
			}
			else
			{
				infix.pop();
				answer = false;
				break;
			}
		}
	}

	preprocessed.clear();//Deconstructs the stack
	return answer;//Returns the bool
}

int GetOperatorWeight(char input)//Simulates pemdas. Making that multiplcation and division is done before addition and subtraction
{
	int weight;
	weight = -1;

	switch(input)
	{
		case '+'://PEMD(AS)
		case '-':
			weight = 1;
			break;
		case '*'://PE(MD)AS
		case '/':
			weight = 2;
			break;
	}

	return weight;
}
 
int Priority(char input1, char input2)//Simulates pemdas. Making that multiplcation and division is done before addition and subtraction
{
	int Weight1 = GetOperatorWeight(input1);//Checks the operator weight
	int Weight2 = GetOperatorWeight(input2);
	
	return Weight1 > Weight2 ? true: false;//Returns the priority
}

string infix_To_Postfix(const string& expression)
{
	string postfixString,InfixString;//Declares the strings
	postfixString = "";
	InfixString = "";

	stack<char> postfix;//Declares the stack

	char add, subtract, multiply, divide;//Declares the char variables
	vector<char> preprocessed(expression.begin(),expression.end());

	int i;//Declares int

	add = '+';//Defines the chars
	subtract = '-';
	multiply = '*';
	divide = '/';


	for(i = 0; i != preprocessed.size(); i++)//Runs through the line to reorganize it into a postfix design
	{
		if(preprocessed[i] == add || preprocessed[i] == subtract || preprocessed[i] == multiply || preprocessed[i] == divide)
		{
			while(!postfix.empty() && postfix.top() != '(' && Priority(postfix.top(), preprocessed[i]))
			{
				postfixString += postfix.top();
				postfix.pop();
			}
			postfix.push(preprocessed[i]);
		}
		else if(preprocessed[i] >= '0' && preprocessed[i] <= '9')//checks to see if it's a number
		{
			postfixString += expression[i];
		}
		else if(preprocessed[i] == '(')//Checks for brackets
		{
			postfix.push(preprocessed[i]);
		}
		else if(preprocessed[i] == ')')//Checks for brackets
		{
			while(!postfix.empty() && postfix.top() != '(')
			{
				postfixString += postfix.top();
				postfix.pop();
			}
			postfix.pop();
		}
	}

	while(!postfix.empty()) //while the stack isnt empty it adds the top of the stack to the string
	{
		postfixString += postfix.top();
		postfix.pop();
	} 

	preprocessed.clear();//Deconstructs the stack
	return postfixString;
}

double evaluate(const string& expression)//Returns the value of the postfix sentence
{
	double answer, number1, number2, size;//Declares doubles

	stack<double> evaluate;//Declares stack

	int i = 0;//Declares int

	vector<char> postfix(expression.begin(),expression.end());


	while(i < expression.size())//While the size of the line is greater than the counter
	{

		if(isdigit(postfix[i]))//checks to see if it's a digit
		{
			evaluate.push(postfix[i]-'0');//Adds it to the stack if so.
		}
		else
		{
			if(!evaluate.empty())//If the stack is not empty
			{
				number1 = evaluate.top();//It takes off the top of the stack
				evaluate.pop();
				number2 = evaluate.top();//Takes a second number off the stack
				evaluate.pop();
				switch(postfix[i])//Processes those two numbers based on the operator then adds it to the stack again
				{
					case '*':
						evaluate.push(number2 * number1);
						break;
					case '/':
						evaluate.push(number2 / number1);
						break;
					case '+':
						evaluate.push(number2 + number1);
						break;
					case '-':
						evaluate.push(number2 - number1);
						break;
					default:
						evaluate.push(0);
						break;
				}
			}
		}
		i++;//Increases the counter
	}

	answer = evaluate.top();//Sets the answer to the last number on the stack

	postfix.clear();//Deconstructs the stack
	return answer;
}

int main(int argc, char const *argv[])
{
	string line, postfix;//Declares the strings

	double result;//Declares double

	ifstream inputFile;//Declares the file
	inputFile.open("numbers.txt");

	while(!inputFile.eof())//Runs until the end of the file
	{
		while(getline(inputFile,line)) //Continues to retrieves lines while possible
		{
			if(isBalanced(line))//Checks to see if it's balanced then runs ti through the functions
			{
				postfix = infix_To_Postfix(line);
				result = evaluate(postfix);
				cout << "Results for " << line << " is: " << result << endl;
			}
			else//If not declares that it isnt balanced
			{
				cout << "'" << line << "'" << " is not balanced" << endl;
			}

		}
	}

	system("PAUSE");
	return 0;
}