public class VehicleClient
{
	public static void main(String[] args)
	{
		MotorizedVehicle mv1 = new MotorizedVehicle("Mike", 4, 3.2);
		MotorizedVehicle mv2 = new MotorizedVehicle("Mike", 4, 4.0);
		System.out.println("[" + mv1 + "]has " + mv1.horsePower() + " horsepower ");

		mv2.setOwner(mv1.getOwner());

		if(mv1.equals(mv2))
		{
			System.out.println("Mv1 and Mv2 are equal");
		}
		else
		{
			System.out.println("Mv1 and Mv2 are not equal");
		}

		mv2.setVolumeDisplacement(mv1.getVolumeDisplacement());

		if(mv1.equals(mv2))
		{
			System.out.println("Mv1 and Mv2 are now equal.");
		}
		else
		{
			System.out.println("Mv1 and Mv2 are still not equal");
		}

		Bicycle b2 = new Bicycle("Jane",2);
		System.out.println("\nb2 is " + b2);
	}
}