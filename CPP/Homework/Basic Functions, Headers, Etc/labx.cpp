#include <iostream>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

int main()
{
    int accountNumber = 1000;

    bankAccount jackAccount(20);
    bankAccount bobAccount(30);

// cout<<"jackAccount: "<<jackAccount<<endl;
// cout<<"bobAccount: "<<bobAccount<<endl;

// bankAccount twiceMoreThanJack = jackAccount*2;
// cout<<"twiceMoreThanJack: "<<twiceMoreThanJack<<endl;

// bobAccount++;
// cout<<"after++, bobAccount is : "<<bobAccount<<endl;

// bankAccount bobAndJack = jackAccount + bobAccount;
// cout<<"bobAndJack account: " <<bobAndJack<<endl;

// bankAccount JoeAccount(100);

// bankAccount joeAndBob = add(bobAccount, JoeAccount);
// cout<<"joeAndBob account: "<<joeAndBob<<endl;
   cout <<bobAccount++<<endl;

	cin.get();
	cin.get();
    return 0;
}

#include "bankAccount.h"
#include <iostream>
using namespace std;

bankAccount::bankAccount(int initialBalance)
{
balance = initialBalance;
}

bankAccount bankAccount::operator++(int u)
{
   bankAccount temp = *this;  //use this pointer to copy
                                //the value of the object
       //increment the length and width  
   balance++;

   return temp;    //return the old value of the object
}


bankAccount bankAccount::operator+(bankAccount& account)
{
   bankAccount tempAcc(balance);

   tempAcc.balance = balance + account.balance;

   return tempAcc;
}


bankAccount bankAccount::operator*( int number)
{
   bankAccount tempAcc(balance);

   tempAcc.balance = balance * number;

   return tempAcc;
}

bool bankAccount::operator==(bankAccount& account)
{
   return (balance == account.balance);
}

bool bankAccount::operator<(bankAccount& account)
{
   return (balance < account.balance);
}


ostream& operator<<(ostream& osObject,bankAccount& account)
{
   osObject << "balance = "  << account.getBalance();
           

   return osObject;
}

int bankAccount::getBalance()
{
return balance;
}

bankAccount add(bankAccount & acc1, bankAccount& acc2)
{
int sum = acc1.getBalance() + acc2.getBalance();
bankAccount tmp(sum);
return tmp;
}