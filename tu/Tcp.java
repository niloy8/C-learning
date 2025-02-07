
import java.util.Scanner;

public class Tcp {
    private int receiverWindow;
    private int bufferCapacity;
    private int senderWindow;
    private int dataUnit;
    private boolean isPaused;

    public Tcp(int capacity, int unitSize) {
        this.bufferCapacity = capacity;
        this.receiverWindow = capacity;
        this.senderWindow = 0;
        this.dataUnit = unitSize;
        this.isPaused = false;
    }

    public void startSimulation() {
        Scanner input = new Scanner(System.in);
        System.out.println("Starting Network Flow Control Simulation...");

        while (true) {
            if (!isPaused) {
                displayCurrentState();
                processDataTransfer();
            } else {
                processReceiverData(input);
            }

            if (!checkContinue(input)) {
                break;
            }
        }
        input.close();
    }

    private void displayCurrentState() {
        System.out.println("\nSender's Window Size: " + senderWindow);
        System.out.println("Receiver's Advertised Window (rwnd): " + receiverWindow);
    }

    private void processDataTransfer() {
        if (receiverWindow >= dataUnit) {
            System.out.println("Sending a packet of size: " + dataUnit);
            receiverWindow -= dataUnit;
            senderWindow += dataUnit;

            System.out.println("Updated rwnd: " + receiverWindow);
            System.out.println("Updated swnd: " + senderWindow);
        } else {
            System.out.println("Not enough space in receiver buffer. Pausing transmission...");
            isPaused = true;
        }
    }

    private void processReceiverData(Scanner input) {
        System.out.println("\nReceiver processing data...");
        System.out.print("Enter the amount of data processed by receiver: ");
        int processed = input.nextInt();

        if (processed <= senderWindow) {
            receiverWindow += processed;
            senderWindow -= processed;

            if (receiverWindow > 0) {
                System.out.println("Receiver has space available. Resuming transmission...");
                isPaused = false;
            }
        } else {
            System.out.println("Error: Processed data cannot exceed sender's window.");
        }
    }

    private boolean checkContinue(Scanner input) {
        System.out.print("\nDo you want to continue simulation? (yes/no): ");
        String response = input.next();
        if (response.equalsIgnoreCase("no")) {
            System.out.println("Simulation terminated.");
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner setup = new Scanner(System.in);

        System.out.println("Enter the receiver buffer size:");
        int bufferSize = setup.nextInt();

        System.out.println("Enter the packet size:");
        int packetSize = setup.nextInt();

        Tcp simulator = new Tcp(bufferSize, packetSize);
        simulator.startSimulation();

        setup.close();
    }
}