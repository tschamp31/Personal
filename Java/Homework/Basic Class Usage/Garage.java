import java.util.*;


public class Garage
{
	private ArrayList<Auto> cars = new ArrayList<Auto>();

	Garage()
	{

	}

	public void addCar(Auto car)
	{
		if(this.cars.size() == 100)
		{
			System.out.println("Garage Full; Can Not Add Another Car");
		}

		else
		{
			this.cars.add(car);
		}
	}

	public double averageMiles()
	{
		int count = 0;
		int averageMiles = 0;

		for(int i = 0; i < cars.size(); i++)
		{
			averageMiles += this.cars.get(i).getMilesDriven();
			count ++;
		}

		averageMiles /= count;

		return averageMiles;
	}

	@Override
	public boolean equals(Object o)
	{
		if(o == this)
		{
			return true;
		}

		if(!(o instanceof Garage))
		{
			return false;
		}

		Garage temp = (Garage) o;

		return (o instanceof Garage) && cars.equals(((Garage)o).cars);
	}

	public ArrayList<Auto> getCars()
	{
		return this.cars;
	}

	public String occupancy()
	{
		if(this.cars.size() < 25)
		{
			return "Below Minimum(Under 25 Cars)";
		}

		else if(this.cars.size() < 100 && this.cars.size() >= 25)
		{
			return "Normal Load: " + this.cars.size();
		}

		else if(this.cars.size() == 100)
		{
			return "Full(100 Cars)";
		}

		else
		{
			return "ERROR";
		}

	}

	public void setCars(ArrayList<Auto> newCars)
	{
		this.cars = (ArrayList<Auto>)newCars.clone();
	}

	public String toString()
	{
		return "Cars In The Garage: " + "\n" + this.cars;
	}

	public double totalGallons()
	{
		int totalGallons = 0;

		for(int i = 0; i < this.cars.size(); i++)
		{
			totalGallons += this.cars.get(i).getGallonsOfGas();
		}

		return totalGallons;
	}

}