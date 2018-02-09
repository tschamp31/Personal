import java.util.Scanner;

public class PalindromicPrimes
{
	public static void main (String argv [])
	{
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		double[] primePalindromeList;
		double inputNumber, prime, primeHolder;
		int inputCounter, position, primeFound, primeTrue, divisorCounter, cap, palindrome, i;
		String palindromeString, reversedString;
		String[] processedString;


		primePalindromeList = new double[100];
		palindrome = 0;
		position = 0;
		primeFound = 0;
		primeTrue = 0;
		divisorCounter = 0;
		cap = 1;

		Scanner user_input = new Scanner(System.in); //Initializes the input
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		System.out.println("What is the prime you would like to enter?"); //Prints out the question for the total.
    	inputNumber = user_input.nextDouble();
    	System.out.println("How many primes would you like to be found?(Limit 100)"); //Prints out the question for the total.
    	inputCounter = user_input.nextInt() - 1;
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		primeHolder = inputNumber;

		while(primeHolder != -1)
		{
			if(inputNumber%primeHolder == 0)
			{
				divisorCounter++;
			}
			if(primeHolder == 0 && divisorCounter == 2)
			{
				primeFound = 1;
			}
			if(primeFound == 1)
			{
				Integer primehold = (int) inputNumber;
				reversedString = "";

				palindromeString = String.valueOf(primehold);
				String[] processedstring = palindromeString.split("");

				i = palindromeString.length();
				while(i >= 0)
				{
					reversedString = reversedString + processedstring[i];
					i--;
					
				}

				if(reversedString.equals(palindromeString))
				{
					palindrome = 1;
				}
			}
			if(primeFound == 1 && palindrome == 1)
			{
				position++;
				primePalindromeList[position] = inputNumber;
			}
			primeHolder--;
		}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		if(primeFound == 0)
		{
			System.out.println("The number entered was not a Palindromic Prime");
			System.exit(0);
		}
/////////////////////////////////////////////////////////////////////////	
/////////////////////////////////////////////////////////////////////////
    	while(inputCounter != 0)
    	{
    		prime = primePalindromeList[position] + 1;
    		primeFound = 0;
    		palindrome = 0;

    		while(primeFound == 0 && palindrome == 0)
    		{
    			primeHolder = prime;
				divisorCounter = 0;

				while(primeHolder != -1)
				{
					if(prime%primeHolder == 0)
					{
						divisorCounter++;
					}
					if(primeHolder == 0 && divisorCounter == 2)
					{
						primeFound = 1;
						divisorCounter = 0;
					}
					if(primeFound == 1)
					{
						Integer primehold = (int) prime;
						reversedString = "";

						palindromeString = String.valueOf(primehold);
						String[] processedstring = palindromeString.split("");

						i = palindromeString.length();
						while(i >= 0)
						{
							reversedString = reversedString + processedstring[i];
							i--;
							
						}

						if(reversedString.equals(palindromeString))
						{
							palindrome = 1;
						}
						else
						{
							primeFound = 0;
						}
					}
					if(primeFound == 1 && palindrome == 1)
					{
						position++;
						primePalindromeList[position] = prime;
					}
					primeHolder--;
				}
    			prime++;
    		}
    		inputCounter--;
    	}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
    	while(cap != position + 1)
    	{
    		System.out.print(primePalindromeList[cap] + "  ");

    		if(cap%10 == 0)
    		{
    			System.out.println("");
    		}

    		cap++;
    	}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
	}
}