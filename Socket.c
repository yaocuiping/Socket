#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

char str[40]="linzijun";
int num=0;
int client_sock;
int main(int argc,int **argv)
{	
	int server_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(server_sock==-1)
	{
		printf("socket fail!\r\n");
		return 0;
	}

	printf("socket ok:%d\r\n",server_sock);
	
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
//	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(1234);
	printf("addr:%#x,port:%#x\r\n",server_addr.sin_addr.s_addr,server_addr.sin_port);

	int Bind=bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
	if(Bind==-1)
	{
		printf("bind fail\r\n");
	}
	printf("bind ok\r\n");

	int Listen=listen(server_sock,20);
	if(Listen==-1)
	{
		printf("Listen fail\r\n");
	}
	printf("Luisten ok\r\n");

	struct sockaddr_in client_addr;
	socklen_t client_addr_size =sizeof(client_addr);

	while(1)
	{	
		client_sock = accept(server_sock,(struct sockaddr*)&client_addr,&client_addr_size);
		if(client_sock==-1)
		{
			printf("accept fail\r\n");
		}
		printf("accept ok\r\n");	

		int Wnum=0;
	//	scanf("%s\r\n",str);
		num++;
		Wnum=write(client_sock,&num,sizeof(num));
		if(Wnum==-1)
		{
			printf("write Fail\r\n");
		}
		printf("write ok:%d",num);
	}
	close(client_sock);
	close(server_sock);

	return 0;
}
