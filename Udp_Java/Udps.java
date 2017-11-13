import java.io.*;
import java.net.*;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.event.*;
import javax.swing.JLabel;

class Udps
{
	public static int port;
	public static JFrame f;
	public static JLabel l;
	public static JButton b1;
	public static JTextArea ta,ta1;
	public static byte[] receiveData = new byte[1024];
	public static byte[] sendData = new byte[1024];
	public static DatagramPacket receivePacket;
	public static InetAddress IPAddress;
	public static String capitalizedSentence;
	public static DatagramPacket sendPacket;
	public static DatagramSocket serverSocket;
	public static String sentence;
	public Udps()
	{
		f = new JFrame("Server");
		b1 = new JButton("Send");
		ta = new JTextArea();
		ta1 = new JTextArea();
		l = new JLabel("Type Here...");
		b1.setBounds(190,410,210,450);
		//Button event
		b1.addActionListener( new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				new sendTo();
		}
		});
		//Layout section
		b1.setSize(100,50);
		ta.setBounds(20,20,450,200);
		ta1.setBounds(20,300,400,430);
		l.setBounds(20,220,400,300);
		f.add(l);
		ta1.setSize(450,50);
		f.add(ta1);
		f.add(ta);
		f.add(b1);
		f.setSize(500,500);
		f.setLayout(null);
		f.setVisible(true);
	} 
	public static void main(String args[]) throws Exception
	{
		Udps o = new Udps();
		//Socket-------------
		serverSocket = new DatagramSocket(9876);
		//Server waiting for message
		while(true){
			try
			{
				
				receivePacket = new DatagramPacket(receiveData, receiveData.length);
				serverSocket.receive(receivePacket);
				sentence = new String( receivePacket.getData());
				//Set received message to the TextArea
				ta.setText(ta.getText()+"\n=>From Client:"+sentence);
			}catch(SocketException e){
				e.printStackTrace();
			}catch(IOException e){
				e.printStackTrace();
			}
			IPAddress = receivePacket.getAddress();
				port = receivePacket.getPort();
		}
	}
	public class sendTo
	{
		//Function to send the message(to client)
		sendTo()
		{	
			try
			{
				
				sentence = ta1.getText();
				sendData = sentence.getBytes();
				sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
				serverSocket.send(sendPacket);
				ta.setText(ta.getText()+"\n=>Me:"+sentence);
				ta1.setText("");
			}catch(IOException e){
				e.printStackTrace();
			}
		}
	}
}
