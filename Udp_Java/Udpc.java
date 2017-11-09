import java.io.*;
import java.net.*;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.event.*;
import javax.swing.JLabel;
class Udpc
{
	public static JFrame f;
	public static JLabel l;
	public static JButton b1;
	public static JTextArea ta,ta1;
	public static byte[] sendData = new byte[1024];
	public static byte[] receiveData = new byte[1024];
	public static String sentence,modifiedSentence;
	public static BufferedReader inFromUser;
	public static DatagramSocket clientSocket;
	public static InetAddress IPAddress;
	public static DatagramPacket sendPacket,receivePacket;
	public Udpc()
	{
		f = new JFrame("Client");
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
		ta1.setSize(450,50);
		f.add(l);
		f.add(ta1);
		f.add(ta);
		f.add(b1);
		f.setSize(500,500);
		f.setLayout(null);
		f.setVisible(true);
	} 
	public static void main(String args[]) throws Exception
	{
		Udpc o = new Udpc();
		//Get the ipAddress=-------------
		IPAddress = InetAddress.getByName("localhost");
		clientSocket = new DatagramSocket();
		//Client waiting for message
		while(true){
			try
			{		
				receivePacket = new DatagramPacket(receiveData, receiveData.length);
				clientSocket.receive(receivePacket);
				modifiedSentence = new String(receivePacket.getData());
				//Set received message to the TextArea
				ta.setText(ta.getText()+"\n=>"+modifiedSentence);
			}catch(SocketException e){
				e.printStackTrace();
			}catch(IOException e){
				e.printStackTrace();
			}
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
				sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
				clientSocket.send(sendPacket);
				ta1.setText("");
			}catch(SocketException e){
				e.printStackTrace();
			}catch(IOException e){
				e.printStackTrace();
			}
		}
	}
}

