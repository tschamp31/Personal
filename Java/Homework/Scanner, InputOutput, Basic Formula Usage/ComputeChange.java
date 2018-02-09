import java.util.Scanner;

public class ComputeChange
{
	public static void main (String argv [])
	{
		///////////////////////////////////////////////////////////////
		//Declares the variables
		double dollar, quarter, dime, nickel, penny, total, remainder;
		int dollars, quarters, dimes, nickels, pennies;
		///////////////////////////////////////////////////////////////

		///////////////////////////
		//Initializes the variables
		dollar = 1.00;
		quarter = 0.25;
		dime = 0.10;
		nickel = 0.05;
		penny = 0.01;

		dollars = 0;
		quarters = 0;
		dimes = 0;
		nickels = 0;
		pennies = 0;
		////////////////////////

		Scanner user_input = new Scanner(System.in); //Initializes the input

		System.out.println("What is the monetary figure you would like to enter?"); //Prints out the question for the total.
    	total = user_input.nextDouble();

		//////////////////////////////////////
		// Works as a hierarchy system to break down the total
    	while(total > 0.99)
    	{
    		total = total - dollar;
    		dollars++;
    	}

    	while(total > 0.25)
    	{
    		total = total - quarter;
    		quarters++;
    	}

    	while(total > 0.10)
    	{
    		total = total - dime;
    		dimes++;
    	}

        while(total > 0.05)
    	{
    		total = total - nickel;
    		nickels++;
    	}

    	while(total > 0.00)
    	{
    		total = total - penny;
    		pennies++;
    	}
    	/////////////////////////////////////////////

    	System.out.println(dollars + " dollars, " + quarters + " quarters, " + dimes + " dimes, " + nickels + " nickels, " + pennies + " pennies."); //Prints out the total as given in the assignment
	}	
}