import java.sql.*;
import java.net.*;
import javax.swing.*;
import java.awt.event.*;
public class Calculator
{
    JFrame f;
    float First_number,Second_number,Sum;
    JTextArea ta,ta2,ta3;
    JLabel l,l2,l3,l4;
    JButton b1,b2,b3,b4,b5,b6,b7;
    public Calculator()
    {
        f = new JFrame("Calculator");
        ta = new JTextArea();
        ta2 = new JTextArea();
        ta3 = new JTextArea();
        l = new JLabel("CALCULATOR");
        l2 = new JLabel("First Number");
        l3 = new JLabel("Second Number");
        l4 = new JLabel("Total");
        b1 = new JButton("+");
        b2 = new JButton("-");
        b3 = new JButton("*");
        b4 = new JButton("/");
        b5 = new JButton("%");
        b6 = new JButton("Exit");
        b7 = new JButton("CLEAR");
        l4.setBounds(650,130,620,130);
        l4.setSize(150,50);
        l3.setBounds(400,130,450,130);
        l3.setSize(200,50);
        l2.setBounds(120,130,200,130);
        l2.setSize(200,50);
        l.setBounds(450,20,1000,30);
        l.setSize(1000,100);
        ta.setBounds(120,180,200,180);
        ta.setSize(200,50);
        ta2.setBounds(400,180,450,180);
        ta2.setSize(200,50);
        ta3.setBounds(650,180,620,180);
        ta3.setSize(150,50);
        b1.setBounds(200,280,250,280);
        b2.setBounds(320,280,350,280);
        b3.setBounds(440,280,480,280);
        b4.setBounds(580,280,630,280);
        b5.setBounds(200,340,250,340);
        b6.setBounds(580,340,600,340);
        b7.setBounds(400,340,430,340);
        b1.setSize(100,50);
        b2.setSize(100,50);
        b3.setSize(100,50);
        b4.setSize(100,50);
        b5.setSize(100,50);
        b6.setSize(100,50);
        b7.setSize(100,50);
        b1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                new Add();
            }
        });
        b2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                new Substraction();
            }
        });
        b3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                new Multiplication();
            }
        });
        b4.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                new Division();
            }
        });
        b5.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                new Modulus();
            }
        });
        b6.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                new Exit_App();
            }
        });
        b7.addActionListener(new ActionListener(){
                         public void actionPerformed(ActionEvent ae){
                                              new Clear_f();
                                                           }
                                  });

        f.add(l4);
        f.add(l3);
        f.add(l2);
        f.add(b7);
        f.add(b6);
        f.add(b5);
        f.add(b4);
        f.add(b3);
        f.add(b2);
        f.add(b1);
        f.add(l);
        f.add(ta3);
        f.add(ta2);
        f.add(ta);
        f.setSize(1000,1000);
        f.setLayout(null);
        f.setVisible(true);
    }
    public static void main(String [] args)
    {
        Calculator o = new Calculator();
    }
    public class Add
    {
        Add()
        {
            First_number =Float.parseFloat(ta.getText());
            Second_number =Float.parseFloat(ta2.getText());
            Sum = First_number + Second_number;
            ta3.setText(Float.toString(Sum));
        }
    }
    public class Substraction
    {
        Substraction()
        {
            First_number =Float.parseFloat(ta.getText());
            Second_number =Float.parseFloat(ta2.getText());
            Sum = First_number - Second_number;
            ta3.setText(Float.toString(Sum));
        }
    }
    public class Multiplication
    {
        Multiplication()
        {
            First_number =Float.parseFloat(ta.getText());
            Second_number =Float.parseFloat(ta2.getText());
            Sum = First_number * Second_number;
            ta3.setText(Float.toString(Sum));
        }
    }
    public class Division
    {
        Division()
        {
            First_number =Float.parseFloat(ta.getText());
            Second_number =Float.parseFloat(ta2.getText());
            Sum = First_number / Second_number;
            ta3.setText(Float.toString(Sum));
        }
    }
    public class Modulus
    {
        Modulus()
        {
            First_number =Float.parseFloat(ta.getText());
            Second_number =Float.parseFloat(ta2.getText());
            Sum = First_number % Second_number;
            ta3.setText(Float.toString(Sum));
        }
    }
    public class Clear_f
    {
        Clear_f()
        {
            ta.setText("");
            ta2.setText("");
            ta3.setText("");
        }
    }
    public class Exit_App
    {
        Exit_App()
        {
            System.exit(0);
        }
    }
}
