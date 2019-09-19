//
// Created by atlas on 18/09/19.
//

#ifndef C_CLIENT_CLIENT_H
#define C_CLIENT_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "../res/strings_values.h"

#define IP "10.0.2.2"
#define PORT 9999
#define MAX 1024

int sock;
struct sockaddr_in server_address;

void start();

void stop();

int createSocket();

struct sockaddr_in serverAddress(struct sockaddr_in);

int connectServer(int , struct sockaddr_in);

void sendMessage(char *);

char *readMessage();

#endif //C_CLIENT_CLIENT_H
