#include <iostream>
#include <string>

using namespace std;

struct Node //Creates an int node
{
	double data; //Setups the data structure
	Node* next;
};

class Queue//Declares Queue class
{
public:
	Queue()//Declares Queue as a structure
	{
		front = NULL;//Sets front null
		rear = NULL;//Sets rear null
	}
	void enqueue(double n);//Declares function
	void dequeue();//Declares function
	void queuepeek();//Declares function
private:
	Node *front;//Sets class as a structure node.
	Node *rear;//Sets class as a structure node.

};

void Queue::enqueue(double n)//Pushes the Queue back and adds to the top
{
	    Node *queue = new Node;//Setups temp node
	    queue->data=n;//adds data to the queue
	    queue->next=NULL;//Sets next null
        if(rear == NULL || front == NULL)//Checks to see if top is null
        {       
        	front = queue;//Sets new front
        }
        else
        {
        	rear->next=queue;//Sets next data to rear
        }
        rear=queue;//Sets data to the rear
}

void Queue::dequeue()//Pops top of Queue
{
	Node *queue = new Node;//Setups temp node
	int n;//Declares variable
	if(rear == NULL || front == NULL)//Checks to see if the top is empty
        cout<< "Queue is empty." << endl;//Returns a string if it is
    else
    {
    	queue = front;//Sets the front
    	n = queue->data;
    	front = front->next;//Sets new front
    	delete(queue);//Deletes old front
    }
}

void Queue::queuepeek()//Peeks the top of the Queue
{
	Node *temp;//Creates temp Queue
    temp = front;//Sets the top position to temp
    if(front == NULL || rear == NULL)//checks if the Queue is null
    {
    	cout<<"Queue is empty."<<endl;//reads out if so
    }
    else
    {
    	cout << "Output from Queue: " << endl;//Reads out header
    	while(temp!=NULL)//Reads out the queue
    	{
    		cout<<temp->data<<endl;
    		temp=temp->next;
    	}
    }
}

int main()
{
	Queue *queue = new Queue; //Declares class constructor
	double input, i; //Declares variables
	i = 0;//Sets i to 0
	while (i != 5)//While i is not 0
	{
	cout << "Enter an input: ";//Reads out
	cin >> input;//Takes in
	queue->enqueue(input);//Assigns input to stack top
	cout << endl;//Adds a line
	i++;//Counts up
	}
	// queue->enqueue(1.5); //Example code
	// queue->enqueue(2.5);
	// queue->enqueue(3.5);
	// queue->enqueue(4.5);
	// queue->enqueue(5.5);
	// queue->enqueue(6.5);
	// queue->dequeue();
	queue->queuepeek();
	return 0;
}