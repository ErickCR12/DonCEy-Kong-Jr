package server;

import java.io.*;
import java.net.Socket;

class ClientSocket extends Thread {

    private Socket socket;
    private DataOutputStream out;
    private DataInputStream in;

    ClientSocket(Socket socket) {
        this.socket = socket;
    }

    public void start() {
        System.out.println("Client accepted");
        startIOStream();
        startListening();
    }

    private void startIOStream() {
        try {
            out = new DataOutputStream(socket.getOutputStream());
            in = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void startListening() {
        String message = "";
        try {
            while (!message.equals("exit")) {
                message = in.readUTF();
                System.out.printf("Server received: %s \n", message);
                response(message);
            }
            stopListening();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void response(String message) {
        try {
            out.writeUTF(message);
            System.out.printf("Server send: %s \n", message);
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
