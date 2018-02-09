import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class DistanceConverter
{
  public DistanceConverter distance;
  public JLabel answer = new JLabel();
  public JTextField  inputField = new JTextField(10);
  //Coding segment is so submethods can access it, especially the action performed.

  public double convertToMiles(double input)
  {
      return (input * 0.62137);
  }

  public double convertToFeet(double input)
  {
    return (input * 3280.8);
  }

  public double convertToInches(double input)
  {
    return (input * 39370);
  }
  //All the conversion methods needed


  public DistanceConverter()
  {

      JFrame window = new JFrame("Lab 10 ----> Distance Converter");
      Container content = window.getContentPane();
      JLabel text = new JLabel("Enter Distance In Kilometers...");
      JSeparator separator = new JSeparator(SwingConstants.HORIZONTAL);
      JRadioButton miles = new JRadioButton("Convert To Miles");
      JRadioButton feet = new JRadioButton("Convert To Feet");
      JRadioButton inches = new JRadioButton("Convert To Inches");
      //Declaration of multiple objects in order it goes - Window, Container Manager, Separator, Radio buttons. 

      ButtonGroup bG = new ButtonGroup();
      bG.add(miles);
      bG.add(feet);
      bG.add(inches);
      //So that the radio buttons cant be clicked all together

      content.setLayout(new GridLayout(0,1));
      content.add(text);
      content.add(inputField);
      content.add(separator);
      content.add(miles);
      content.add(feet);
      content.add(inches);
      content.add(answer);
      //Adds the UI in order. Text -> input box -> separator -> radio buttons -> output text.


      miles.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) 
        {
          double kilometers = 0;

            if(inputField.getText() != null && !inputField.getText().isEmpty())
            {
                kilometers = Double.parseDouble(inputField.getText());
            }
            answer.setText(convertToMiles(kilometers) + "");
        }
        });

      feet.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) 
        {
          double kilometers = 0;
          String output = "";

            if(inputField.getText() != null && !inputField.getText().isEmpty())
            {
                kilometers = Double.parseDouble(inputField.getText());
            }
            answer.setText(convertToFeet(kilometers) + "");
        }
      });

      inches.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) 
        {
          double kilometers = 0;

            if(inputField.getText() != null && !inputField.getText().isEmpty())
            {
                kilometers = Double.parseDouble(inputField.getText());
            }
            answer.setText(convertToInches(kilometers) + "");
        }
        });
        //Based on the radio button that is checked is how it calls the conversion methods then sets the output text to it. 


      window.setSize( 375, 200 );
      window.setLocationRelativeTo(null);
      window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      window.setVisible( true );

      //Window size, can move, can be closed, and is visible not hidden.
  }

	public static void main( String [] args )
 	{
    DistanceConverter app = new DistanceConverter();
    //Runs all the given methods above.

 	}
}