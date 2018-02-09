class BankAccount
{
	double balance;
	double interest;

	BankAccount()
	{
		this.balance = 0; //starts a 0 bank and interest
		this.interest = 0;
	}

	BankAccount(double balance, double interest)
	{
		this.balance = balance; //sets based on user input
		this.interest = interest;
	}

	double getBalance()
	{
		return this.balance; //returns the balance
	}
	void setBalance(double balance)
	{
		this.balance = balance; // sets the balance
	}
	double getInterest()
	{
		return this.interest; //returns the interest
	}
	void setInterest(double interest)
	{
		this.interest = interest; //sets the interest
	}
	void deposit(double total)
	{
		this.balance = this.balance + total; // adds a deposit to balance
	}
	void withdrawal(double total)
	{
		this.balance = this.balance - total; //withdrawals from the balance
	}
	void addInterest(double time)
	{
		this.balance = this.balance + ((this.balance * this.interest) * time); //adds interest
	}
	double getTime(double fbalance, double balance, double rate, double deposits)
	{
		double time;
		time = (fbalance - balance + deposits)/(balance*rate); //finds the time.
		return time;
	}

}