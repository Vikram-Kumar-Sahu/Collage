// udp_client_reply.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    socklen_t len;
    char buffer[1024];
    char *msg = "Hello from UDP client";

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sockfd, msg, strlen(msg), 0,
           (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Message sent to server\n");

    len = sizeof(servaddr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                     (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    printf("Reply from server: %s\n", buffer);

    close(sockfd);
    return 0;
}
