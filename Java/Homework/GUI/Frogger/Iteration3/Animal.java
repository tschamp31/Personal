import javax.swing.ImageIcon;
import java.util.Random;
import java.awt.Image;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.awt.Rectangle;

class Animal
{
	private Game game;
	Image img, imgData;
	BufferedImage bufferedImage;
	AffineTransform tx;
	AffineTransformOp op;
	Random rand = new Random();
	int height, width, randomLane;
	int	xV = 1;
	int x = 0;
	int y = 0;
	Boolean killstatus = false;


	public Animal(Game game,  int lane)
	{
		this.game = game;

		ImageIcon i = new ImageIcon("images/animal.png");
		this.img = i.getImage();
		this.width = img.getWidth(null);
		this.height = img.getHeight(null);
		this.bufferedImage = toBufferedImage(this.img);

		flip();

		this.x += this.width;
		this.y += this.height;
		randomLane = 1;

		switch(lane)
		{
			case 0:
				this.y = 379; 
				break;
			case 1:
				this.y = 239;
				break;
		}
	}

	public static BufferedImage toBufferedImage(Image img)
	{
	    if(img instanceof BufferedImage)
	    {
	        return (BufferedImage) img;
	    }

	    // Create a buffered image with transparency
	    BufferedImage bimage = new BufferedImage(img.getWidth(null), img.getHeight(null), BufferedImage.TYPE_INT_ARGB);

	    // Draw the image on to the buffered image
	    Graphics2D bGr = bimage.createGraphics();
	    bGr.drawImage(img, 0, 0, null);
	    bGr.dispose();

	    // Return the buffered image
	    return bimage;
	}

	void flip()
	{
		tx = AffineTransform.getScaleInstance(-1, 1);
    	tx.translate(-this.width, 0);
    	op = new AffineTransformOp(tx, AffineTransformOp.TYPE_NEAREST_NEIGHBOR);
    	this.bufferedImage = op.filter(this.bufferedImage, null);

	}

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
		if(this.x + this.xV > game.getWidth() - this.width)
		{
			flip();
			this.xV *= -1;
		}
		if(this.x + this.xV < 0)
		{
			flip();
			this.xV *= -1;
		}

		this.x += this.xV;
	}

	void paint(Graphics g)
	{
		g.drawImage(this.bufferedImage, this.x, this.y, null);
	}
}