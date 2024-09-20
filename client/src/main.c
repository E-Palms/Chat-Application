#include "main.h"

// global vars
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
    char* my_addr;
    int my_port;
    char* server_addr;
    int server_port;
    
    properties = property_read_properties(properties_file);
    
    server_port = atoi(property_get_property(properties, "SERVER_PORT"));
    server_addr = property_get_property(properties, "SERVER_ADDRESS");
    my_port = atoi(property_get_property(properties, "MY_PORT"));
    my_addr = property_get_property(properties, "MY_ADDRESS");


    // create the two threads for sending and receiving    
    int num_threads = 2;
    pthread_t threads[num_threads];
    /*
    if (pthread_create(&threads[0], NULL, receive_messsage, (void *)task_counter) != 0) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }
    */

    if (pthread_create(&threads[1], NULL, send_message, NULL) != 0) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }

    return 0;
}
