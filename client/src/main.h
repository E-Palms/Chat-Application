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

#include "properties.h"

// define keys in properties file
#define SERVER_ADDR "SERVER_ADDR"
#define SERVER_PORT "SERVER_PORT"
#define MY_PORT "MY_PORT"
#define MY_ADDR "MY_ADDR"

#define FALSE 0
#define TRUE !FALSE

#define NUM_CONNECTIONS 5       // number of pending connections in the connection queue

