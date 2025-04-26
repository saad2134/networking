#include <stdio.h> #include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
 
#include<arpa/inet.h>#include <stdlib.h> #include <string.h>
#defineSRV_IP_ADRS"127.0.0.1"
#defineSRV_UDP_PORT8000
#define MAX_MSG	100 void errExit(char *str)
{
puts(str); exit(0);
}
intmain()
{
int sockFd;
structsockaddr_insrvAdr; char txmsg[MAX_MSG]; char rxmsg[MAX_MSG]; int n;
if((sockFd=socket(AF_INET,SOCK_DGRAM,0))< 0)
{	errExit("can'topendatagramsocket\n");
}
memset ( &srvAdr,0,sizeof(srvAdr)); srvAdr.sin_family = AF_INET; srvAdr.sin_addr.s_addr=inet_addr(SRV_IP_ADRS); srvAdr.sin_port = htons (SRV_UDP_PORT); printf("Enter message to send :\n"); fgets(txmsg,MAX_MSG,stdin);
n=strlen(txmsg)+1;
if(sendto(sockFd,txmsg,n,0,(structsockaddr*)&srvAdr,sizeof(srvAdr))!=n)
{	errExit("sendtoerror\n");
 
}
n=recv(sockFd,rxmsg,MAX_MSG,0); printf("n=%d\n",n);
if(n<0)
{	errExit("recverror\n");
}
printf("TimeReceivedfromtheserver :%s\n",rxmsg);
}
