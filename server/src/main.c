#include "main.h"

// mutex lock global vars
pthread_mutex_t mutex_client_sock = PTHREAD_MUTEX_INITIALIZER;

/* ************************************************************************* */
/* MAIN                                                                      */
/* ************************************************************************* */

int main(int argc, char** argv) {
    int server_socket;                 // descriptor of server socket
    struct sockaddr_in server_address; // for naming the server's listening socket

    // read in properties from prop file
    char* properties_file = argv[1];
    Properties* properties;
    char* server_addr;
    int server_port;
    
    properties = property_read_properties(properties_file);
    
    server_port = atoi(property_get_property(properties, SERVER_PORT));
    server_addr = property_get_property(properties, SERVER_ADDR);

    // sent when client disconnected
    signal(SIGPIPE, SIG_IGN);
    
    // create unnamed network socket for server to listen on
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // name the socket (making sure the correct network byte ordering is observed)
    server_address.sin_family      = AF_INET;           // accept IP addresses
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); // accept clients on any interface
    server_address.sin_port        = htons(server_port);       // port to listen on
    
    // binding unnamed socket to a particular port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) != 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    
    // listen for client connections (pending connections get put into a queue)
    if (listen(server_socket, NUM_CONNECTIONS) != 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d\n", server_port);

    // create chat node linked list
    chat_nodeType *head_chat_ptr = NULL;
    
    // server loop
    while (TRUE) {

        // mutex lock
        pthread_mutex_lock(&mutex_client_sock);

        // accept connection to client
        int client_socket = accept(server_socket, NULL, NULL);
        printf("\nServer with PID %d: accepted client\n", getpid());

        handleClientArgs *args = (handleClientArgs*) malloc(sizeof(handleClientArgs));
        args->client_socket = client_socket;
        args->head_ptr = NULL;

        // create thread to handle the client's request
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, args) != 0) {
        // if (pthread_create(&thread, NULL, handle_client, (void*)&client_socket) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
        
        // detach the thread so that we don't have to wait (join) with it to reclaim memory.
        // memory will be reclaimed when the thread finishes.
        if (pthread_detach(thread) != 0) {
            perror("Error detaching thread");
            exit(EXIT_FAILURE);
        }
    }
}