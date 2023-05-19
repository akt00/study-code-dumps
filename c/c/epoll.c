#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void stopwatch(unsigned limit) {

    time_t start = time(NULL);
    time_t prev = start;
    for(;;) {
        time_t now = time(NULL);
        if(prev != now) {
            printf("\r%ld\n", now - start);
            prev = now;
        }
        if(limit != -1 && (now - start) >= limit) break;
    }
}

#define MAX_EVENTS 5
#define READ_SIZE 10
int main(int argc, char **argv) {

    /*
    if(argc != 2) {
        fprintf(stderr, "invalid number of arguments\n");
        exit(1);
    }
    */

    struct epoll_event ev, events[MAX_EVENTS];
    int listen_sock, conn_sock, nfds, epollfd;

    in_port_t port = 1234;
    if((listen_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        fprintf(stderr, "server socket creation failed\n");
        return 1;
    }

    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(port);

    if(bind(listen_sock, (struct sockaddr*) &servAddr, sizeof(servAddr)) < 0) {
        fprintf(stderr, "bind error\n");
        return 1;
    }

    if(listen(listen_sock, 10) < 0) {
        fprintf(stderr, "listen failed\n");
        return 1;
    }
    
    epollfd = epoll_create1(0);
    if(epollfd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
        perror("epoll_ctl: listen_sock");
        exit(EXIT_FAILURE);
    }

    for(;;) {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if(nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }
        struct sockaddr_in addr;
        socklen_t addrLen = sizeof(addr);

        for(int n=0; n<nfds;n++) {
            if(events[n].data.fd == listen_sock) {
                conn_sock = accept(listen_sock, (struct sockaddr*) &addr, &addrLen);
                if(conn_sock == -1) {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                // setNonBlocking(conn_sock);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;
                if(epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
                    perror("epoll_ctl: conn_sock");
                    exit(EXIT_FAILURE);
                }
            }
            else {
                printf("non socket IO\n");
                // do_use_fd(events[n].data.fd);
            }
        }
    }
	return 0;
}