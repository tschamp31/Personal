import javax.swing.ImageIcon;
import java.awt.Image;
import java.util.Random;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

class Fly
{
	private Game game;
	Image img;
	Random rand = new Random();
	int height, width;
	int randomSpot;
	int x = 0;
	int y = 0;
	
	public Fly(Game game)
	{
		this.game = game;

		ImageIcon i = new ImageIcon("images/butterfly.png");
		img = i.getImage();
		this.width = img.getWidth(null);
		this.height = img.getHeight(null);
	}

	void paint(Graphics g)
	{
		g.drawImage(this.img, this.x, this.y, null);
	}
}