package server;

import java.io.IOException;
import java.net.ServerSocket;

public class Server {

    private Server instance;
    private ServerSocket serverSocket;
    private int ip;
    private int port;

    private Server(int port) {
        this.ip = 0;
        this.port = port;
    }

    public Server getInstance(int port) {
        if (instance == null) instance = new Server(port);
        return instance;
    }

    public void start() throws IOException {
        serverSocket = new ServerSocket(port);
        startListening();
    }

    private void startListening() throws IOException {
        while (true) {
            new ClientSocket(serverSocket.accept())
                    .start();
        }
    }

    public void stop() throws IOException {
        serverSocket.close();
    }

    public int getIp() {
        return ip;
    }

    public int getPort() {
        return port;
    }
}
