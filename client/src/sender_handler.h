//Varaiables
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// socket/bind/listen/accept
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// read/write/close
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

#define SPACE ' '

//Functions
void *send_message(void* args);
