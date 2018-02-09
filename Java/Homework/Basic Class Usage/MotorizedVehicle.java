public class MotorizedVehicle extends Vehicle
{
	private double volumeDisplacement;

	/**
	*MotorizedVehicle constructor
	*Constructs the MotorizedVehicle class
	*@param newOwner - name of owner, newWheels - wheel count, newVolumeDisplacement - Volume displacement in liters
	*@return N/A
	*No other similar constructor in this class
	*/
	public MotorizedVehicle(String newOwner, int newWheels, double newVolumeDisplacement)
	{
		super(newOwner,newWheels);
		this.volumeDisplacement = newVolumeDisplacement;
	}

	/**
	*getVolumeDisplacement Method
	*Returns the double value of Volume Displacement in liters
	*@param N/A
	*@return Returns double value
	*Similar to nothing in this class.
	*/
	public double getVolumeDisplacement()
	{
		return this.volumeDisplacement;
	}

	/**
	*setVolumeDisplacement Method
	*Sets the double value of Volume Displacement in liters
	*@param Sets the double value of Volume Displacement in liters.
	*@return N/A
	*Similar to nothing in this class.
	*/
	public void setVolumeDisplacement(double newVolumeDisplacement)
	{
		this.volumeDisplacement = newVolumeDisplacement;
	}

	/**
	*toString Method
	*Returns a string of the variables
	*@param N/A
	*@return String of text and variables
	*Similar nothing in this class.
	*/
	public String toString()
	{
		return "Owner: " + super.getOwner() + "\nWheel Count: " + super.getWheels() + "\nVolume Displacement(Liters): " + this.volumeDisplacement;
	}

	/**
	*equals Method
	*Returns a boolean value of whether two objects match
	*@param Object O of the similar class
	*@return Returns true if objects match
	*Similar nothing in this class.
	*/
	public boolean equals(Object o)
	{
		if(o == this)
		{
			return true;
		}
		if(!(o instanceof MotorizedVehicle))
		{
			return false;
		}
		
		MotorizedVehicle temp = (MotorizedVehicle) o;
		return (super.getOwner() == temp.getOwner()) && (super.getWheels() == temp.getWheels()) && (volumeDisplacement == temp.volumeDisplacement);
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
		return super.getWheels() * this.volumeDisplacement;
	}
}