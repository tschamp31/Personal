public class ComplexPair
{
	public Complex first;
	public Complex second;

	ComplexPair(Complex newFirst, Complex newSecond)
	{
		this.first = (Complex) newFirst;
		this.second = (Complex) newSecond;
	}

	ComplexPair()
	{
		
	}

	public boolean bothIdentical()
	{
		return this.first == this.second;
	}

	public boolean equals(Object o)
	{
		if(o == this)
		{
			return true;
		}

		if(!(o instanceof ComplexPair))
		{
			return false;
		}
		
		ComplexPair temp = (ComplexPair) o;
		
		return (first == temp.first) && (second == temp.second);
	}

	public Complex getFirst()
	{
		return this.first;
	}

	public Complex getSecond()
	{
		return this.second;
	}

	public void setFirst(Complex newFirst)
	{
		this.first = newFirst;
	}

	public void setSecond(Complex newSecond)
	{
		this.second = newSecond;
	}

	public String toString()
	{
		return "Complex 1: " + this.first + "\n" + "Complex 2: " + this.second;
	}
}