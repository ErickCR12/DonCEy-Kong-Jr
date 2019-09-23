//
// Created by José Acuña on 12/09/2019.
//

#include "Client.h"

void start() {
    printf(CLIENT_START);
    sock = createSocket();
    server_address = serverAddress(server_address);
    connectServer(sock, server_address);
}

void stop() {
    printf(CLIENT_STOP);
    close(sock);
}

SOCKET createSocket() {
    SOCKET status = socket(AF_INET, SOCK_STREAM, 0);
    if (status < 0) printf(SOCK_ERROR);
    return status;
}

struct sockaddr_in serverAddress(struct sockaddr_in serverAddress) {
    serverAddress.sin_addr.S_un.S_addr = inet_addr(IP);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    return serverAddress;
}

int connectServer(SOCKET socket, struct sockaddr_in serverAddress) {
    int status = connect(socket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (status < 0) {
        printf(CONNECTION_ERROR);
        status = -1;
    }
    return status;
}

char *message(char *message) {
    start();
    sendMessage(message);
    message = readMessage();
    stop();
    return message;
}

void sendMessage(char *message) {
    if (send(sock, message, strlen(message), 0) < 0)
        printf(CLIENT_SEND_FAILED);
    else printf("Client send: %s \n", message);
    send(sock, "\n", strlen("\n"), 0);
}

char *readMessage() {
    char response[MAX];
    if (recv(sock, response, MAX, 0) == SOCKET_ERROR)
        printf(CLIENT_READ_FAILED);
    else printf("Client read: %s \n", response);

    char *result = {response};
    return result;
}
