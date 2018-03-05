#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <unistd.h>
#include <errno.h>

#define PORT 12123

int main(int argc, char *argv[]){
  /********* TCP SERVER ********/

  int serverSocket, newSocket;
  struct sockaddr_in serverAddress;
  int addrlen = sizeof(serverAddress);
  char serverBuffer[1024] = {0};

  // #1, Create a socket
  if( ( serverSocket = socket( AF_INET, SOCK_STREAM, 0 ) ) == 0 ){
    perror( "Could Not Create Socket!" );
    exit( EXIT_FAILURE );
  }

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons( PORT );
  
  // #2, Bind to that socket
  if( bind(serverSocket, ( struct sockaddr * )&serverAddress, sizeof( serverAddress ) ) < 0 ){
    perror(" Could Not Bind!" );
    exit( EXIT_FAILURE );
  }

  // #3, Listen for a connection
  listen( serverSocket, 1 );
  
  // #4, Accept new connections
  puts(" /********* TCP SERVER ********/\n");
  newSocket = accept(serverSocket, (struct sockaddr *)&serverAddress, ( socklen_t* )&addrlen );

  // #5, Interact.
  read( newSocket, serverBuffer, sizeof( serverBuffer ) );
  printf("Client said: %s\n", serverBuffer);
  send( newSocket, serverBuffer, sizeof( serverBuffer ), 0 );
  

  return 0;
}


