#ifndef CHAT_NODE_H
#define CHAT_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

 // constants
#define STR_EQUAL 0
#define LOGIC_NAME_LEN 32
#define IP_ADDRESS_LEN 16

// structure definition
typedef struct chat_node
   {
    int port;

    char ipAddress[IP_ADDRESS_LEN];

    char logicalName[LOGIC_NAME_LEN];

    struct chat_node *nextChatNode;

   } chat_nodeType;

 // function prototypes
chat_nodeType *addChatNode(chat_nodeType *chatNodePtr, int port, char *ipAddress, char *logicName);

chat_nodeType *removeNode(chat_nodeType *chatNodeHeadPtr, char *ipAddress);

chat_nodeType *clearNodes(chat_nodeType *chatNodePtr);

#endif /*CHAT_NODE_H*/
=======
#ifndef CHAT_NODE_H
#define CHAT_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

 // constants
#define STR_EQUAL 0
#define LOGIC_NAME_LEN 32
#define IP_ADDRESS_LEN 16

// structure definition
typedef struct chat_node
   {
    int port;

    char ipAddress[IP_ADDRESS_LEN];

    char logicalName[LOGIC_NAME_LEN];

    struct chat_node *nextChatNode;

   } chat_nodeType;

 // function prototypes
chat_nodeType *addChatNode(chat_nodeType *chatNodePtr, int port, char *ipAddress, char *logicName);

chat_nodeType *removeNode(chat_nodeType *chatNodeHeadPtr, char *ipAddress);

chat_nodeType *clearNodes(chat_nodeType *chatNodePtr);

#endif /*CHAT_NODE_H*/
