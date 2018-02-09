/* JButtonPractice, Programming Activity 1
   Anderson, Franceschi
*/

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class JButtonPractice extends JFrame
{
 Container contents;
 // GUI components
 private JButton open;
 private JButton close;
 private Circuit circuit;

 private static JButtonPractice app;
 private boolean firstTime = true;

 public JButtonPractice( )
 {
  super( "Choose your activity" );
  contents = getContentPane( );
  contents.setLayout( new FlowLayout( ) );

  circuit = new Circuit( );

  open = new JButton( "OPEN" );
  contents.add( open );
  close = new JButton( "CLOSE" );
  contents.add( close );

  open.addActionListener(new ActionListener() {

      public void actionPerformed(ActionEvent e) {
        open();
        animate();
      }
    });
  close.addActionListener(new ActionListener() {

      public void actionPerformed(ActionEvent e) {
        close();
        animate();
        
      }
    });

  setSize( 500, 375 );
  setVisible( true );
 }

public void actionPerformed(ActionEvent e) 
  {
  
  }


 // end of task 2

 public void open( )
 {
  circuit.open( );
 }

 public void close( )
 {
  circuit.close( );
 }

 private void animate( )
 {
  try
  {
   repaint( );
   Thread.sleep( 200 );
  }
  catch ( InterruptedException e )
  {
   System.out.println( "IE Exception " + e.getMessage( ) );
   System.out.println( e.toString( ) );
  }
 }

 public void paint( Graphics g )
 {
  if ( firstTime )
    firstTime = false;
  super.paint( g );
  circuit.draw( g );
 }

 public static void main( String [] args )
 {
  app = new JButtonPractice( );
  app.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
 }
}