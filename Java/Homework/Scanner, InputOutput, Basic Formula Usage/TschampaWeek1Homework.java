import java.util.Scanner;

public class TschampaWeek1Homework 
{
	public static void ProblemOne()
	{
    	String namefirst, namelast;
    	Scanner user_input = new Scanner(System.in);

       	System.out.println("What is your first name?:");
		namefirst = user_input.next();
		System.out.println("What is your last name?:");
		namelast = user_input.next();

		char[] firstname = namefirst.toCharArray();
		char[] lastname = namelast.toCharArray();
		System.out.println("Is it okay if I call you by your initials " + firstname[0] + "." + lastname[0] + "?");
	}

	public static void ProblemTwo()
	{
    	double sum, average, x;
    	int i;
    	char z;
    	String givennumbers;
    	Scanner user_input = new Scanner(System.in);

    	System.out.println("What would you like to enter as your three numbers?: ");
    	givennumbers = user_input.nextLine();
    	String numbers = givennumbers.replaceAll("[^0-9]", "");

    	int[] a = new int[numbers.length()];
    	x = numbers.length();
    	i = 0;
    	while (x > 0)
    	{
    		z = numbers.charAt(i);
  			a[i] = Character.getNumericValue(z);
  			i++;
    		x--;
    	}
    	
    	int sumsize = numbers.length();
    	i = 0;
    	sum = 0;
    	while (sumsize > 0)
    	{
    		sum += a[i];
    		i++;
    		sumsize--;
    	}
    	sumsize = numbers.length();
    	average = sum / sumsize;

    	System.out.println("The sum is: " + sum);
    	System.out.println("The average is: " + average);
	}

	public static void ProblemThree()
	{
    	double radiusCircle, area;
    	Scanner user_input = new Scanner(System.in);

    	System.out.println("What is the radius of the circle?:");
    	radiusCircle = user_input.nextInt();

    	area = Math.PI * (radiusCircle * radiusCircle);

    	System.out.println("The area of the circle is: " + area);
	}

	public static void ProblemFour()
	{
		double height, weight, age;
    	Scanner user_input = new Scanner(System.in);

    	System.out.println("What is your height in Centimeters?:");
    	height = user_input.nextDouble();
    	System.out.println("What is your age in years?:");
    	age = user_input.nextDouble();

    	weight = ((height - 100) + (age/10)) * (0.9);

    	System.out.println("Your suggested weight is: " + weight);
	}

	public static void ProblemFive()
	{
		char oldchar = 'r';
    	char newchar = 'X';
    	String letterreplacement = "Twinkle, Twinkle, Litte Star";
    	System.out.println(letterreplacement);
    	String newstring =  letterreplacement.replace(oldchar,newchar);
    	System.out.println(newstring);
	}

	public static void ProblemSix()
	{
		String inputstring;
    	int x = 3;
    	int a = 0;
    	Scanner user_input = new Scanner(System.in);

    	System.out.println("What string would you like to be processed?:");
    	inputstring = user_input.nextLine();
    	System.out.println("The first character is: " + inputstring.charAt(0));
    	System.out.println("The Index of A is: " + inputstring.indexOf('a') + " and " + inputstring.lastIndexOf('a'));
    	System.out.print("The first four characters are: ");
    	while (x >= 0)
    	{
    		System.out.print(inputstring.charAt(a));
    		a++;
    		x--;
    	}
    	System.out.println("\n" + "The length of the string is: " + inputstring.length());
    	System.out.println("The uppercase version of the string is: " + inputstring.toUpperCase());
	}

	public static void ProblemSeven()
	{
		String inputstring;
    	Scanner user_input = new Scanner(System.in);

    	System.out.println("What string would you like to be processed?: ");
    	inputstring = user_input.nextLine();
    	String numbers = inputstring.replaceAll("[^0-9]", "");
    	System.out.println(numbers.length() + " Numbers were found in that string.");
    	System.out.println("The numbers in your string were: " + numbers);
	}

    public static void main(String []args)
    { 
    	ProblemOne();
    	ProblemTwo();
    	ProblemThree();
    	ProblemFour();
    	ProblemFive();
    	ProblemSix();
    	ProblemSeven();
    }
}