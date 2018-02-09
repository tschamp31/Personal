//Class bankAccount
 
#ifndef H_bankAccount
#define H_bankAccount

#include <iostream>
using namespace std;

class bankAccount
{
public:
	bankAccount(int initialBalance);
	bankAccount operator + (bankAccount &account);
	bankAccount operator * (int number);
	bankAccount operator ++ (int);
	bool operator == (bankAccount& acc);
	bool operator < (bankAccount& acc);
	int getBalance();

//friend functions:

friend ostream& operator<<(ostream& osObject, bankAccount & acc);
friend bankAccount add(bankAccount & acc1, bankAccount & acc2);

private:    
   int balance;
};

#endif