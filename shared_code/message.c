#include "message.h"

int read_full_int(int socket, int *int_value_ptr)
   {
    // initialize bytes
	 int byte1 = 0, byte2 = 0, byte3 = 0, byte4 = 0;
	 int return1, return2, return3, return4;
	 unsigned int read_int;
	 unsigned char byte_array[4];

    // read the integer byte by byte
	 return1 = read(socket, &byte1, 1);
	 return2 = read(socket, &byte2, 1);
	 return3 = read(socket, &byte3, 1);
	 return4 = read(socket, &byte4, 1);
    
    // return error if byte read incorrect
	 if ((byte1 | byte2 | byte3 | byte4) < 0)
		return -1;
    
    // return 0 if integer read as zero
	 else if ((return1 | return2 | return3 | return4) == 0)
		return 0;
    
    // format the integer
	 *int_value_ptr = (byte4 << 24) + (byte3 << 16) + (byte2 << 8) + (byte1 << 0);
   }

void sendMessage(messageType *message, chat_nodeType *serverInfo, int socket)
   {
    // initialize function/variables
    int formatted_port, formatted_enum;

    // check for message pointer not null
    if (message != NULL)
      {
       // send logical name
       write(socket, serverInfo->logicalName, (sizeof(char) * LOGIC_NAME_LEN));

       // send ip address
       write(socket, serverInfo->ipAddress, (sizeof(char) * IP_ADDRESS_LEN));

       // format port integer
       formatted_port = htonl(serverInfo->port);

       // send port
       write(socket, &formatted_port, sizeof(formatted_port));

       // format message type enum
       formatted_enum = message->messageEnum;

       // send message type int value
       write(socket, &formatted_enum, sizeof(formatted_enum));

       // send message string
       
       write(socket, message->messageString, (sizeof(char) * MESSAGE_LEN));
      }
   }

messageType *receiveMessage(messageType *messageNode, int socket)
   {
    // initialize function/variables
    
       // ip address string
    char ipAddress[MESSAGE_LEN],
         logicalName[LOGIC_NAME_LEN],
         messageString[MESSAGE_LEN];
    
    int messageEnum,
        port;

    chat_nodeType *chatNode;

    // read logical name and store
    read(socket, logicalName, LOGIC_NAME_LEN);

    // read ip address and store
    read(socket, ipAddress, IP_ADDRESS_LEN);

    // read port and store
    read_full_int(socket, &port);

    // read message type and store
    read_full_int(socket, &messageEnum);

    // read message string
    read(socket, messageString, MESSAGE_LEN);
    
    // call add chat node and assign chat node pointer to function result
    chatNode = addChatNode(chatNode, port, ipAddress, logicalName);

    // call initialize message and pass relevant information as parameters
    messageNode = initializeMessage(messageNode, chatNode, messageEnum, messageString);

    // return message pointer
    return messageNode;
   }

messageType *initializeMessage(messageType *messageNode, chat_nodeType *userInfo, int messageEnum, char *message)
   {    
    // allocate the message struct
    messageNode = (messageType *)malloc(sizeof(messageType));
    
    // assign chat node info
    messageNode->userInfo = userInfo;

    // assign message enum
    messageNode->messageEnum = messageEnum;

    // copy the message string
    strcpy(messageNode->messageString, message);

    // return message struct pointer

    return messageNode;
   } 
=======
#include "message.h"

int read_full_int(int socket, int *int_value_ptr)
   {
    // initialize bytes
	 int byte1 = 0, byte2 = 0, byte3 = 0, byte4 = 0;
	 int return1, return2, return3, return4;
	 unsigned int read_int;
	 unsigned char byte_array[4];

    // read the integer byte by byte
	 return1 = read(socket, &byte1, 1);
	 return2 = read(socket, &byte2, 1);
	 return3 = read(socket, &byte3, 1);
	 return4 = read(socket, &byte4, 1);
    
    // return error if byte read incorrect
	 if ((byte1 | byte2 | byte3 | byte4) < 0)
		return -1;
    
    // return 0 if integer read as zero
	 else if ((return1 | return2 | return3 | return4) == 0)
		return 0;
    
    // format the integer
	 *int_value_ptr = (byte4 << 24) + (byte3 << 16) + (byte2 << 8) + (byte1 << 0);
   }

void sendMessage(messageType *message, chat_nodeType *serverInfo, int socket)
   {
    // initialize function/variables
    int formatted_port, formatted_enum;

    // check for message pointer not null
    if (message != NULL)
      {
       // send logical name
       write(socket, serverInfo->logicalName, (sizeof(char) * LOGIC_NAME_LEN));

       // send ip address
       write(socket, serverInfo->ipAddress, (sizeof(char) * IP_ADDRESS_LEN));

       // format port integer
       formatted_port = htonl(serverInfo->port);

       // send port
       write(socket, &formatted_port, sizeof(formatted_port));

       // format message type enum
       formatted_enum = message->messageEnum;

       // send message type int value
       write(socket, &formatted_enum, sizeof(formatted_enum));

       // send message string
       
       write(socket, message->messageString, (sizeof(char) * MESSAGE_LEN));
      }
   }

messageType *receiveMessage(messageType *messageNode, int socket)
   {
    // initialize function/variables
    
       // ip address string
    char ipAddress[MESSAGE_LEN],
         logicalName[LOGIC_NAME_LEN],
         messageString[MESSAGE_LEN];
    
    int messageEnum,
        port;

    chat_nodeType *chatNode;

    // read logical name and store
    read(socket, logicalName, LOGIC_NAME_LEN);

    // read ip address and store
    read(socket, ipAddress, IP_ADDRESS_LEN);

    // read port and store
    read_full_int(socket, &port);

    // read message type and store
    read_full_int(socket, &messageEnum);

    // read message string
    read(socket, messageString, MESSAGE_LEN);
    
    // call add chat node and assign chat node pointer to function result
    chatNode = addChatNode(chatNode, port, ipAddress, logicalName);

    // call initialize message and pass relevant information as parameters
    messageNode = initializeMessage(messageNode, chatNode, messageEnum, messageString);

    // return message pointer
    return messageNode;
   }

messageType *initializeMessage(messageType *messageNode, chat_nodeType *userInfo, int messageEnum, char *message)
   {    
    // allocate the message struct
    messageNode = (messageType *)malloc(sizeof(messageType));
    
    // assign chat node info
    messageNode->userInfo = userInfo;

    // assign message enum
    messageNode->messageEnum = messageEnum;

    // copy the message string
    strcpy(messageNode->messageString, message);

    // return message struct pointer

    return messageNode;
   } 
