#include "client_handler.h"

int read_int(int socket, int* int_value_ptr)
{
    int ERROR = -1;
    int bytes_received = 0;
    int total_bytes = sizeof(int);
    char buffer[total_bytes];

    while (bytes_received < total_bytes) {
        int bytes = read(socket, buffer + bytes_received, total_bytes - bytes_received);

        if (bytes <= 0) {
            return ERROR;
        }

        bytes_received += bytes;
    }

    // Convert the received bytes to an integer
    *int_value_ptr = *((int*)buffer);

    return total_bytes; // Successful read
}

void* handle_client(void* _args) {
    handleClientArgs *args = (handleClientArgs*)_args;

    free(_args);

    int client_socket = args->client_socket;   // the socket connected to the client
    chat_nodeType *chat_head_ptr = args->head_ptr;
    int input;

    // unlock the mutex lock
    pthread_mutex_unlock(&mutex_client_sock);

    // read input from client
    read(client_socket, &input, sizeof(int));
    
    // switch statement for enumerated commands
    switch(input) {
        case JOIN:
            // join

            char logicalName[MAX_LOGICAL_NAME_LEN];
            char ip[MAX_IP_LEN];
            int port;

            // read in the user's information, like username/IP/port
            read(client_socket, logicalName, MAX_LOGICAL_NAME_LEN);
            read(client_socket, ip, MAX_IP_LEN);
            read(client_socket, &port, sizeof(int));

            // check if user is in chat node linked list yet
            // if yes, break
            // if not, add the user to the linked list
            // and send message to all clients that user has joined
            if (checkForUser(ip, chat_head_ptr)) {
                break;
            } else {
                messageType message;
                char messageText[64];

                // chat_head_ptr = addChatNode(chat_head_ptr, port, ip, logicalName);

                sprintf(messageText, "User %s joined the chat\n", logicalName);
                // message = initializeMessage(new_chat_node, JOIN, messageText);

                sendMessagesToAllClients(NULL, NULL);
            }

            // clean up
            break;

        case LEAVE:
        case SHUTDOWN:
            // leave and shutdown have the same server logic

            // remove the user from the chat node linked list

            // send message to all clients that user left

            // clean up

            break;
        case NOTE:
            // note

            // read in the message from the client
            // store the message

            // send the message to all clients in the chat node linked list

            // clean up

            break;
        case SHUTDOWN_ALL:
            // shutdown all

            // run through the chat node linked list and send a shutdown message to each client

            // remove all nodes from the chat node linked list

            // shut down the server

            // clean up

            break;
    }

    // cleanup
    free(args);

    if (close(client_socket) == -1) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    } else {
        printf("Closed socket to client, exit");
    }
    
    pthread_exit(NULL);
}

void sendMessagesToAllClients(messageType *message, chat_nodeType *headChatNodePtr) {
    // run through all chat nodes and send message to each one
    
    // chat_nodeType *wkgPtr = *headChatNodePtr;

    // while (wkgPtr != NULL)
    // {
    //     sendMessage(message, )
    // }
    
    printf("Sent messages to all clients\n");
}

bool checkForUser(char* ip, chat_nodeType* head_ptr) {
    // run through the linked list to see if the ip exists there already

    // stub return
    return 0;
}
