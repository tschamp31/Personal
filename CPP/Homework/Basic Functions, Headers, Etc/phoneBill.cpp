#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Customer
{
private:
	string name;
	int callsmade;
	float balance;
	int plan;
	int minutesSpent;
public:
	Customer(string INname, int INcallsmade, int INplan)
	{
		this->name = INname;
		this->callsmade = INcallsmade;
		this->balance = 0;
		this->plan = INplan;
	}
	void computeBill()
	{
		float monthlyfee, bill, percall, numcalls, permin, nummins;

		if(this->plan == 0)
		{
			monthlyfee = 10;
			percall = 0.50;

			bill = monthlyfee + (percall * this->callsmade);
		}
		if(this->plan == 1)
		{
			monthlyfee = 20;
			percall = 0.05;
			permin = 0.10;
			bill = monthlyfee + (percall*this->callsmade) + (permin*this->minutesSpent);
		}
		else
		{
			cout << "Invalid plan assigned to the name: " << this->name << "." << endl;
 		}
 		this->balance += bill;
	}
	void setName(string INname)
	{
		this->name = INname;
	}
	void setPlan(int INplan)
	{
		this->plan = INplan;
	}
	void setCallsMade(int INcallsmade)
	{
		this->callsmade = INcallsmade;
	}
	string getName()
	{
		return this->name;
	}
	float getBalance()
	{
		return this->balance;
	}
};

int main(int argc, char const *argv[])
{
	Customer* list[30];
	int i, plan,

	string fnames[] = {"Rob", "Sally", "Joseph", "Marry", "Sue", "Tyler", "Chris", "Matt", "Bob", "Jake"};
	string lnames[] = {" Smith", " Red", " Blue", " Nguyen", " Frost", " Ahn", " Champagne", " Young", " Peterson", " Read"};
	for(i = 0; i != 30; i++)
	{
		if(i <= 15)
		{
			plan = 0;
		}
		if(i > 15)
		{
			plan = 1;
		}

	}
	return 0;
}