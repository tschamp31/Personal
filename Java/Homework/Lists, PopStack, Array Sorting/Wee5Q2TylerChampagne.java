import java.util.Scanner;

class Wee5Q2TylerChampagne
{
	// public static void TrainYard()
	// {
	// 	public static void stack()
	// }
	public static void main(String []args)
	{
		int[] inputarray, outputarray;
		String input, map;
		inputarray = new int[10];
		outputarray = new int[10];
		int counter, counter2, maplength;
		Scanner user_input = new Scanner(System.in);

		System.out.println("What is the mapping input?: ");
		input = "1 2 3 4 9 6 7 8 9";
		map = input.replaceAll("[^0-9]", "");
		maplength = map.length();
		counter = 9;
		counter2 = 0;
		
		do
		{
			inputarray[counter] = map.charAt(counter2) - '0';
			counter--;
			counter2++;
			maplength--;
		}
		while (maplength > 0);


		while(counter2 >= 0)
        {
            System.out.print(inputarray[counter2] + " ");
            counter2--;
        }

		// Howto - get an input array, output array, stackconverter.
		// inputer array = string of numbers spliced into eahc number an array position
		// output array = array positions read out into a String
		// stackconverter = push pop system based off the array size and contents.
	}
}