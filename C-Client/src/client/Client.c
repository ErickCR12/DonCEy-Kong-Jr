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

int createSocket() {
    int status = socket(AF_INET, SOCK_STREAM, 0);
    if (status < 0) printf(SOCKET_ERROR);
    return status;
}

struct sockaddr_in serverAddress(struct sockaddr_in serverAddress) {
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    if(inet_pton(AF_INET, IP, &serverAddress.sin_addr) <= 0)
    {
        printf(ADDRESS_ERROR);
    }

    return serverAddress;
}

int connectServer(int socket, struct sockaddr_in serverAddress) {
    int status = connect(socket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (status < 0) {
        printf(CONNECTION_ERROR);
        status = -1;
    }
    return status;
}

void sendMessage(char *message) {
    write(sock, message, strlen(message));
    printf("Client send: %s \n", message);
}

char *readMessage() {
    char message[MAX];
    read(sock, message, sizeof(message));
    printf("Client read: %s \n", message);
    return message;
}
