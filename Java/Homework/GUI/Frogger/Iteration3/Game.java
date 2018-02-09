import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.Ellipse2D;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.ImageIcon;
import java.util.*;
import java.awt.Rectangle;
import java.awt.Image;

public class Game extends JPanel
{
	Image img;
	Random rand = new Random();
	int lane1 = 0;
	int lane2 = 0;
	int lane3 = 0;
	int lane4 = 0;
	int lane5 = 0;
	int lane6 = 0;
	int l1d,l2d,l3d,l4d,l5d,l6d;

	Frog frog = new Frog(this);

	CycleTime timerr = new CycleTime();
	ArrayList<CycleTime> timerrlist = new ArrayList<CycleTime>();

	Animal animal = new Animal(this,0);
	ArrayList<Animal> animalList = new ArrayList<Animal>();

	LgCarLeft lgCarLeft = new LgCarLeft(this,0,0);
	ArrayList<LgCarLeft> lgCarLeftList = new ArrayList<LgCarLeft>();

	LgCarRight lgCarRight = new LgCarRight(this,0,0);
	ArrayList<LgCarRight> lgCarRightList = new ArrayList<LgCarRight>();

	Log log = new Log(this,0,0);
	ArrayList<Log> logList = new ArrayList<Log>();

	SmCar smCar = new SmCar(this,0,0);
	ArrayList<SmCar> smCarList = new ArrayList<SmCar>();

	Fly fly = new Fly(this);
	ArrayList<Fly> flyList = new ArrayList<Fly>();
	
	Tree tree = new Tree(this, 0);
	ArrayList<Tree> treelist = new ArrayList<Tree>();


	public Game()
	{
		addKeyListener(new KeyListener() {
			@Override
			public void keyTyped(KeyEvent e) 
			{
			}
			@Override
			public void keyReleased(KeyEvent e) 
			{
			}
			@Override
			public void keyPressed(KeyEvent e) 
			{
				keyPressedd(e);
			}
		});
		setFocusable(true);

		ImageIcon i = new ImageIcon("images/background.png");
		img = i.getImage();

		timerrlist.add(new CycleTime());

		this.l1d = rand.nextInt(1) + 1;
		this.l2d = rand.nextInt(1) + 1;
		this.l3d = rand.nextInt(1) + 1;
		this.l4d = rand.nextInt(1) + 1;
		this.l5d = rand.nextInt(1) + 1;
		this.l6d = rand.nextInt(1) + 1;
	}


		public void keyPressedd(KeyEvent e)
	{
		if(e.getKeyCode() == KeyEvent.VK_UP)//Moves Frogger Up
		{
			frog.up();
		}
		if(e.getKeyCode() == KeyEvent.VK_DOWN)//Moves Frogger Down
		{
			frog.down();
		}
		if(e.getKeyCode() == KeyEvent.VK_LEFT)//Moves Frogger Left
		{
			frog.left();
		}
		if(e.getKeyCode() == KeyEvent.VK_RIGHT)//Moves Frogger Right
		{
			frog.right();
		}
	}

	private void move()
	{
		for(Animal animal : animalList) animal.move();
		for(LgCarLeft lgCarLeft : lgCarLeftList) lgCarLeft.move();
		for(LgCarRight lgCarRight : lgCarRightList) lgCarRight.move();
		for(Log log : logList) log.move();
		for(SmCar smCar : smCarList) smCar.move();
	}

	void collision()
	{

	}

	private void killstatus()
	{
		for(Animal animal : animalList)
		{
			if(animal.getkill() == true)
			{
				kill(0);
				break;
			}
		}

		for(LgCarLeft lgCarLeft : lgCarLeftList)
		{
			if(lgCarLeft.getkill() == true)
			{
				kill(1);
				break;
			}
		}

		for(LgCarRight lgCarRight : lgCarRightList)
		{
			if(lgCarRight.getkill() == true)
			{
				kill(2);
				break;
			}
		}

		for(Log log : logList)
		{
			if(log.getkill() == true)
			{
				kill(3);
				break;
			}
		}

		for(SmCar smCar : smCarList) 
		{
			if(smCar.getkill() == true)
			{
				kill(4);
				break;
			}
		}
	}

	void kill(int object)
	{
		switch(object)
		{
			case 0:
				animalList.remove(0);
				break;
			case 1:
				lgCarLeftList.remove(0);
				break;
			case 2:
				lgCarRightList.remove(0);
				break;
			case 3:
				logList.remove(0);
				break;
			case 4:
				smCarList.remove(0);
				break;
		}
	}

	void spawn()
	{
		for(CycleTime timerr : timerrlist) timerr.add();
		int treemax, treemin, randomCar, carmax, carmin, animalmin, animalmax;
		long lastSpawned;

		treemax = 5;
		treemin = treelist.size();

		if(treemin != treemax)
		{
			treelist.add(new Tree(this, treemin));
			treemin++;
		}

		carmax = 644;

		if(timerrlist.get(0).returnTime() > 50)
		{
			if(lane1 < carmax)//lane 1
			{
				randomCar = rand.nextInt(3);
				switch(randomCar)
				{
					case 0:
						smCarList.add(new SmCar(this,1,l1d));
						this.lane1 += 57;
						break;
					case 1:
						lgCarLeftList.add(new LgCarLeft(this,1,l1d));
						this.lane1 += 104;
						break;
					case 2:
						lgCarRightList.add(new LgCarRight(this,1,l1d));
						this.lane1 += 104;
						break;
				}
			}

			if(lane2 < carmax)//lane 2
			{
				randomCar = rand.nextInt(3);
				switch(randomCar)
				{
					case 0:
						smCarList.add(new SmCar(this,2,l2d));
						this.lane2 += 57;
						break;
					case 1:
						lgCarLeftList.add(new LgCarLeft(this,2,l2d));
						this.lane2 += 104;
						break;
					case 2:
						lgCarRightList.add(new LgCarRight(this,2,l2d));
						this.lane2 += 104;
						break;
				}
			}

			if(lane3 < carmax)//lane 3
			{
				randomCar = rand.nextInt(3);
				switch(randomCar)
				{
					case 0:
						smCarList.add(new SmCar(this,3,l3d));
						this.lane3 += 57;
						break;
					case 1:
						lgCarLeftList.add(new LgCarLeft(this,3,l3d));
						this.lane3 += 104;
						break;
					case 2:
						lgCarRightList.add(new LgCarRight(this,3,l3d));
						this.lane3 += 104;
						break;
				}
			}

			if(lane4 < carmax)//lane 4
			{
				randomCar = rand.nextInt(3);
				switch(randomCar)
				{
					case 0:
						smCarList.add(new SmCar(this,4,l4d));
						this.lane4 += 57;
						break;
					case 1:
						lgCarLeftList.add(new LgCarLeft(this,4,l4d));
						this.lane4 += 104;
						break;
					case 2:
						lgCarRightList.add(new LgCarRight(this,4,l4d));
						this.lane4 += 104;
						break;
				}
			}

			if(lane5 < carmax)//lane 5
			{
				randomCar = rand.nextInt(3);
				switch(randomCar)
				{
					case 0:
						smCarList.add(new SmCar(this,5,l5d));
						this.lane5 += 57;
						break;
					case 1:
						lgCarLeftList.add(new LgCarLeft(this,5,l5d));
						this.lane5 += 104;
						break;
					case 2:
						lgCarRightList.add(new LgCarRight(this,5,l5d));
						this.lane5 += 104;
						break;
				}
			}

			if(lane6 < carmax)//lane 6
			{
				randomCar = rand.nextInt(3);
				switch(randomCar)
				{
					case 0:
						smCarList.add(new SmCar(this,6,l6d));
						this.lane6 += 57;
						break;
					case 1:
						lgCarLeftList.add(new LgCarLeft(this,6,l6d));
						this.lane6 += 104;
						break;
					case 2:
						lgCarRightList.add(new LgCarRight(this,6,l6d));
						this.lane6 += 104;
						break;
				}
			}

			timerrlist.get(0).reset();
		}

		animalmin = animalList.size();
		animalmax = 2;

		if(animalmin != animalmax)
		{
			animalList.add(new Animal(this, animalmin));
			animalmin++;
		}
	}

	public void paint(Graphics g)
	{
		super.paint(g);
		Graphics2D g2d = (Graphics2D) g;
		g2d.drawImage(img, 0, 0, null);
		g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

		for(Animal animal : animalList) animal.paint(g);
		for(LgCarLeft lgCarLeft : lgCarLeftList) lgCarLeft.paint(g);
		for(LgCarRight lgCarRight : lgCarRightList) lgCarRight.paint(g);
		for(Log log : logList) log.paint(g);
		for(SmCar smCar : smCarList) smCar.paint(g);

		for(Fly fly : flyList) fly.paint(g);
		for(Tree tree : treelist) tree.paint(g);
		frog.paint(g);
	}

	public static void main(String [] args) throws InterruptedException 
	{
		JFrame frame = new JFrame("Frogger");
		Game game = new Game();
		frame.setSize(650, 672);
		frame.add(game);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setVisible(true);

		while(true)
		{
			game.killstatus();
			game.spawn();
			game.move();
			game.collision();
			game.repaint();
			Thread.sleep(10);
		}
	}
}