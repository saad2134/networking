#include<stdio.h> #include<stdlib.h> #include<time.h> #include<sys/types.h> #include<sys/socket.h> #include<netinet/in.h> #include<string.h>#include <time.h>#include<strings.h> main()
{
unsignedlongt; time_t tick;
char*st,buffer[512];
intn,i,l,ml,sockfd,newsockfd;
struct sockaddr_in serv_addr,cli_addr; sockfd=socket(AF_INET,SOCK_STREAM,0); serv_addr.sin_family=AF_INET; serv_addr.sin_addr.s_addr=htonl(INADDR_ANY); serv_addr.sin_port=htons(5555);
bind(sockfd,(structsockaddr*)&serv_addr,sizeof(serv_addr)); listen(sockfd,5);
puts("waiting	");
l=sizeof(cli_addr); for(i=0;i<5;i++)
{
newsockfd=accept(sockfd,(structsockaddr*)&cli_addr,&l); printf("\nConnected to client");	t=time(&t);
//snprintf(buffer,sizeof(buffer),"%.24s\r\n",ctime(&tick)); buffer=ctime(&t);
//strcpy(buffer,st); puts(buffer);
n=write(newsockfd,buffer,strlen(buffer)); close(newsockfd);
}
}
