import java.util.Scanner;

public class Wee4Q2TylerChampagne
{
	public static void InsertionSorter(int[] numberarray,int arrayposition)
	{
	int i, key, j;

    for (i = 1; i < numberarray.length; i++)
    {
           key = numberarray[i];
           for(j = i - 1; (j >= 0) && (numberarray[j] < key); j--)   // Smaller values are moving up
          {
                 numberarray[j+1] = numberarray[j];
          }
         numberarray[j+1] = key;
    }

    while(arrayposition >= 0)
    {
    	System.out.println(numberarray[arrayposition]);
    	arrayposition--;
    }

     }

	public static void main(String []args)
    {
    	int inputnumber, arrayposition, respositionnumber, numberssorted, counter;
    	char answer;
    	int[] numberarray;
    	numberarray = new int[15];
    	arrayposition = 0;
    	Scanner user_input = new Scanner(System.in);

    	System.out.println("Would you like to enter a number to the array? Enter:(Y/N): ");
    	answer = user_input.next().charAt(0);
    	System.out.println("What number would you like to add then?: ");
    	inputnumber = user_input.nextInt();

    	if(answer == 'Y' || answer == 'y')
    	{
    		do
    		{
    			numberarray[arrayposition] = inputnumber;
    			System.out.println("Would you like to enter another number to the array? Enter:(Y/N): ");
    			answer = user_input.next().charAt(0);
    			if(answer == 'Y' || answer == 'y')
    			{
    				System.out.println("What number would you like to add then?: ");
    				inputnumber = user_input.nextInt();
    				arrayposition++;
    			}
    			else if(answer == 'N' || answer == 'n')
    			{
    				System.out.println("");
    			}    			
    			else
    			{
    				System.out.println(answer + " Is not a correct input.");
    			}
    		}
    		while(answer == 'Y' || answer == 'y');

    		int arraypositionsort = arrayposition;
    		while(arrayposition >= 0)
    		{
    			System.out.println(numberarray[arrayposition]);
    			arrayposition--;
    		}
    		System.out.println("");
    		InsertionSorter(numberarray, arraypositionsort);

    	}
    	else if(answer == 'N' || answer == 'n')
    	{
    		System.out.println("Have a nice day then!");
    	}

    	else
    	{
    		System.out.println(answer + " Is not a correct input.");
    	}

    }
}