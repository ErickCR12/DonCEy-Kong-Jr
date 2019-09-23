package server;

import java.io.*;
import java.net.Socket;
import java.util.TimerTask;

/**
 * Manages the clients connections and IOStream
 * @author José Acuña
 */
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

    /**
     * Receives InputStream from the socket
     * last modified: 19 Set by Jose Acuna
     * @return creates a response for the Client and returns it as a String
     */
    private String listen() {
        String message = "";
        try {
            in = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));

            message = in.readLine();
            System.out.printf("Server received: %s \n", message);
            Integer gameID = JsonParser.parseGame(message);
            message = JsonParser.serializeGame(gameID);

        } catch (IOException e) {
            e.printStackTrace();
        }

        return message;
    }

    /**
     * Output the given message to the client
     * last modified: 19 Set by Jose Acuna
     * @param message the response to send
     */
    private void response(String message) {
        try {
            out = new PrintWriter(socket.getOutputStream());

            out.println(message + "\0");
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
