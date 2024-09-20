#include "chat_node.h"

chat_nodeType *addChatNode(chat_nodeType *chatNodePtr, int port, char *ipAddress, char *logicName)
   {
    // check for if the chat pointer is null
    if (chatNodePtr == NULL)
      {
       // allocate a new node
       chatNodePtr = (chat_nodeType *)malloc(sizeof(chat_nodeType));

       // assign port paramter
       chatNodePtr->port;

       // assign IP address parameter
       strcpy(chatNodePtr->ipAddress, ipAddress);

       // assign logical name parameter
       strcpy(chatNodePtr->logicalName, logicName);

       // return chat pointer
       return chatNodePtr;
      }

    // call addChatNode recursively and assign to the current pointer's next pointer
    chatNodePtr->nextChatNode = addChatNode(chatNodePtr, port, ipAddress, logicName);

    // return the current chat pointer
    return chatNodePtr;
   }

chat_nodeType *removeNode(chat_nodeType *chatNodeHeadPtr, char *ipAddress)
   {
    // temporary chat node pointer and working pointer
    chat_nodeType *prevChatNode = NULL, *chatWkgPtr = chatNodeHeadPtr;

    // check for if the current head pointer is to be removed
    if (strcmp(chatNodeHeadPtr->ipAddress, ipAddress) == STR_EQUAL)
      {
       // point temporary pointer to the head pointer
       chatWkgPtr = chatNodeHeadPtr;

       // set the head pointer to the next pointer 
       chatNodeHeadPtr = chatNodeHeadPtr->nextChatNode;

       // free the temporary pointer
       free(chatWkgPtr);
      }
    else
      {
       chatWkgPtr = chatNodeHeadPtr->nextChatNode;
       prevChatNode = chatNodeHeadPtr;
       // loop while the working pointer isn't null
       while (chatWkgPtr != NULL && strcmp(chatWkgPtr->ipAddress, ipAddress) != STR_EQUAL)
         {
          // traverse the pointer
          chatWkgPtr = chatWkgPtr->nextChatNode;
         }
       
       if (chatWkgPtr != NULL)
         {
          // point the previous pointer's next node pointer to the working pointer's next node
          prevChatNode->nextChatNode = chatWkgPtr->nextChatNode;

         // free the identified node
          free(chatWkgPtr);
         }
      }

    // return the head pointer
    return chatNodeHeadPtr;
   }

chat_nodeType *clearNodes(chat_nodeType *chatNodePtr)
   {
    // temporary node pointer
    chat_nodeType *temp;

    // check if the current pointer is not null
    if (chatNodePtr != NULL)
      {
       // point temp to current chat node
       temp = chatNodePtr;
       
       // point current node pointer to next chat node
       chatNodePtr = chatNodePtr->nextChatNode;
       
       // free the temp pointed node
       free(temp);
      }
    
    // return the empty chat node head pointer
    return chatNodePtr;
   }