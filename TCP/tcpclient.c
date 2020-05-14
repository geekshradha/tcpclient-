#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<fcntl.h>
#define PORT_NUM 2500
#define IP_ADDR "127.0.0.1"

int main()
{
	int client_sockfd;
	int server_len;
	char out_buf[100];
	char in_buf[100];
	struct sockaddr_in server_address;
	
	client_sockfd=socket(AF_INET, SOCK_STREAM,0);
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(PORT_NUM);
	server_address.sin_addr.s_addr=inet_addr(IP_ADDR);
	
	server_len=sizeof(server_address);
	connect(client_sockfd, (struct sockaddr *)&server_address, server_len);
	

	while(1)
	{
		recv(client_sockfd,in_buf,sizeof(in_buf),0);
		printf("Rceceived from server ... message ='%s'\n",in_buf);
		printf("Enter your message...");
		fgets(out_buf,100,stdin);
		send(client_sockfd,out_buf, (strlen(out_buf)+1),0);
	}
close(client_sockfd);
}
