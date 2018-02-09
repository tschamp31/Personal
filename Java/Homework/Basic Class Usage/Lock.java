class Lock
{
	private int x;// declares class variables
	private int y;
	private int z;
	private int top;
	private boolean lock;

	//sets up constructor including 0 variables and unlock
	Lock()
	{
		this.x = 0;
		this.y = 0;
		this.z = 0;
		this.lock = false;
	}
// allows a combination to be set
void setCombo(int x, int y, int z)
{
	this.x = x;
	this.y = y;
	this.z = z;
}

//turns lock based on which number it is
boolean turnLock(int currentNumber, int combinationPosition)
{
	if(combinationPosition == 1) //sets the rotation for the first number and solves it
	        {
	            int counter = 0;
	            for(int i = 0; i >= 0; i --)
	            {
	                top = i;
	                System.out.print(" " + top + " ");
	                if(top == currentNumber)
	                    counter ++;
	                if(counter == 2 && top == currentNumber)
	                {
	                    if(top == this.x)
	                    {
	                        System.out.println("\n\n");
	                        return true;
	                    }
	                    else
	                    	return false;
	                }
	                if(top == 0)
	                    i = 40;
	            }
	        }


    else if(combinationPosition == 2)//sets the rotation for the second number and solves it
    {
        int counter = 0;

        for(int i = top; i <= 39; i++)
        {
            top = i;
            System.out.print(" " + top + " ");
            if(top == currentNumber)
                counter++;

            if(counter == 2 && top == currentNumber)
            {
                if(top == this.y)
                {
                    System.out.println("\n\n");
                    return true;
                }
                else
                	return false;
            }

            if(top == 39)
            {
                i = -1;
            }
        }
    }
    else if(combinationPosition == 3) //rotates for the third number and solves it
    {
        int counter = 0;
        for(int i = top; i >= 0; i--)
        {
            top = i;
            System.out.print(" " + top + " ");
            if(top == currentNumber)
            {
                if(top == this.z)
                {
                    System.out.println("\n\n");
                    return true;
                }
                else
                	return false;
            }
            if(top == 0)
            {
                i = 40;
            }
        }
    }
    else 
    	return false; //if everything failes it cancels out the lock rotation attempt
    return false;


}


void closeLock()
{
	this.lock = false;//locks the lock
}

void attemptLock(int x, int y, int z)
{
	boolean xtest = false;//sets up tests for each lock number and then attempts them providing a return whether the lock was solved or not.
	boolean ytest = false;
	boolean ztest = false;

	xtest = turnLock(x, 1);
	System.out.println();

	ytest = turnLock(y, 2);
	System.out.println();

	ztest = turnLock(z, 3);
	System.out.println();

	if(xtest == true && ytest == true && ztest == true)
		{
			this.lock = false;
			System.out.println("Lock: OPEN!");

		}
	else
		System.out.println("Lock: CLOSED!");

}

boolean checkLock()
{
	return this.lock;//checks to see if it is locked or unlocked
}

int checkTop()
{
	return this.top;//checks the current top number
}
}