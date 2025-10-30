#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
// #include <arpa/inet.h> // optional, useful for inet_ntoa etc.

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    ssize_t n;
    char buffer[255];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    if (argc < 2) {
        fprintf(stderr, "Port No not provided. Program terminated\n");
        exit(1);
    }

    // 1) Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    // (nice-to-have) allow quick restart
    int yes = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
        error("setsockopt(SO_REUSEADDR) failed");
    }

    // 2) Prepare server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // 3) Bind
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Binding failed");
    }

    printf("Server setup complete on port %d. Waiting for a client...\n", portno);

    // 4) Listen
    if (listen(sockfd, 5) < 0) {
        error("Listen failed");
    }

    // 5) Accept a single client
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) error("Error on accept");

    printf("Client connected. Type messages to reply. Type 'Bye' to end.\n");

    // 6) Chat loop
    while (1) {
        // Receive from client
        memset(buffer, 0, sizeof(buffer));
        n = read(newsockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) error("Error on reading");
        if (n == 0) {  // client closed connection
            printf("Client disconnected.\n");
            break;
        }
        printf("Client: %s", buffer);

        // Send reply
        printf("You: ");
        fflush(stdout);
        memset(buffer, 0, sizeof(buffer));
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("\nEOF on stdin, closing.\n");
            break;
        }

        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) error("Error on writing");

        // If you typed "Bye...", end the chat
        if (strncmp(buffer, "Bye", 3) == 0) {
            printf("Ending chat.\n");
            break;
        }
    }

    // 7) Close sockets
    close(newsockfd);
    close(sockfd);
    return 0;
}