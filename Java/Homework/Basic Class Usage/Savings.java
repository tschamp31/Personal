public class Savings extends Account
{
	public Savings(int id, double balance, double annualInterestRate)
	{
		super(id, balance, annualInterestRate);
	}

	public void withdraw(double m)
	{
		super.balance = super.balance - m;
	}
	public void deposit(double m)
	{
		super.balance = super.balance + m;
	}
}