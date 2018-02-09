#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <ctype.h>

using namespace std;

struct iNode //Creates an int node
{
	double data; //Setups the data structure
	iNode* next;
};

struct sNode //Creates a string node
{
	string data; //Setups the data structure
	sNode* next;
};


class String //Sets up the string node commands
{
public:
	void initNode(struct sNode *head, string n); //Starts the node
	void addNode(struct sNode *head, string n); //Adds a value to the node
	void display(struct sNode *head1, struct sNode *head2, struct iNode *head3, struct iNode *head4);//Setups a display

};

//********************************************************//

class Int //Sets up the int node commands
{
public:
	void initNode(struct iNode *head,double n); //Starts the node
	void addNode(struct iNode *head, double n); //Adds a value to the node
};

class Location //Setsup the location commands
{
public:
	void Main(string filename); //Main function for the location commands
	int Find(struct sNode *head, string city); //Finds a specific string value
	void Calculate(struct iNode *head1, struct iNode *head2, struct sNode *head3, struct sNode *head4, int anchor,int linenumber); //Does the calculations
	void Display(int miles, int kilometers, string abreviation1, string city1, string abreviation2, string city2); //Reads out the data
};
//********************************************************//

void String::initNode(struct sNode *head, string n) //starts the node
{
	head->data = n; //Starts it at N
	head->next =NULL; //Sets next value to null
}
void String::addNode(struct sNode *head, string n)  //Adds to the node
{
	sNode *newNode = new sNode; //Creates an internal node
	newNode->data = n; //Sets the data N
	newNode->next = NULL; //Sets the next data to null

	sNode *cur = head; 
	while(cur) //Adds while there are values to add and as long as the string is not null.
	{
		if(cur->next == NULL) 
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void String::display(struct sNode *head1, struct sNode *head2, struct iNode *head3, struct iNode *head4) 
{
	String String; //References the string function
	if(!head1 || !head2 || !head3 || !head4) //If any of the nodes do not work it ends the function
	{
		cout << endl;
		return;
	}
	cout << head1->data << "\t"<< head2->data << "\t"<< head3->data << "\t"<< head4->data << endl;; //Reads out the nodes
	String.display(head1->next,head2->next,head3->next,head4->next); //Recursively checks back till the end
}

//********************************************************//
void Int::initNode(struct iNode *head,double n)//starts the node
{
	head->data = n;//Starts it at N
	head->next =NULL;//Sets next value to null
}
void Int::addNode(struct iNode *head, double n) //Adds to the node
{
	iNode *newNode = new iNode;//Creates an internal node
	newNode->data = n;//Sets the data N
	newNode->next = NULL;//Sets the next data to null

	iNode *cur = head;
	while(cur) //Adds while there are values to add and as long as the string is not null.
	{
		if(cur->next == NULL) 
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

//********************************************************//

void Location::Main(string filename) //Starts the main location function
{
	Int Int;//Creates a class int
	String String;//Creates a class string
	Location Location;//Creates a class location
	double LATdegree, LATseconds, LATminutes, LONGdegree, LONGseconds, LONGminutes, LONGdecimal_degree, LATdecimal_degree;//Declares the doubles
	string abreviation, location, city;//Declares the strings
	struct sNode *abreviationM = new sNode;//Starts the node
	struct sNode *locationM = new sNode;//Starts the node
	struct iNode *LATdecimal_degreeM = new iNode;//Starts the node
	struct iNode *LONGdecimal_degreeM = new iNode;//Starts the node
	ifstream in_stream; //Stream to read from the file
	ofstream out_stream; //Stream to write on the file

	String.initNode(abreviationM, "Start");//Starts the linked list
	String.initNode(locationM, "Start");//Starts the linked list
	Int.initNode(LATdecimal_degreeM, 1);//Starts the linked list
	Int.initNode(LONGdecimal_degreeM, 1);//Starts the linked list

	in_stream.open( filename.c_str() ); //Opens and initializes the data file
	if (in_stream.fail())			 //If-statement to break program if file does not open
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	while(!in_stream.eof())//Reads until the end of the file
	{
		in_stream >> abreviation >> LATdegree >> LATminutes >> LATseconds >> LONGdegree >> LONGminutes >> LONGseconds >> location;//Reads in the info to temp data for the line
		LATdecimal_degree = (LATdegree) + (LATminutes/60) + (LATseconds/3600); //Calculates Latitiude Decimal Degree
		LONGdecimal_degree = (LONGdegree) + (LONGminutes/60) + (LONGseconds/3600);//Calculates Latitiude Decimal Degree
		string::size_type s = location.find(",", 0); // Removes the commas
		if (s != string::npos) //Checks to make sure the comma exists
		{ 
			location.erase(s, 1); //Erasses the comma
			location.insert(s,"  ");//Seperates the City/State
		}
		String.addNode(abreviationM,abreviation);//Adds the temp data to the node
		String.addNode(locationM,location);//Adds the temp data to the node
		Int.addNode(LATdecimal_degreeM,LATdecimal_degree);//Adds the temp data to the node
		Int.addNode(LONGdecimal_degreeM,LONGdecimal_degree);//Adds the temp data to the node
	}
	in_stream.close();//Closes the file

	cout << "What city call letters would you like to reference?" << endl;//Asks for the abv input
	cin >> city;//Takes it in
	city = "[" + city + "]";//Adds the brackets for the search
	int linenumber = Location.Find(abreviationM, city); //Finds the line number for the city
	int anchor = Location.Find(abreviationM, "[DTW]"); //Find the line number for detroit
	Location.Calculate(LATdecimal_degreeM,LONGdecimal_degreeM,abreviationM,locationM,anchor,linenumber); //Calculates it all
}

int Location::Find(struct sNode *head, string city) //Finds the line number
{
	int count; //Implements a counter
	count = 0; //Sets the counter
	sNode *cur = head; 
	while(cur) //runs until the node is finished
	{
		if(cur->data == city) return count; //Finishes the while statement if the variable is found in the linked list and returns the line number
		cur = cur->next;
		count++;
	}
	cout << "No Node " << city << " in list.\n"; //Otherwise declares nothing is found.
}

void Location::Calculate(struct iNode *head1, struct iNode *head2, struct sNode *head3, struct sNode *head4, int anchor,int linenumber)
{
	String String; //Declares string class
	Location Location; //Declares location class
	int i; //Declares ints
	double lat1, lon1, lat2, lon2, dlon, dlat, a, c, d1, d2, r1, r2; //Declares doubles
	string letters1, city1, letters2, city2; //Declares strings
	i = 0; //Set 0
	r1 = 3961; //Sets for miles
	r2 = 6373;// sets for kilometers
	if(head1 != 0 || head2 != 0) //Starts the linked list reader
	{
		while(head1->next != NULL || head2->next != NULL) //Reads until it is null
		{
			if(anchor == i) //Sets the variables for the anchor line number
			{
				lat1 = head1->data;
				lon1 = head2->data;
				letters1 = head3->data;
				city1 = head4->data;
			}
			if(linenumber == i) //sets variables for the selected city line number
			{
				lat2 = head1->data;
				lon2 = head2->data;
				letters2 = head3->data;
				city2 = head4->data;
			}
			head1 = head1->next;//Cycles through the string
			head2 = head2->next;//Cycles through the string
			head3 = head3->next;//Cycles through the string
			head4 = head4->next;//Cycles through the string
			i++;
		}
	}
	lat1 = lat1*(M_PI/180); //Converts to radians
	lat2 = lat2*(M_PI/180);//Converts to radians
	lon1 = lon1*(M_PI/180);//Converts to radians
	lon2 = lon2*(M_PI/180);//Converts to radians

	dlat = lat2 - lat1; //Sets delta lat
	dlon = lon2 - lon1; //Sets delta lon

	a = (sin(dlat/2)*sin(dlat/2)) + (sin(dlon/2)*sin(dlon/2)) * (cos(lat1) * cos(lat2)); //Haversine
	c = 2 * (atan2(sqrt(a),sqrt(1-a)));// Haversine
	d1 = r1 * c;//Haversine - Miles
	d2 = r2 * c;//Haversine - Kilometers

	Location.Display(d1,d2,letters1,city1,letters2,city2); //Reads out the info
}

void Location::Display(int miles, int kilometers, string abreviation1, string city1, string abreviation2, string city2) //Reads out the info in a neat manner.
{
	cout << "Distance betweeen " << city1 << " " << abreviation1 << " and " << city2 << " " << abreviation2 << " is " << miles << " miles (" << kilometers << " kilometers)." << endl;
}

int main()
{
	Location Memory; //Sets a memory class
	Memory.Main("US_Cities.dat"); //runs the program.
	return 0;
}