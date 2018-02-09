public class Checking extends Account
{
	public Checking(int id, double balance, double annualInterestRate)
	{
		super(id, balance, annualInterestRate);
	}

	public void withdraw(double m)
	{
		if(super.balance - m >= -5000)
		{
			super.balance = super.balance - m;
		}
		else
		{
			super.balance = super.balance;
			System.out.println("***Insufficient Funds to withdraw: " + m + ". Your current balance is: " + super.balance + " ***");
		}
	}
	public void deposit(double m)
	{
		super.balance = super.balance + m;
	}
}