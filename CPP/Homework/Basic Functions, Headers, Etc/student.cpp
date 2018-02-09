//Tyler Champagne
//Ser 221
//Assignment 2

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Student
{
private://Variable declaration for the class
	string name;
	int numClasses;
	vector<string> classList;
public:
	Student(string nameInput, int numClassesInput, vector<string> classListInput)//Constructor for the class
	{
		this->name = nameInput;
		this->numClasses = numClassesInput;
		this->classList = classListInput;
	}

	string nameGet()//Appropriate gets for each variable
	{
		return this->name;
	}
	int numClassesGet()
	{
		return this->numClasses;
	}
	vector<string> classListGet()
	{
		return this->classList;
	}

	void nameSet(string nameInput)//Appropriate sets for each variable
	{
		this->name = nameInput;
	}
	void numClassesSet(int numClassesInput)
	{
		this->numClasses = numClassesInput;
	}
	void classListSet(vector<string> classListInput)
	{
		this->classList = classListInput;
	}

	void printStudents()//Prints out the student info
	{
		cout << "Student Name: " << name << endl;
		cout << "Student Class List: ";
		if(classList.size() == 0)
		{
			cout << "There are no classes assigned to this student." << endl;
		}
		else
		{
			for(int i = 0; i != classList.size(); i++)
			{
				cout << classList[i] << ", ";
			}
		}
	}

	void studentReset()//Resets the class count and list of classes
	{
		this->numClasses = 0;
		this->classList.clear();
	}

	void studentClear()//Resets the whole class
	{
		this->name="";
		this->numClasses = 0;
		this->classList.clear();
	}
};

int main(int argc, char const *argv[])
{
	char answer;//Declaration of variables
	string nameInput, numClassesInputString, classListInputString;
	int numClassesInput;
	vector<string> classListInput(100);

	while(true)
	{
		cout << "What is the students name?: " << endl;//Asks for student name input
		cin >> nameInput;

		while (true)//Runs until it retrieves a digit answer.
		{
			cout << "How many classes does " << nameInput << " have?" << endl;//Retrvies class count
			cin.ignore();
			getline(cin, numClassesInputString);

			stringstream myStream(numClassesInputString);//Converts the class count to a stream
			if (myStream >> numClassesInput) break;//Converts the stream to a possible valid number
			cout << "Invalid input, please enter numbers only." << endl;
		}

		for(int i = 0; i != numClassesInput; i++)//Asks for the class list based on the class count
		{
			cout << "Class " << i + 1 << " is? " << endl;
			getline(cin, classListInputString);
			classListInput[i] = classListInputString;
		}

		classListInput.resize(numClassesInput);//Resizes the vector class list to the actual count of class.

		Student student(nameInput,numClassesInput,classListInput);//Constructs the class with the given info.

		cout << endl;
		student.printStudents();//calls a class function
		cout << endl;
		cout << "Is the info above correct?(Y/N)" << endl;//checks to see if the info is correct
		cin >> answer;
		if(answer == 'Y' || answer == 'y') break;//If it's correct it ends the program.
		student.studentClear();//calls a class function
	}

	return 0;
}