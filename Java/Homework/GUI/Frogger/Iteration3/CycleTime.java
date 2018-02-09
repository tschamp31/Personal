public class CycleTime
{
	int time = 0;

	public void add()
	{
		this.time += 1;
	}

	public void set(int value)
	{
		this.time = value;
	}
	public void reset()
	{
		this.time = 0;
	}

	public void subtract()
	{
		this.time -= 1;
	}

	public int returnTime()
	{
		return this.time;
	}
}