#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    printf("[+] Socket created successfully (File Descriptor: %d)\n", server_fd);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("[+] Bind successful on port %d\n", PORT);

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("[+] Server is running and listening indefinitely...\n");

    // KEEP IT OPEN: Infinite loop to handle multiple clients one after another
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue; // If one connection fails, keep the server alive for the next one
        }
        
        printf("[+] Connection accepted! Client file descriptor: %d\n", new_socket);

        // Send HTTP response
        char *hello = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 13\r\n\r\nHello, World!";
        write(new_socket, hello, strlen(hello));
        
        // Close only the client socket, keep the server listening
        close(new_socket);
        printf("[+] Response sent. Waiting for next connection...\n");
    }

    // (This part is rarely reached, but good practice)
    close(server_fd);
    return 0;
}
