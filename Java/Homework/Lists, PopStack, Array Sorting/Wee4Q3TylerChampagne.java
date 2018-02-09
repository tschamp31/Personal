public class Wee4Q3TylerChampagne
{
	static class Product
	{
		private String product;
		private Double price;

		public Product()
		{
			product = "";
			price = 0;
		}

		public double SetPrice(Double value)
		{
			price = value;
		}
		public double SetName(String name)
		{
			product = name;
		}
		public double InceasePrice(Double amount)
		{
			price += amount;
		}
		public double GetPrice()
		{
			return price;
		}
		public String ChangeName(String newname)
		{
			product = newname;
		}
		public String GetName()
		{
			return product;
		}
	}
	public static void main(String[] args)
	{

	}
}