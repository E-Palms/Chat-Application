#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <syslog.h>
#include <signal.h>

#include "./shared_code/chat_node.h"
#include "./shared_code/message.h"

// mutex lock
extern pthread_mutex_t mutex_client_sock;

// enums
enum Command {
    JOIN,
    LEAVE,
    NOTE,
    SHUTDOWN,
    SHUTDOWN_ALL
};

typedef struct handleClientArgs {
    int client_socket;
    chat_nodeType *head_ptr;
} handleClientArgs;

// prototypes
void* handle_client(void* arg);
void sendMessagesToAllClients(messageType *message, chat_nodeType *headChatNodePtr);
bool checkForUser(char* ip, chat_nodeType* head_ptr);

#define FALSE 0
#define TRUE !FALSE

#define NUM_CONNECTIONS 5       // number of pending connections in the connection queue
#define MAX_LOGICAL_NAME_LEN 32
#define MAX_IP_LEN 16
