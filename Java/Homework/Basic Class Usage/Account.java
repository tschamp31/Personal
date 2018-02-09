import java.util.Date;

public class Account
{
	public int id = 0;
	public double balance = 0;
	public double annualInterestRate = 0;
	public Date dateCreated;

	public Account(int i, double b, double air)
	{
		this.id = i;
		this.balance = b;
		this.annualInterestRate = air;
		this.dateCreated = new Date();
	}
	public Account()
	{
		this.id = 0; 
		this.balance = 0; 
		this.annualInterestRate = 0;
		this.dateCreated = new Date();
	}

	public String GetAccount()
	{
		return "ID:" + id + ", Balance:" + balance + ", Annual Interest Rate: " + annualInterestRate + ", Date Created: " + dateCreated;
	}

	public void SetAccountID(int i)
	{

		this.id = i;
	}

	public void SetAccountBalance(double b)
	{
		this.balance = b;
	}

	public void SetAccountAIR(double air)
	{
		this.annualInterestRate = air;
	}

	public int GetAccountID()
	{
		return this.id;
	}

	public double GetAccountBalance()
	{
		return this.balance;
	}

	public double GetAccountAnnualInterest()
	{
		return this.annualInterestRate;
	}	

	public double getMonthlyInterest()
	{
		return this.annualInterestRate/12;
	}

	public Date getDateCreated()
	{
		return this.dateCreated;
	}

	public void withdraw(double m)
	{
		this.balance = this.balance - m;
	}

	public void deposit(double m)
	{
		this.balance = this.balance + m;
	}

	public void deposit(int m)
	{
		this.balance = this.balance + m;
	}
}