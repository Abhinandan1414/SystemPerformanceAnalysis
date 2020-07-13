
/* Code is not mine */

#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define MAX 80 
#define PORT 8080 
#define LSIZ 128
#define RSIZ 1000
#define SA struct sockaddr 
void func(int sockfd) 
{ 
    FILE * file_pointer;
    char line[RSIZ][LSIZ];
    char buff[MAX];
    char c; 
    int n; 
    int i;
    int counter;
    /*
    for (;;) { 
        bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
        n = 0; 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
        write(sockfd, buff, sizeof(buff)); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        }
    }
    */
     file_pointer = fopen("Test.txt", "r"); //reset the pointer
     if ( file_pointer == NULL)
     {
	     printf("File does not exist\n");
	     return;
     }
     /*
     do
     {
        buff = getline(file_pointer);
	//printf("%c",buff);
	//strcpy(buff,c);
        write(sockfd, buff, sizeof(buff)); 
     } while (buff != EOF);
     */
    while(fgets(line[i], LSIZ, file_pointer))
	{
        //line[i][strlen(line[i]) - 1] = '\0';
	printf("%s",line[i]);
        write(sockfd, line[i],LSIZ); 
        i++;
    }
     fclose(file_pointer);
     //bzero(buff, sizeof(buff)); 
     //read(sockfd, buff, sizeof(buff)); 
     //printf("From Server : %s", buff); 
} 
  
int main(int argc, char* argv[]) 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_addr.s_addr = inet_addr(argv[1]); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 
