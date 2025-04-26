#include<string.h> #include<stdio.h> #include<sys/types.h> #include<sys/socket.h> #include<netinet/in.h> main()
{
intsockfd,n;

charbuffer[512];
structsockaddr_inserv_addr;
bzero((char *)&serv_addr,sizeof(serv_addr)); serv_addr.sin_family=AF_INET; serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1"); serv_addr.sin_port=htons(5555); sockfd=socket(AF_INET,SOCK_STREAM,0); connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)); n=read(sockfd,buffer,512,0);
printf("\nTimereceivedfromtheserver:%s",buffer); close(sockfd);
}
