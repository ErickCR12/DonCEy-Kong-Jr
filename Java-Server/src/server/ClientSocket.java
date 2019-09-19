package server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

class ClientSocket extends Thread {

    private Socket socket;
    private PrintWriter out;
    private BufferedReader in;

    ClientSocket(Socket socket) {
        this.socket = socket;
    }

    public void start() {
        System.out.println("Client running...");
        startIOStream();
        startListening();
    }

    private void startIOStream() {
        try {
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void startListening() {
        String message;
        try {
            while ((message = in.readLine()) != null) {
                System.out.printf("Server received: %s \n", message);

                if (message.equals("exit")) break;
                out.println(message);
            }
            stopListening();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void stopListening() throws IOException {
        System.out.println("Client closing...");
        in.close();
        out.close();
        socket.close();
    }
}
