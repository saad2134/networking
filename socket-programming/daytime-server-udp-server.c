#include<stdio.h> #include<stdlib.h> #include<time.h> #include<sys/types.h> #include<sys/socket.h> #include<netinet/in.h> #include<strings.h> #include<strings.h> main()
{
unsigned long t;char*st,buffer[512];
 
intn,i,l,ml,sockfd,newsockfd;
struct sockaddr_in serv_addr,cli_addr; sockfd=socket(AF_INET,SOCK_DGRAM,0); serv_addr.sin_family=AF_INET; serv_addr.sin_addr.s_addr=htonl(INADDR_ANY); serv_addr.sin_port=htons(5555);
bind(sockfd,(structsockaddr*)&serv_addr,sizeof(serv_addr)); l=sizeof(cli_addr);
cliLen=sizeof(cliAdr);
n	=	recvfrom(sockFd,buffer,MAX_MSG,0	,(struct sockaddr*)&cliAdr,&cliLen);
if(n<0)
{
errExit("recvfromerror\n");
}
Printf(“\nMessagereceivedfromclient:%s”,buffer); t=time(&t);
st=(char*)ctime(&t); strcpy(buffer,st); n=sizeof(buffer);
if(sendto(sockFd,buffer,n,0,(structsockaddr*)&cliAdr,cliLen)!=n)
{	errExit("sendtoerror \n");
}
Printf(“Timesent…”);
}
}
