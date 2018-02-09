class Rational
{
	int numerator;
	int denominator;

	Rational(int numerator, int denominator)
	{
		this.numerator = numerator; //sets the numer and denom without allowing 0
		
		if(denominator == 0)
		{
			this.denominator = 1;
			System.out.println("Denominator can not be set to 0, defaulted to 1.");
		}
		else
		{
			this.denominator = denominator;
		}
	}

	Rational()
	{
		this.numerator = 0; //sets the numer and denom as a default
		this.denominator = 1;
	}

	void printRational()
	{
		if(this.numerator < 0 || this.denominator < 0) //prints out the numer and denom based on whether it is a negative fraction or positive
		{
			System.out.println("-"+this.numerator+"/"+this.denominator);
		}
		else
		{
			System.out.println(this.numerator+"/"+this.denominator);
		}
	}

	void normalize()
	{
		int divisor;//reduces the fraction to a simplified form
		divisor = Rational.gcd(this.numerator, this.denominator);
		this.numerator = this.numerator / divisor;
		this.denominator = this.denominator / divisor;
	}

	static int gcd(int a, int b)
	{
        int c; // finds the greatest common denominator for the normalizing
        while (b != 0) 
        {
	        c = a % b;
	        a = b;
	        b = c;
        }
        return a;
    }

    public void addition(Rational x)
    {
        int greatdenom = x.denominator * this.denominator;       //adds the fractions together
        int multx = greatdenom / x.denominator;
        int mult = greatdenom / this.denominator;

        this.denominator = x.denominator * this.denominator;
        this.numerator = (x.numerator * multx) + (this.numerator * mult);

        normalize();
    }

    public void minus(Rational x)
    {
        int greatdenom = x.denominator * this.denominator; //subtracts the fractions       
        int multx = greatdenom / x.denominator;
        int mult = greatdenom / this.denominator;

        this.denominator = x.denominator * this.denominator;

        if (x.numerator > this.numerator)
        {
        	this.numerator = (x.numerator * multx) - (this.numerator * mult);
        }
        else 
        {
        	this.numerator = (this.numerator * mult) - (x.numerator * multx);
        }

        normalize();
    }

    public void multiply(Rational x)
    {
        this.numerator = this.numerator * x.numerator;//multiplies the factions
        this.denominator = this.denominator * x.denominator;
        normalize();
    }

    public void divide(Rational x)
    {
        this.numerator = this.numerator / x.numerator;//divides the fractions
        this.denominator = this.denominator / x.denominator;
        normalize();
    }
}