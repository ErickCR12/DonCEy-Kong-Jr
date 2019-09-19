//
// Created by José Acuña on 12/09/2019.
//

#include <afxres.h>
#include "Client.h"

void start() {
    printf(CLIENT_START);
    initWinSock();
    sock = createSocket();
    server_address = serverAddress(server_address);
    connectServer(sock, server_address);
}

void stop() {
    printf(CLIENT_STOP);
    free(wsa);
    close(sock);
}

void initWinSock() {
    wsa = malloc(sizeof(wsa));
    if (WSAStartup(MAKEWORD(2,2),wsa) != 0)
        printf(WINSOCK_ERROR);
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
    sendMessage(message);
    return readMessage();
}

void sendMessage(char *message) {
    if (send(sock, message, strlen(message), 0) < 0)
        printf(CLIENT_SEND_FAILED);
    printf("Client send: %s \n", message);
}

char *readMessage() {
    char *message[MAX];
    if (recv(sock, *message, sizeof(message), 0) == SOCKET_ERROR)
        printf(CLIENT_READ_FAILED);
    printf("Client read: %s \n", *message);
    return *message;
}
