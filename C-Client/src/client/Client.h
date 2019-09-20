//
// Created by atlas on 18/09/19.
//

#ifndef C_CLIENT_CLIENT_H
#define C_CLIENT_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <unistd.h>
#include <string.h>
#include "../res/strings_values.h"

#define IP "127.0.0.1"
#define PORT 9999
#define MAX 1024

SOCKET sock;
struct sockaddr_in server_address;

void start();

void stop();

SOCKET createSocket();

struct sockaddr_in serverAddress(struct sockaddr_in);

int connectServer(SOCKET , struct sockaddr_in);

char *message(char *);

void sendMessage(char *);

char *readMessage();

#endif //C_CLIENT_CLIENT_H
