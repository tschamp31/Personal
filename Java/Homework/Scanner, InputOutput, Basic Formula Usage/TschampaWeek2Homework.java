import java.util.Scanner;

public class TschampaWeek2Homework 
{
	// public static void ProblemOne()
	// {
	// 	int trigger, position, inputnumber, sum;
	// 	float result, listsize;
	// 	int[] inputnumberlist;
	// 	inputnumberlist = new int[100];
	// 	trigger = 0;
	// 	position = 1;
	// 	listsize = -1;
	// 	sum = 0;
	// 	Scanner user_input = new Scanner(System.in);

	// 	System.out.println("Type another number: ");
	// 	inputnumber = user_input.nextInt();
	// 	inputnumberlist[0] = inputnumber;

	// 	do
	// 	{
	// 		System.out.println("Type another number: ");
	// 		inputnumber = user_input.nextInt();
	// 		inputnumberlist[position] = inputnumber;
	// 		position++;
	// 	}while(inputnumber > trigger);

	// 	position = position - 1;

	// 	while(position >= 0)
	// 	{
	// 		sum += inputnumberlist[position];
	// 		listsize++;
	// 		position--;
	// 	}
	// 	result = sum / listsize;
	// 	System.out.println("The average of the numbers entered is: " + (result));
	// }

	// public static void ProblemTwo()
	// {
	// 	int start, end, increment;
	// 	startnum = 100;
	// 	endnum = 5;
	// 	increment = 5;
	// 	while(startnum >= endnum)
	// 	{
	// 		System.out.println(startnum);
	// 		startnum -= increment;
	// 	}
	// 	for(startnum = 100; startnum >= endnum; startnum -= increment)
	// 	{
	// 		System.out.println(startnum);
	// 	}
	// }

	// public static void ProblemThree()
	// {
	// 	String inputstring;
	// 	int i;
	// 	i = 0;
	// 	Scanner user_input = new Scanner(System.in);
	// 	System.out.println("What is the string you would like to be processed?: ");
	// 	inputstring = user_input.nextLine();
	// 	System.out.println("The string you entered is: " + inputstring);
	// 	System.out.print("The string you entered backwards is: " );
	// 	String[] processedstring = inputstring.split("");
	// 	i = inputstring.length();
	// 	while(i >= 0)
	// 	{
	// 		System.out.print(processedstring[i]);
	// 		i--;
			
	// 	}

	// }

	public static void ProblemFour()
	{
		String List[], string;
		List = new String[10];
		int lexis1, lexis2;
		Scanner user_input = new Scanner(System.in);
		System.out.println("What is your first input string?: ");
		List[1] = "ssss";
		System.out.println("What is your second input string?: ");
		string = "ssss";
		System.out.println(List[1].compareTo(null) < List[1].compareTo(null));
		// if(lexis1 < lexis2)
		// {
		// 	System.out.println(inputstringone);
		// }
		// else if(lexis2 < lexis1)
		// {
		// 	System.out.println(inputstringtwo);
		// }
		// else if(lexis1 == lexis2)
		// {
		// 	System.out.println("The strings are equal.");
		// }
	}

	// static class Sailboat
	// {
	// 	public static double CalculateHullSpeed(double lwl)
	// 	{
	// 		return (1.34 * Math.sqrt(lwl));
	// 	}
	// 	public static double CalculateDtoL(double lwl,double displacement)
	// 	{
	// 		return ((displacement/2240)/(Math.pow((0.01*lwl), 3)));
	// 	}
	// 	public static double CaculateSAtoD(double sailarea, double displacement)
	// 	{
	// 		return (sailarea/(Math.pow((displacement/64),0.667)));
	// 	}
	// 	public static double CalculateCapI(double beam, double displacement)
	// 	{
	// 		return (beam/(Math.pow((displacement/64),0.333)));
	// 	}
	// 	public static double CalculateCI(double displacement, double loa, double beam, double lwl)
	// 	{
	// 		return (displacement/(0.65*(((0.7*lwl)+(0.3*loa))*Math.pow(beam, 1.33))));
	// 	}
	// 	public static void main()
	// 	{
	// 		double lwl,displacement,sailarea,beam,loa, hullspeed, dtol, satod, capi, ci;
	// 		Scanner user_input = new Scanner(System.in);

	// 		System.out.println("What is the length at waterline of the boat?");
	// 		lwl = user_input.nextDouble();
	// 		System.out.println("What is the Displacement of the boat?");
	// 		displacement = user_input.nextDouble();
	// 		System.out.println("What is the Sail Area of the boat?");
	// 		sailarea = user_input.nextDouble();
	// 		System.out.println("What is the Beam of the boat?");
	// 		beam = user_input.nextDouble();
	// 		System.out.println("What is the overall length of the boat?");
	// 		loa = user_input.nextDouble();

	// 		hullspeed = Sailboat.CalculateHullSpeed(lwl);
	// 		dtol = Sailboat.CalculateDtoL(lwl,displacement);
	// 		satod = Sailboat.CaculateSAtoD(sailarea,displacement);
	// 		capi = Sailboat.CalculateCapI(beam,displacement);
	// 		ci = Sailboat.CalculateCI(displacement,loa,beam,lwl);

	// 		System.out.println("The Hull Speed is: " + hullspeed);
	// 		System.out.println("The Displacement to ship length is: " + dtol);
	// 		System.out.println("The sail area to displacement is: " + satod);
	// 		System.out.println("The capsize screening is: " + capi);
	// 		System.out.println("The comfort index is: " + ci);
	// 	}
	// }

    public static void main(String []args)
    {
    	ProblemFour();
    }
}
