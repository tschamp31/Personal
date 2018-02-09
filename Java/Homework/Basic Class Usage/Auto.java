public class Auto
{
	public int countAutos;
	public String model;
	public int milesDriven;
	public double gallonsOfGas;

	Auto()
	{
		this.model = "";
		this.milesDriven = 0;
		this.gallonsOfGas = 0;
		this.countAutos++;
	}
	
	Auto(String startModel, int startMilesDriven, double startGallonsOfGas)
	{
		this.model = startModel;
		this.milesDriven = startMilesDriven;
		this.gallonsOfGas = startGallonsOfGas;
		this.countAutos++;
	}
	
	public double calculateMilesPerGallon()
	{
		return this.milesDriven/this.gallonsOfGas;
	}

	@Override
	public boolean equals(Object o)
	{
		if(o == this)
		{
			return true;
		}
		if(!(o instanceof Auto))
		{
			return false;
		}
		
		Auto temp = (Auto) o;
		return (model == temp.model) && (milesDriven == temp.milesDriven) && (gallonsOfGas == temp.gallonsOfGas);
	}

	public int getCountAutos()
	{
		return this.countAutos;
	}

	public double getGallonsOfGas()
	{
		return this.gallonsOfGas;
	}

	public int getMilesDriven()
	{
		return this.milesDriven;
	}

	public String getModel()
	{
		return this.model;
	}

	public void setGallonsOfGas(double newGallonsOfGas)
	{
		this.gallonsOfGas = newGallonsOfGas;
	}

	public void setMilesDriven(int newMilesDriven)
	{
		this.milesDriven = newMilesDriven;
	}

	public void setModel(String newModel)
	{
		this.model = model;
	}

	public String toString()
	{
		return "\n" + "\n" + "Model: " + this.model + "\n" + "Miles Driven: " + this.milesDriven + "\n" + "Gallons of Gas: " + this.gallonsOfGas;
	}
}