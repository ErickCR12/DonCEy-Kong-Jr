package server;

import java.io.IOException;
import java.net.ServerSocket;

public class Server extends Thread {

    private static Server instance;
    private ServerSocket serverSocket;
    private Integer ip;
    private Integer port;

    private Server(Integer port) {
        this.ip = 0;
        this.port = port;
    }

    public static Server getInstance(Integer port) {
        if (instance == null) instance = new Server(port);
        return instance;
    }

    @Override
    public void run() {
        try {
            System.out.println("Server running...");
            serverSocket = new ServerSocket(port);
            startListening();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void startListening() throws IOException {
        while (true) {
            new ClientSocket(serverSocket.accept())
                    .start();
        }
    }

    public Integer getIp() {
        return ip;
    }

    public Integer getPort() {
        return port;
    }
}
