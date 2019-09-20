package server;

import java.io.*;
import java.net.Socket;
import java.util.TimerTask;

class ClientSocket extends Thread {

    private Socket socket;
    private BufferedReader in;
    private PrintWriter out;

    ClientSocket(Socket socket) {
        this.socket = socket;
    }

    public void start() {
        System.out.println("Client accepted");
        String message = listen();
        response(message);
        stopListening();
    }

    private String listen() {
        String message = "";
        try {
            in = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));

            message = in.readLine();
            System.out.printf("Server received: %s \n", message);

        } catch (IOException e) {
            e.printStackTrace();
        }

        return message;
    }

    private void response(String message) {
        try {
            out = new PrintWriter(socket.getOutputStream());

            out.println(message);
            out.flush();
            System.out.printf("Server send: %s \n", message);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void stopListening() {
        System.out.println("Client closing...");

        new java.util.Timer().schedule(
                new java.util.TimerTask() {
                    @Override
                    public void run() {
                        try {
                            in.close();
                            out.close();
                            socket.close();
                            stop();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                },
                5000
        );
    }
}
