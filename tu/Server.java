
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(5000);
        System.out.println("Server is waiting to connect");
        Socket s = ss.accept();
        System.out.println("client connect " + s.getPort());

        DataInputStream in = new DataInputStream(s.getInputStream());
        DataOutputStream out = new DataOutputStream(s.getOutputStream());
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        String sendMsg = "";
        String recvMsg = "";
        System.out.println("Enter your msg ,type stop to end ");
        while (true) {

            // Receive message from the client
            recvMsg = in.readUTF();
            System.out.println("Client: " + recvMsg);
            // Read input from the user
            sendMsg = read.readLine();

            // Check if the user typed "stop"
            if (sendMsg.equals("stop")) {
                break; // Exit the loop if "stop" is typed
            }

            // Send the message to the server
            out.writeUTF(sendMsg);

        }
        ss.close();
        in.close();
        out.close();
        System.out.println("server is disconnected");

    }
}
