import java.util.Scanner;

public class TestAccount
{
	public static void main (String argv [])
	{
		int id;
		double balance, annualInterestRate, withdraw, deposit;
		Scanner user_input = new Scanner(System.in);

		System.out.println("What is the id for this checking account?");
		// id = 1122;
		id = user_input.nextInt();
		
		System.out.println("What is the balance of ID:" + id + "?");
		// balance = 0;
		balance = user_input.nextDouble();

		System.out.println("What is the Annual Interest Rate of ID:" + id + "?");
		// annualInterestRate = 0.045;
		annualInterestRate = user_input.nextDouble();

		Account P2 = new Checking(id,balance,annualInterestRate);

		System.out.println("What amount would you like to be withdrawn from ID:" + P2.GetAccountID() + "?");
		// withdraw = 5001;
		withdraw = user_input.nextDouble();
		P2.withdraw(withdraw);

		System.out.println("What amount would you like to be desposited to ID:" + P2.GetAccountID() + "?");
		// deposit = 15;
		deposit = user_input.nextDouble();
		P2.deposit(deposit);

		System.out.println(P2.GetAccount());

		System.out.println();
		System.out.println();

		System.out.println("What is the id for this savings account?");
		// id = 1123;
		id = user_input.nextInt();
		
		System.out.println("What is the balance of ID:" + id + "?");
		// balance = 0;
		balance = user_input.nextDouble();

		System.out.println("What is the Annual Interest Rate of ID:" + id + "?");
		// annualInterestRate = 0.045;
		annualInterestRate = user_input.nextDouble();

		Account P3 = new Savings(id,balance,annualInterestRate);

		System.out.println("What amount would you like to be withdrawn from ID:" + P3.GetAccountID() + "?");
		// withdraw = 5001;
		withdraw = user_input.nextDouble();
		P3.withdraw(withdraw);

		System.out.println("What amount would you like to be desposited to ID:" + P3.GetAccountID() + "?");
		// deposit = 15;
		deposit = user_input.nextDouble();
		P3.deposit(deposit);

		System.out.println(P3.GetAccount());
	}
}