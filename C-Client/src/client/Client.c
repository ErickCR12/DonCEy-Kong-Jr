//
// Created by José Acuña on 12/09/2019.
//

#include "Client.h"

void start() {
    server_address = (struct sockaddr_in *) malloc(sizeof(struct sockaddr_in));
    sock = createSocket();
    serverAddress(server_address);
    connectServer(sock, server_address);
}

void stop() {
    free(server_address);
}

int createSocket() {
    int status = socket(AF_INET, SOCK_STREAM, 0);
    if (status < 0) printf(SOCKET_ERROR);
    return status;
}

int serverAddress(struct sockaddr_in *serverAddress) {\
    int status = 0;
    serverAddress->sin_family = AF_INET;
    serverAddress->sin_port = htons(PORT);
    serverAddress->sin_addr.s_addr = inet_addr(IP);

    return status;
}

int connectServer(int socket, struct sockaddr_in *serverAddress) {
    int status = connect(socket,  (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (status < 0) {
        printf(CONNECTION_ERROR);
        status = -1;
    }
    return status;
}

void sendMessage(char *message) {
    send(sock, message, strlen(message), 0);
    printf("Client send: %s", message);
}

char *readMessage(char *message) {
    read(sock, message, sizeof(message));
    printf("Client read: %s", message);
    return message;
}