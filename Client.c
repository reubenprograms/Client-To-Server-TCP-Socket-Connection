#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

//They're all of the includes which you need to run this next program//
int main()
{
  int sock; //Declaring a variable named "sock"//
  sock = socket(AF_INET, SOCK_STREAM, 0); //Defining the variable named "sock"//

  struct sockaddr_in server_address; //Declaring a server address//
  server_address.sin_family = AF_INET; //Telling the server the type of connection(ipv4)//
  server_address.sin_port = htons(8080); //Defining the server's port//
  server_address.sin_addr.s_addr = INADDR_ANY; //Because the connection is local it can connect with any IP Address.//

  int connection = connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)); //Defining a Connection//

  if (connection == -1){ //If the connection fails//
    printf("There was an error in the connection\n"); //Print the error//
  } //Close the if statement//

  char server_response[255]; //Declaring the server response//
  recv(sock, &server_response, sizeof(server_response), 0); //receving the server response//

  printf("The server responded with %s\n", server_response); //Telling the Client how the server responded//

}
