#include<stdio.h>
#include <stdlib.h>
#include <errno.h> #include <netdb.h> #include<sys/types.h>#include<netinet/in.h>
intmain(intargc,char*argv[])
{
structhostent*h; if(argc!=2)
{ /*error check the command line*/ printf(stderr,"usage:getpidaddress\n"); exit(1);
}
if((h=gethostbyname(argv[1]))==NULL)
{ /*get the host info*/ perror("gethostbyname"); exit(1);
}
printf("Hostname:%s\n",h->h_name);
printf("IPAddress:%s\n",inet_ntoa(*((structin_addr*)h->h_addr))); return 0;
}
