import javax.swing.ImageIcon;
import java.awt.Image;
import java.util.Random;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

class Tree
{
	private Game game;
	Image img;
	Random rand = new Random();
	int height, width;
	int randomSpot;
	int x = 0;
	int y = 0;
	
	public Tree(Game game, int amount)
	{
		this.game = game;

		ImageIcon i = new ImageIcon("images/trees.png");
		img = i.getImage();
		this.width = img.getWidth(null);
		this.height = img.getHeight(null);
		switch(amount)
		{
			case 1:
				this.x = 0;
				break;
			case 2:
				this.x = 138;
				break;
			case 3:
				this.x = 276;
				break;
			case 4:
				this.x = 414;
				break;
			case 5:
				this.x = 552;
				break;
		}

	}
//Tree Coords
// 0,0
// 138,0
// 276,0
// 414,0
// 552,0


	void paint(Graphics g)
	{
		g.drawImage(this.img, this.x, this.y, null);
	}
}