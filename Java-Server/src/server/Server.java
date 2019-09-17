package server;

import java.io.IOException;
import java.net.ServerSocket;

public class Server {

    private Server instance;
    private ServerSocket serverSocket;
    private Integer ip;
    private Integer port;

    private Server(Integer port) {
        this.ip = 0;
        this.port = port;
    }

    public Server getInstance(Integer port) {
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

    public Integer getIp() {
        return ip;
    }

    public Integer getPort() {
        return port;
    }
}
