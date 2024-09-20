//included header files
#include receiver_handler.h

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

/*
This function will listen for the server's repsonse
*/
void *recieve_message(void* args)
{
    //define variables 

    //set listeningFlag true

    //unlock Mutex

    //Listening loop(listeningFlag)

        //listens for the servers response

            //process_message
                //set listentingFlag equal to the result 
                //of this function
  
}

/*
Proccess the messages from the server 
*/
bool process_message(char* message)
{
    //define variables

    //set messageFlag true

    //create socket

    //connect to server

    //read message from server
        //Function: read_int

    //check message for any commands
        //case SHUTDOWN
            //set messageFlag false
            //display shutdown message
            //break

        //case SHUTDOWN ALL
            //set messageFlag false
            //display shutdown all message
            //break

        //case LEAVE
            //set messageFlag false
            //display leave message
            //break

        //default(message)
            //display message

    //close socket

    //return messageFlag
    return messageFlag;
}