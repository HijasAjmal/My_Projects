import java.io.*;
import java.net.*;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.event.*;
import javax.swing.JLabel;

class Tcps
{
	public static int port;
	public static JFrame f;
	public static JTextArea ta;
	public static BufferedReader inFromClient;
	public static Socket connectionSocket;
	public static DataOutputStream outToClient;
	public static String clientSentence;
	public static ServerSocket serverSocket;
	public static String sentence;
	public static int in_num, c;
	public Tcps()
	{
		f = new JFrame("Server");
		ta = new JTextArea();
		ta.setBounds(20,20,450,200);
		f.add(ta);
		f.setSize(500,500);
		f.setLayout(null);
		f.setVisible(true);
	} 
	public static void main(String args[]) throws Exception
	{
		Tcps o = new Tcps();
		//Socket-------------
		serverSocket = new ServerSocket(45454);
		connectionSocket = serverSocket.accept();
		//Server waiting for message
		while(true){
			try
			{       
				inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
				clientSentence = inFromClient.readLine();
				in_num = Integer.parseInt(clientSentence);
				//Set received message to the TextArea
				c =1;
				ta.setText(ta.getText()+"\n=>From Client::"+in_num);
				for (int i = 2; i <= in_num/2; i++) {
      					if (in_num % i == 0) {
        			 	c=2;
        			 	break;
    			  }
			  }
			  if(c == 2)
			  	sentence = "Is Not Prime";
			  else
			  	sentence = "Is Prime";
			  outToClient = new DataOutputStream(connectionSocket.getOutputStream());
				outToClient.writeBytes(sentence + '\n');
				ta.setText(ta.getText()+"\n=>Me::"+sentence);
			}catch(SocketException e){
				e.printStackTrace();
			}catch(IOException e){
				e.printStackTrace();
			}
		}
	}
}
