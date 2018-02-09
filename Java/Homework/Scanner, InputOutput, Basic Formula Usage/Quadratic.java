public class Quadratic
{
	public int a;
	public int b;
	public int c;
	public double d;
	public double v;
	public double r1;
	public double r2;
	public String comment;

	Quadratic(int newA, int newB, int newC)
	{
		this.a = newA;
		this.b = newB;
		this.c = newC;
	}

	private int discriminat()
	{
		int answer;

		answer = ((this.b*this.b)+(-4*this.a*this.c));

		return answer;
	}

	public boolean equals(Object o)
	{
		return this == o;
	}

	public int getA()
	{
		return this.a;
	}

	public int getB()
	{
		return this.b;
	}

	public int getC()
	{
		return this.c;
	}

	public String getComment()
	{
		return this.comment;
	}

	public boolean isQuadratic()
	{
		if(this.a == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	public boolean hasDistinctRealRoots()
	{
		this.d = discriminat();
		this.v = -this.b / (2 * this.a);
		this.r1 = Math.sqrt(d) / (2 * this.a) + v;
		this.r2 = -Math.sqrt(d) / (2 * this.a) + v;


		if(d >= 0 && (r1 != r2))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	public boolean hasDoubleRealRoot()
	{
		this.d = discriminat();
		this.v = -this.b / (2 * this.a);
		this.r1 = Math.sqrt(d) / (2 * this.a) + v;
		this.r2 = -Math.sqrt(d) / (2 * this.a) + v;


		if(d >= 0 && (r1 == r2))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	public boolean hasComplexRoots()
	{
		if((hasDoubleRealRoot() && hasDistinctRealRoots()) == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	public void setA(int newA)
	{
		this.a = newA;
	}

	public void setB(int newB)
	{
		this.b = newB;
	}

	public void setC(int newC)
	{
		this.c = newC;
	}

	public ComplexPair solveQuadratic()
	{
		double v = -this.b / (2 * this.a);
		double d = discriminat();

		Complex r1 = new Complex(v,(Math.sqrt(-d) / (2*this.a)));
		Complex r2 = new Complex(v,(-Math.sqrt(-d) / (2*this.a)));

		ComplexPair answer = new ComplexPair(r1,r2);

		return answer;

	}

	public String toString()
	{
		return this.a + "x^2 + " + this.b + "x + " + "(" + this.c + ")";
	}
}