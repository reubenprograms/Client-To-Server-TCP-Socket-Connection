  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
//All of the includes you need to make it//

int main()
{
  char server_message[256] = "You got a message from the server"; //Defining the server message//

  int server_sock; //Declaring a variable named "server_sock"//
  server_sock = socket(AF_INET, SOCK_STREAM, 0); //Defining the server sock//

  struct sockaddr_in server_address; //Defining the server address//
  server_address.sin_family = AF_INET; //Defining the connection(ipv4)//
  server_address.sin_port = htons(8080); //Defining the server's port//
  server_address.sin_addr.s_addr = INADDR_ANY; //Once again, this is a local connection so any IP Address is able to be used//

  bind(server_sock, (struct sockaddr*) &server_address, sizeof(server_address)); //Binding the server's socket to the server address//
  listen(server_sock, 4); //Listening to the server's socket for 4 seconds//

  int client_accept; //Accepting a Client's request to connect to the server//
  client_accept = accept(server_sock, NULL, NULL); //Accepting the connection//

  send(client_accept, server_message, sizeof(server_message), 0); //Sending the server message//
  
  close(server_sock); //Closing the socket
}
