#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <errno.h>

#define SERVER_PORT	22333
#define MAX_CURR	10000

int set_nonblock(int fd)
{
	int ret;
	
	ret = fcntl(fd, F_GETFL);
	if(ret < 0)
	{
		perror("fcntl");
		return -1;
	}

	if(fcntl(fd, F_SETFL, ret | O_NONBLOCK))
	{
		perror("fcntl");
		return -2;
	}

	return 0;
}

int main(void)
{
	int listenfd;
	int efd;
	int nfds;
	int ret;
	int i;
	char buf[1024];
	char http_header[1024];

	char demo_html[] =
		"<html>\r\n"
		"<head>\r\n"
		"<title>demo</title>\r\n"
		"</head>\r\n"
		"<body>\r\n"
		"hello world!"
		"</body>\r\n"
		"</html>\r\n\r\n";
	char http_fmt[] =
		"HTTP/1.0 200 OK\r\n"
		"Server: KarsusNeko\r\n"
		"Date: 01/01/1970 00:00:00 GMT\r\n"
		"Content-Type: text/html\r\n"
		"Accept-Ranges: bytes\r\n"
		"Content-Length: %d\r\n\r\n";
	sprintf(http_header, http_fmt, strlen(demo_html));

	efd = epoll_create(10000);

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(set_nonblock(listenfd) < 0)
	{
		printf("set_nonblock failed\r\n");
		return -32;
	}

	struct epoll_event ev;

	set_nonblock(efd);
	set_nonblock(listenfd);

	ev.data.fd = listenfd;
	ev.events = EPOLLIN | EPOLLET;
	epoll_ctl(efd, EPOLL_CTL_ADD, listenfd, &ev);

	struct sockaddr_in clientaddr;
	struct sockaddr_in serveraddr;

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;

	char local_addr[] = "127.0.0.1";
	inet_aton(local_addr, &(serveraddr.sin_addr));
	serveraddr.sin_port = htons(SERVER_PORT);
	bind(listenfd, (sockaddr*)&serveraddr, sizeof(serveraddr));
	listen(listenfd, 1000);

	int maxi = 0;
	int confd;
	int sockfd;
	struct epoll_event events[10000];
	socklen_t client;
	while(1)
	{
		nfds = epoll_wait(efd, events, 1000, 500);
		for(i = 0; i < nfds; ++i)
		{
			if(events[i].data.fd == listenfd)
			{
				confd = accept(listenfd, (sockaddr*)&clientaddr, &client);
				if(confd < 0)
				{
					perror("accept");
					// return -2;
					continue;
				}
				set_nonblock(confd);
				char* str = inet_ntoa(clientaddr.sin_addr);
				
				ev.data.fd = confd;
				ev.events = EPOLLIN | EPOLLET;
				epoll_ctl(efd, EPOLL_CTL_ADD, confd, &ev);

				continue;
			}
			else if(events[i].events & EPOLLIN)
			{
				if((sockfd = events[i].data.fd) < 0) continue;
				ret = read(sockfd, buf, 1024);
				if(ret <= 0)
				{
					printf("--------\r\n");
					events[i].data.fd = -1;
					ev.data.fd = sockfd;
					epoll_ctl(efd, EPOLL_CTL_DEL, sockfd, &ev);
					close(sockfd);
					continue;
				}

				ev.data.fd = sockfd;
				ev.events = EPOLLOUT | EPOLLET;
				epoll_ctl(efd, EPOLL_CTL_MOD, sockfd, &ev);

				continue;
			}
			else if(events[i].events & EPOLLOUT)
			{
				sockfd = events[i].data.fd;
				write(sockfd, http_header, strlen(http_header));
				write(sockfd, demo_html, strlen(demo_html));

				ev.data.fd = sockfd;
				ev.events = EPOLLIN | EPOLLET;
				epoll_ctl(efd, EPOLL_CTL_DEL, sockfd, &ev);
				close(sockfd);

				continue;
			}
		}
	}

	return 0;
}
