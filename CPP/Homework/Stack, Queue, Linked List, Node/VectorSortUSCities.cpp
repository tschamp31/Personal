#include <iostream> //Headers
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>   

using namespace std;

int linecounter(string inputfile)
{
	ifstream in_stream; //Stream to read from the file
	int linecount; //Starts variables
	string line;
	linecount = 0;

	in_stream.open( inputfile.c_str() ); //Opens and initializes the data file
	if (in_stream.fail())			 //If-statement to break program if file does not open
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	while(in_stream.good()) //counts up the lines
	{
		while(getline(in_stream,line))
		{
			linecount++;
		}
	}
	in_stream.close();  //Closes the data file
	return linecount;
}

void GeoDataSort(string inputfile, string outputfile)
{
	ifstream in_stream; //Stream to read from the file
	ofstream out_stream; //Stream to write on the file
	string line;
	int i, linecount;
	linecount = linecounter(inputfile) + 1; //Carries over the linecount

	in_stream.open( inputfile.c_str() ); //Opens and initializes the data file
	if (in_stream.fail())			 //If-statement to break program if file does not open
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	out_stream.open( outputfile.c_str() ); //Opens and initializes the data file
	if (out_stream.fail())					//If-statement to break program if file does not open
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}

	vector<string> abreviation(linecount);//Initializes Variables
	vector<string> location(linecount); //Initializes Variables
	vector<double> LATdegree(linecount);//Initializes Variables
	vector<double> LATminutes(linecount);//Initializes Variables
	vector<double> LATseconds(linecount); //Initializes Variables
	vector<double> LONGdegree(linecount);//Initializes Variables
	vector<double> LONGminutes(linecount);//Initializes Variables
	vector<double> LONGseconds(linecount);  //Initializes Variables
	vector<double> LATdecimal_degree(linecount);//Initializes Variables
	vector<double> LONGdecimal_degree(linecount); //Initializes Variables

	for (i = 0; !in_stream.eof(); i++) //Runs loop until end of file
	{
		in_stream >> abreviation[i] >> LATdegree[i] >> LATminutes[i] >> LATseconds[i] >> LONGdegree[i] >> LONGminutes[i] >> LONGseconds[i] >> location[i]; //Reads file and stores data into variables
		LATdecimal_degree[i] = (LATdegree[i]) + (LATminutes[i]/60) + (LATseconds[i]/3600); //Calculates Latitiude Decimal Degree
		LONGdecimal_degree[i] = (LONGdegree[i]) + (LONGminutes[i]/60) + (LONGseconds[i]/3600); //Calculates Longitude Decimal Degree
		out_stream.precision(2);	//Sets the precision of output values to the hundreths place.

		//******************************************************//
		string::size_type s = location[i].find(",", 0); // Removes the commands
		if (s != string::npos) 
		{ 
			location[i].erase(s, 1);
			location[i].insert(s,"  ");
		}
		//********************************************************//
		out_stream.setf(ios::fixed);
		out_stream.setf(ios::showpoint);
		cout << abreviation[i] << "\t" << LATdecimal_degree[i] << "\t" << LONGdecimal_degree[i] << "\t" << location[i] << endl;
		out_stream << abreviation[i] << "\t" << LATdecimal_degree[i] << "\t" << LONGdecimal_degree[i] << "\t" << location[i] << endl; //Outputs file in a neat manner
	}

	in_stream.close();  //Closes the data file
	out_stream.close(); //Closes the data file
}

int LocationFinder(string inputfile, string Location)
{
	ifstream in_stream; //Stream to read from the file
	int linecount, i, result;
	linecount = linecounter(inputfile) + 1; //Sets the linecount so there is no stack overflow
	result = 0; //Defaults the result to fail
	
	vector<string> abreviation(linecount);//Initializes Variables
	vector<string> city(linecount); //Initializes Variables
	vector<double> LATdecimal_degree(linecount);//Initializes Variables
	vector<double> LONGdecimal_degree(linecount); //Initializes Variables
	vector<string> state(linecount); 

	in_stream.open( inputfile.c_str() ); //Opens and initializes the data file
	if (in_stream.fail())			 //If-statement to break program if file does not open
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	for (i = 0;in_stream.good(); i++) //Runs loop until end of file
	{
		in_stream >> abreviation[i] >> LATdecimal_degree[i] >> LONGdecimal_degree[i] >> city[i] >> state[i];//Reads file and stores data into variables

		if(city[i].find(Location) != std::string::npos) //Finds the city and reads the line
		{
			cout << abreviation[i] << "\t" << LATdecimal_degree[i] << "\t" << LONGdecimal_degree[i] << "\t" << city[i] << "\t" << state[i] << endl; //Reads out the current location on the array list
			result = 1; //Sets the result to 1 which represents success
		}
	}
	in_stream.close();  //Closes the data file
	return result;
}

int main()
{
string Location;
int Result;
GeoDataSort("US_Cities.dat","sorted.txt"); //Sets the input and output file
cout << "What is the name of the city you want to look for?: "; //Asks for the city
cin >> Location; //Records the city
Result=LocationFinder("sorted.txt",Location); //Sets whether the city was found
if(Result == 0) //Error if the city was not found
{
	cout << "The city " << Location << " was not found on the list.";
}
cin.get();
cin.get();
return 0;
}