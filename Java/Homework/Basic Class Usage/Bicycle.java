public class Bicycle extends Vehicle
{

	/**
	*Bicycle constructor
	*Constructs the MotorizedVehicle class
	*@param newOwner - name of owner, newWheels - wheel count
	*@return N/A
	*No other similar constructor in this class
	*/
	public Bicycle(String newOwner, int newWheels)
	{
		super(newOwner,newWheels);
	}

	/**
	*horsePower Method
	*Returns the double value of Horsepower
	*@param N/A
	*@return Returns double value
	*Similar to nothing in this class.
	*/
	public double horsePower()
	{
		return 0;
	}
}