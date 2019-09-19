//
// Created by atlas on 18/09/19.
//

#ifndef C_CLIENT_CLIENT_H
#define C_CLIENT_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "../res/strings_values.h"

#define IP "192.168.100.1"
#define PORT 9999

int sock;
struct sockaddr_in *server_address;

void start();

void stop();

int createSocket();

int serverAddress(struct sockaddr_in *);

int connectServer(int , struct sockaddr_in *);

void sendMessage(char *);

char *readMessage(char *);

#endif //C_CLIENT_CLIENT_H
