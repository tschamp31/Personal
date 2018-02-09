#include <iostream>
#include <string>

using namespace std;

struct Node //Creates an int node
{
	double data; //Setups the data structure
	Node* next;
};

class Stack//Declares stack class
{
public:
	Stack()//Declares stack as a structure
	{
		top = NULL;//Sets top null
	}
	void push(double n);//Declares function
	void pop();//Declares function
	void peektop();//Declares function
	void print();//Declares function
private:
	Node *top;//Sets class as a structure node.

};

void Stack::push(double n)//Pushes the stack back and adds to the top
{
	    Node *newTop = new Node;//Setups temp node
        if(top == NULL)//Checks to see if top is null
        {       
            newTop->data = n;//If so it adds data to the list
            newTop->next = NULL;//Sets the next in line as null
            top = newTop;//Sets top
        }
        else
        {
            newTop->data = n;//If not it still sets the data to the position
            newTop->next = top;//But the next position is now the new top
            top = newTop;//Sets the top
        }
}

void Stack::pop()//Pops top of stack
{
	if(top == NULL)//Checks to see if the top is empty
        cout<< "Top of the stack is empty." << endl;//Returns a string if it is
    else
    {
        Node * old = top;//If not its applied to a temp node
        top = top->next;//Where it changes positions
        delete(old);//Deleting top of the stack
    }
}

void Stack::peektop()//Peeks the top of the stack
{
	Node *temp;//Creates temp stack
    temp = top;//Sets the top position to temp
    cout << "Top of the stack: ";
    cout<<temp->data<<endl;//Uses top data to pull from the top of the stack
}

void Stack::print()
{
    Node *temp;
    temp = top;
    cout << "Outpuyt from stack:" << endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main()
{
	Stack *stack = new Stack; //Declares class constructor
	double input, i; //Declares variables
	i = 0;//Sets i to 0
	while (i != 5)//While i is not 0
	{
	cout << "Enter an input: ";//Reads out
	cin >> input;//Takes in
	stack->push(input);//Assigns input to stack top
	cout << endl;//Adds a line
	i++;//Counts up
	}
	// stack->push(1.5); //Example code
	// stack->push(2.5);
	// stack->push(3.5);
	// stack->push(4.5);
	// stack->push(5.5);
	// stack->push(6.5);
	// stack->pop();
	// stack->pop();
    stack->print();
	return 0;
}