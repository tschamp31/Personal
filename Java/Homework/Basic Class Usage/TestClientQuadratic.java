import java.util.Scanner;

public class TestClientQuadratic
{
	public void Process(Quadratic equation)
	{
		System.out.println("Quadratic Equation: " + equation);

		if(!equation.isQuadratic())
		{
			System.out.println("Linear Equation, one real root.");
			System.out.println("The Root Is: " + (equation.c / equation.b));
		}
		else if(equation.hasDoubleRealRoot())
		{
			System.out.println("Double Real Roots");
			System.out.println("Root 1: " + equation.r1 + " Root 2: " + equation.r2);

		}
		else if(equation.hasDistinctRealRoots())
		{
			System.out.println("Two Distinct Real Roots");
			System.out.println("Root 1: " + equation.r1 + " Root 2: " + equation.r2);
		}
		else if(equation.hasComplexRoots())
		{
			ComplexPair answer = new ComplexPair();
			answer = equation.solveQuadratic();
			System.out.println("Two Distinct Complex Roots");
			System.out.println("Root 1: " + answer.first + " Root 2: " + answer.second);

		}
	}

	public static void main(String[] args)
	{
		TestClientQuadratic test = new TestClientQuadratic();
		Scanner s = new Scanner(System.in);
		char answer;
		int a,b,c;
		Quadratic equation1 = new Quadratic(0,2,6);
		Quadratic equation2 = new Quadratic(-2,4,-2);
		Quadratic equation3 = new Quadratic(1,4,3);
		Quadratic equation4 = new Quadratic(-1,2,-5);

		test.Process(equation1);
		test.Process(equation2);
		test.Process(equation3);
		test.Process(equation4);

		while(true)
		{
			System.out.println("Would you like to enter a custom equation?(Y/N)");
			answer = s.next().charAt(0);
			if(answer == 'Y')
			{
				System.out.println("Enter the A, B, C of equation(ax^2+bx+c)");
				System.out.println("Enter A(Enter 0 if linear): ");
				a = s.nextInt();
				System.out.println("Enter B: ");
				b = s.nextInt();
				System.out.println("Enter C: ");
				c = s.nextInt();
			}
			else
			{
				break;
			}

			Quadratic equation5 = new Quadratic(a,b,c);
			test.Process(equation5);
		}
	}
}