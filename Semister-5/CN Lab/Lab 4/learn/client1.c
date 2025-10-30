#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[255];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    // Step 1: Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Step 2: Prepare server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    // Convert IP address from text to binary
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Step 3: Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection Failed");
    }

    printf("Connected to server %s:%d\n", argv[1], portno);

    // Step 4: Communication loop
    while (1) {
        // Read message from stdin
        memset(buffer, 0, sizeof(buffer));
        printf("You: ");
        fgets(buffer, sizeof(buffer), stdin);

        // Send to server
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) error("Error writing to socket");

        // If user typed Bye, end connection
        if (strncmp(buffer, "Bye", 3) == 0) {
            printf("Connection closed.\n");
            break;
        }

        // Read server response
        memset(buffer, 0, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) error("Error reading from socket");
        if (n == 0) {
            printf("Server disconnected.\n");
            break;
        }
        printf("Server: %s", buffer);
    }

    close(sockfd);
    return 0;
}