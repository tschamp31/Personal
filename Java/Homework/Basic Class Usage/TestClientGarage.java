import java.util.*;

public class TestClientGarage
{
	public static void main(String[] args)
	{
		Garage g1 = new Garage();
		g1.addCar(new Auto("Honda",80000,12));
		g1.addCar(new Auto("Jeep" ,100000,20));
		g1.addCar(new Auto("Mazda",90000,16));
		Garage g2 = new Garage();
		g2.addCar(new Auto("Audi",100,20));
		g2.addCar(new Auto("Ferrari",100,24));
		g2.addCar(new Auto("Mazda",100,20));

		System.out.println("Garage Object: G1(Arraylist) Contains Auto Objects " + "\n" + g1);
		System.out.println("");
		System.out.println("Garage Object: G2(Arraylist) Contains Auto Objects " + "\n" + g2);
		System.out.println("");

		if(g1.equals(g2))
		{
			System.out.println("The Garages Are Equal");
		}
		else
		{
			System.out.println("The Garages Are Not Equal");
		}

		ArrayList<Auto> temp = g2.getCars();
		g1.setCars(temp);

		if(g1.equals(g2))
		{
			System.out.println("After changing g1, the garages are equal");
		}
		else
		{
			System.out.println("After changing g1, the garages are not equal");
		}

		System.out.println("Average number of miles per car in garage: " + g1.averageMiles());
		System.out.println("Total gallons used by cars in garage: " + g1.totalGallons());

		System.out.println("\n With 3 cars, garage occupancy: " + g1.occupancy());

		for(int i = 0; i < 30; i++)
		{
			g1.addCar(new Auto());
		}
		System.out.println("After adding 30 cars, garage occupancy: " + g1.occupancy());

		for(int i = 0; i < 80; i++)
		{
			g1.addCar(new Auto());
		}
		System.out.println("After adding 30 cars, garage occupancy: " + g1.occupancy());
	}

}