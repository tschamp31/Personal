import javax.swing.ImageIcon;
import java.awt.Image;
import java.util.Random;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

class LgCarRight
{
	private Game game;
	Image img;
	Random rand = new Random();
	int height, width;
	int randomImage, randomLane;
	int	xV = 1;
	int x = 0;
	int y = 0;
	Boolean killstatus = false;

	public LgCarRight(Game game, int lane, int direction)
	{
		this.game = game;

		randomImage = rand.nextInt(6);

		ImageIcon [] possibleImagesLeft = 
		{ 
			new ImageIcon("images/lgCarsRight/lgCar1.png"),
			new ImageIcon("images/lgCarsRight/lgCar2.png"),
			new ImageIcon("images/lgCarsRight/lgCar3.png"),
			new ImageIcon("images/lgCarsRight/lgCar4.png"),
			new ImageIcon("images/lgCarsRight/lgCar5.png"),
			new ImageIcon("images/lgCarsRight/lgCar6.png"),
		};
		String stringValue = Integer.toString(randomImage);

		ImageIcon i = new ImageIcon("images/lgCarsRight/lgCar" + stringValue + ".png");
		this.img = i.getImage();
		this.width = img.getWidth(null);
		this.height = img.getHeight(null);

		switch(lane)
		{
			case 1:
				this.x -= this.width;
				this.y = 571;
				break;
			case 2:
				this.x -= this.width;
				this.y = 521;
				break;
			case 3:
				this.x -= this.width;
				this.y = 476;
				break;
			case 4:
				this.x -= this.width;
				this.y = 426;
				break;
			case 5:
				this.x -= this.width;
				this.y = 333;
				break;
			case 6:
				this.x -= this.width;
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
		if (this.x + this.xV > game.getWidth() + this.width)
			setkill();

		this.x += this.xV;
	}

	void paint(Graphics g)
	{
		g.drawImage(this.img, this.x, this.y, null);
	}
}