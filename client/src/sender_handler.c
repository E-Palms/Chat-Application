#include "sender_handler.h"
/*
Sends message the user enters into the chat 
*/
void *send_message(void* args)
{
    //define varaibles
    bool messageFlag = false;
    int client_socket;
    bool gotServerIP = false;
    char input[100];
    char initialCommand[10];
    char serverIP[16];
    char serverPort[5];
    int port;
    int index = 0;
    int serverIndex = 0;
    struct sockaddr_in server;

    //get user input 
    fgets(input, sizeof(input), stdin);

    //parse through input to get port and message type
    while(input[index] != NULL)
    {
        if(strcmp(initialCommand,"JOIN")==0)
        {
            messageFlag = true;
        }
        
        if(input[index] != ' ')
        {
            if(!messageFlag)
            {
                initialCommand[index] = input[index];
            }
            else if(messageFlag && !gotServerIP)
            {
                serverIP[serverIndex] = input[index];
                serverIndex++;
            }
            else if(messageFlag && gotServerIP)
            {
                serverPort[serverIndex] = input[index];
                serverIndex++;
            }
        }
        else
        {
            if(serverIndex != 0)
            {
                gotServerIP = true;
            }
            
            serverIndex = 0;
        }
        
        index++;
    }

    port = atoi(serverPort);

    //create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(serverIP);
    server.sin_port = htons(port);
    
    if(messageFlag)
    {
        //connect to the server
        if(connect(client_socket, (struct sockaddr *)&server, sizeof(server) )==-1)
        {
            perror("Error connecting to server!\n");
            exit(EXIT_FAILURE);
        }

        //Loop until user types leave/shutdown/shutdown all(messageFlag)
        while(messageFlag)
        {
            //get user input 
            fgets(input, sizeof(input), stdin);

            //initializeMessage

            //check if user input is leave/shutdown/shutdown all
                //set messageFlag false
            /*
            if()
            {
                //set message flag false
                messageFlag = false;
                
                //close socket
                close(client_socket);
            }
            */

            //write user input to server
            write(client_socket, &input, (sizeof(char) * 64));
        }
    }
    return NULL;
}
