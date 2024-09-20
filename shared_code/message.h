#ifndef MESSAGE_H
#define MESSAGE_H

#include "chat_node.h"

// should always be there ...
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// socket/bind/listen/accept
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// read/write/close
#include <sys/uio.h>
#include <sys/types.h>
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
=======
#ifndef MESSAGE_H
#define MESSAGE_H

#include "chat_node.h"

// should always be there ...
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// socket/bind/listen/accept
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// read/write/close
#include <sys/uio.h>
#include <sys/types.h>
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
