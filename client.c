#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
	int Rnum=0,num;
	char Send[10]={0};	
	int sock=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(1234);
	connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	while(1){
	//	sleep(1);
		char buffer[40]={0};
		Rnum=read(sock,buffer,sizeof(buffer));
		if(Rnum!=-1&&Rnum!=0)
		printf("Rnum:%d:--:%s\r\n",Rnum,buffer);
		scanf("%s",Send);
		Rnum=write(sock,Send,10);
		if(Rnum==-1)
		printf("write Fail\r\n");
	//	else
	//	printf("have no data\r\n");
	//	sleep(1);
		
	     }
	close(sock);
	
	return 0;
}
