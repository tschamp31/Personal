import javax.swing.ImageIcon;
import java.awt.Image;
import java.util.Random;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

class Frog
{
	private Game game;
	Image img;
	int height, width;
	int x = 0;
	int y = 612;

	public Frog(Game game)
	{
		this.game = game;

		ImageIcon i = new ImageIcon("images/frog.png");
		img = i.getImage();
		this.width = img.getWidth(null);
		this.height = img.getHeight(null);

	}

	void up()
	{
		this.y += -35;
	}

	void down()
	{
		this.y += 35;
	}

	void left()
	{
		this.x += -38;
	}

	void right()
	{
		this.x += 38;
	}

	void paint(Graphics g)
	{
		g.drawImage(this.img, this.x, this.y, null);
	}
}