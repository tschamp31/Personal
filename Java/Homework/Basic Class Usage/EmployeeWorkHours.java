import java.util.Scanner;
import java.util.Arrays;

public class EmployeeWorkHours
{
	public static void main (String argv [])
	{
		Scanner user_input = new Scanner(System.in);
		String holderS; 
		int rows, columns, row, column, holderI, total;
		holderI = 0;
		total = 0;
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		System.out.println("How many employees do you have?");
		rows = user_input.nextInt() + 1;
		columns = 8;

		int[] workHoursTotal =  new int[rows];
		String[][] workHours = new String[rows][columns];
		workHours[0][0] = "\t\t\t";
		workHours[0][1] = "Sun ";
		workHours[0][2] = "Mon ";
		workHours[0][3] = "Tue ";
		workHours[0][4] = "Wed ";
		workHours[0][5] = "Thur ";
		workHours[0][6] = "Fri ";
		workHours[0][7] = "Sat ";
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		for(row = 1; row < rows; row++)
		{
			workHours[row][0] = "Employee " + row;
		}
		for(row = 1; row < rows; row++)
		{
			for(column = 1; column < columns; column++)
			{
				System.out.println("How many hours did " + workHours[row][0] + " work on " + workHours[0][column] + "?");
				holderI = user_input.nextInt();
				workHours[row][column] = Integer.toString(holderI);
			}
		}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		for(row = 0; row < rows; row++)
		{
			for(column = 0; column < columns; column++)
			{
				System.out.print(workHours[row][column] + " ");
				System.out.print("\t");
				if(row > 0)
				{
					System.out.print("\t");
				}
			}
			System.out.println();
		}

		System.out.println();
		System.out.println();
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		for(row = 1; row < rows; row++)
		{
			for(column = 1; column < columns; column++)
			{
				holderI = Integer.parseInt(workHours[row][column]);
				total = total + holderI;
			}
			workHoursTotal[row] = total;
			total = 0;
			holderI = 0;
		}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
		Arrays.sort(workHoursTotal);
		for(row = rows - 1; row > 0; row--)
		{
			System.out.println(workHours[row][0] + " worked " + workHoursTotal[row] + " hours.");
		}
	}
}