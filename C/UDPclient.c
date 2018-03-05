#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    /******** UDP Client ********/
  
  int clientSocket;
  struct sockaddr_in serverAddress;
  struct hostent *host;
  char buffer[1024];

  // #1, Get The Address of The Server
  //host= gethostbyname( "" ); // Some IP address
  host= gethostbyname( "127.0.0.1" );

  // #2, Get a Socket for The Client
  if( ( clientSocket = socket( AF_INET, SOCK_DGRAM, 0) ) == -1 ){
    perror( "Error Creating Socket!" );
    exit(1);
  }

  // #3, Tell The Kernel Who The Server is And Where Is At
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons( PORT );
  serverAddress.sin_addr = *( ( struct in_addr * )host->h_addr );
  bzero( &( serverAddress.sin_zero ), 8 );
  
  // #4, Interact...
  printf("/******** UDP Client ********/\n");
  strcpy(buffer, "Hello, World!");
  sendto( clientSocket, buffer, strlen(buffer ), 0, ( struct sockaddr * )&serverAddress, sizeof( struct sockaddr ) );
  bzero(buffer, sizeof(buffer));
  recv( clientSocket, buffer, sizeof( buffer ), 0 );
  printf("\nServer said: %s\n", buffer);
  
  return 0;
}
