import javax.swing.ImageIcon;
import java.awt.Image;
import java.util.Random;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

class LgCarLeft
{
	private Game game;
	Image img;
	Random rand = new Random();
	int height, width;
	int randomImage;
	int	xV = -1;
	int x = 0;
	int y = 0;
	Boolean killstatus = false;

	public LgCarLeft(Game game, int lane, int direction)
	{
		this.game = game;

		randomImage = rand.nextInt(6);

		ImageIcon [] possibleImagesLeft = 
		{ 
			new ImageIcon("images/lgCarsLeft/lgCar1.png"),
			new ImageIcon("images/lgCarsLeft/lgCar2.png"),
			new ImageIcon("images/lgCarsLeft/lgCar3.png"),
			new ImageIcon("images/lgCarsLeft/lgCar4.png"),
			new ImageIcon("images/lgCarsLeft/lgCar5.png"),
			new ImageIcon("images/lgCarsLeft/lgCar6.png"),
		};

		String stringValue = Integer.toString(randomImage);

		ImageIcon i = new ImageIcon("images/lgCarsLeft/lgCar" + stringValue + ".png");
		this.img = i.getImage();
		this.width = img.getWidth(null);
		this.height = img.getHeight(null);

		switch(lane)
		{
			case 1:
				this.x = 644;
				this.y = 571;
				break;
			case 2:
				this.x = 644;
				this.y = 521;
				break;
			case 3:
				this.x = 644;
				this.y = 476;
				break;
			case 4:
				this.x = 644;
				this.y = 426;
				break;
			case 5:
				this.x = 644;
				this.y = 333;
				break;
			case 6:
				this.x = 644;
				this.y = 281;
				break;
		}
	}
	//lanes from bottom up
	//lane 1 - 571
	//lane 2 - 521
	//lane 3 - 476
	//lane 4 - 426
	//lane 5 - 333
	//lane 6 - 281
	
	public void setkill()
	{
		this.killstatus = true;
	}

	public Boolean getkill()
	{
		return this.killstatus;
	}

	public void resetkill()
	{
		this.killstatus = false;
	}

	void move()
	{
		if (this.x + this.xV < 0 - this.width)
			setkill();

		this.x += this.xV;
	}

	void paint(Graphics g)
	{
		g.drawImage(this.img, this.x, this.y, null);
	}
}