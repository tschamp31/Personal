#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Student
{
	private:
		string name;
		int numClasses;
		string classList[];
	public:
		void set(string nameInput, int numClassesInput, string classListInput[]);
		void get();
		void reset();
};

void Student::set(string nameInput, int numClassesInput, string classListInput[])
{
	name = nameInput;
	numClasses = numClassesInput;
	classList = classListInput;
}

void Student::get()
{
	cout << "Name: " << name << endl;
	cout << "Number of Classes: " << numClasses << endl;
	cout << "List of Classes: " << classList << endl;
}

void Student::reset()
{
	numClasses = 0;
	classList = {};
}

int main()
{
	string name;
	int numClasses, i;
	char answer;

	cout << "What is the students name?" << endl;
	cin >> name;
	cout << "How many classes are you taking?" << endl;
	cin >> numClasses;

	string classList[numClasses];

	for(i = 1; i != numClasses; i++)
	{
		cout << "What is your " << i << " class?" << endl;
		cin >> classList[i - 1];
	}

	cout << "Is the information you entered correct?" << endl;
	cin >> answer;

	if(answer == 'Y' || answer == 'y')
	{

	}
}