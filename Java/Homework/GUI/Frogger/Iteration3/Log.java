import javax.swing.ImageIcon;
import java.awt.Image;
import java.util.Random;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

class Log
{
	private Game game;
	Image img;
	Random rand = new Random();
	int height, width;
	int randomLane, randomDirection;
	int	xV = 1;
	int x = 0;
	int y = 0;
	Boolean killstatus = false;
	
	public Log(Game game,  int lane, int direction)
	{
		this.game = game;

		ImageIcon i = new ImageIcon("images/log.png");
		img = i.getImage();
		this.width = img.getWidth(null);
		this.height = img.getHeight(null);
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
		if (this.x + this.xV > game.getWidth() + this.width * 2)
			setkill();
		if (this.x + this.xV < 0 - this.width * 2)
			setkill();
		this.x += this.xV;
	}

	void paint(Graphics g)
	{
		g.drawImage(this.img, this.x, this.y, null);
	}
}