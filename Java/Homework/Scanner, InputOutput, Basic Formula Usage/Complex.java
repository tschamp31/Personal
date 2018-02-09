public class Complex
{
	private double imaginary;
	private double real;

	Complex(double newReal, double newImaginary)
	{
		this.imaginary = newImaginary;
		this.real = newReal;
	}

	public boolean equals(Object o)
	{
		if(o == this)
		{
			return true;
		}
		if(!(o instanceof Complex))
		{
			return false;
		}
		
		Complex temp = (Complex) o;

		return (imaginary == temp.imaginary) && (real == temp.real);
	}

	public double getImaginary()
	{
		return this.imaginary;
	}

	public double getReal()
	{
		return this.real;
	}

	public boolean isReal()
	{
		return (this.imaginary > 0);
	}

	public void setImaginary(double newImaginary)
	{
		this.imaginary = newImaginary;
	}

	public void setReal(double newReal)
	{
		this.real = newReal;
	}

	public String toString()
	{
		return real + "+" + "(" + imaginary + "i" + ")";
	}
}