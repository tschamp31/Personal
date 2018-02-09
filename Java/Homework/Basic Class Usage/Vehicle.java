public abstract class Vehicle
{
	private String owner;
	private int wheels;

	/**
	*Vehicle constructor
	*Constructs the Vehicle class
	*@param newOwner - name of owner, newWheels - wheel count
	*@return N/A
	*No other similar constructor in this class
	*/
	public Vehicle(String newOwner, int newWheels)
	{
		this.owner = newOwner;
		this.wheels = newWheels;
	}

	/**
	*getOwner Method
	*Returns the string of the variable owner
	*@param N/A
	*@return Returns string value
	*Similar to getWheels method
	*/
	public String getOwner()
	{
		return this.owner;
	}

	/**
	*getWheels Method
	*Returns the int value of wheels
	*@param N/A
	*@return Returns int value
	*Similar to getOwner method
	*/
	public int getWheels()
	{
		return this.wheels;
	}

	/**
	*setOwner Method
	*Sets the string of the variable owner
	*@param String value of the owner's name
	*@return N/A
	*Similar to setWheels method
	*/
	public void setOwner(String newOwner)
	{
		this.owner = newOwner;
	}

	/**
	*setWheels Method
	*Sets the int of the variable wheels
	*@param Int value of the wheel count
	*@return N/A
	*Similar to setOwner method
	*/
	public void setWheels(int newWheels)
	{
		this.wheels = newWheels;
	}

	/**
	*toString Method
	*Returns a string of the variables
	*@param N/A
	*@return String of text and variables
	*Similar nothing in this class.
	*/
	@Override
	public String toString()
	{
		return "Owner: " + this.owner + "\nWheel Count: " + this.wheels;
	}

	/**
	*equals Method
	*Returns a boolean value of whether two objects match
	*@param Object O of the similar class
	*@return Returns true if objects match
	*Similar nothing in this class.
	*/
	@Override
	public boolean equals(Object o)
	{
		if(o == this)
		{
			return true;
		}
		if(!(o instanceof Vehicle))
		{
			return false;
		}
		
		Vehicle temp = (Vehicle) o;
		return (owner == temp.owner) && (wheels == temp.wheels);
	}

	public abstract double horsePower();
}