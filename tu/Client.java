import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client {

    public static void main(String[] args) throws IOException {
        Socket s = new Socket("localhost", 5000);
        System.out.println("client is connected " + s.getLocalPort());

        DataOutputStream out = new DataOutputStream(s.getOutputStream());
        DataInputStream in = new DataInputStream(s.getInputStream());

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        String sendMsg = "";
        String recvMsg = "";
        System.out.println("Enter your msg ,type stop to end ");
        while (true) {
            // Read input from the user
            sendMsg = read.readLine();
            // Check if the user typed "stop"
            if (sendMsg.equals("stop")) {
                break; // Exit the loop if "stop" is typed
            }

            // Send the message to the server
            out.writeUTF(sendMsg);

            // Receive message from the server
            recvMsg = in.readUTF();
            System.out.println("Server: " + recvMsg);
        }
        s.close();
        in.close();
        out.close();
        System.out.println("client is disconnected");

    }
}
