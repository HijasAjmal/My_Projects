import java.io.*;
import java.net.*;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.event.*;
import javax.swing.JLabel;
class Tcpc
{
	public static JFrame f;
	public static JLabel l;
	public static JButton b1;
	public static JTextArea ta,ta1;
	public static byte[] sendData = new byte[1024];
	public static byte[] receiveData = new byte[1024];
	public static String sentence,modifiedSentence;
	public static BufferedReader inFromUser;
	public static DataOutputStream outToServer;
	public static Socket connectionSocket;
	public static InetAddress IPAddress;
	public static BufferedReader inFromServer;
	public static DatagramPacket sendPacket,receivePacket;
	public Tcpc()
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
		Tcpc o = new Tcpc();
		//Get the ipAddress=-------------
		connectionSocket = new Socket("localhost",45454 );
		//Client waiting for message
		while(true){
			try
			{					
				inFromServer = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
				sentence = inFromServer.readLine();
				//Set received message to the TextArea
				ta.setText(ta.getText()+"\n=>"+sentence);
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
				outToServer = new DataOutputStream(connectionSocket.getOutputStream());
				sentence = ta1.getText();
				outToServer.writeBytes(sentence + '\n');
				
				ta1.setText("");
			}catch(SocketException e){
				e.printStackTrace();
			}catch(IOException e){
				e.printStackTrace();
			}
		}
	}
}

