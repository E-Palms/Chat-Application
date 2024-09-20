#ifndef MESSAGE_H
#define MESSAGE_H

#include "chat_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// constants
#define MESSAGE_LEN 64

#define FIRST_CHAR 0

typedef struct messageStruct
{
   int messageEnum;

   char messageString[MESSAGE_LEN];

   chat_nodeType *userInfo;

} messageType;


// function prototypes
int read_full_int(int socket, int *int_value_ptr);

void sendMessage(messageType *message, chat_nodeType *serverInfo, int socket);

messageType *receiveMessage(messageType *message, int socket);

messageType *initializeMessage(messageType *messageNode, chat_nodeType *userInfo, int messageType, char *message);

#endif /*MESSAGE_H*/