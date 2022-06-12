#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    struct sockaddr_in server_address;

    int socket_descriptor, character_count, file_length, i;
    char buffer_1[3024], buffer_2[3000];

    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(6000);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(socket_descriptor, (struct sockaddr *)&server_address, sizeof(server_address));

    printf("\nEnter the filename:\n");
    character_count = read(0, buffer_1, sizeof(buffer_1));
    buffer_1[character_count - 1] = '\0';

    write(socket_descriptor, buffer_1, character_count);

    file_length = read(socket_descriptor, buffer_2, sizeof(buffer_2));
    if (file_length == 0)
        printf("\n\nFile not present....!!!");
    else {
        printf("\n\nPrinting content of file:\n");
        for (i = 0; i < file_length; i++)
            printf("%c", buffer_2[i]);

        printf("\nReceived requested file\n\n");
    }

    close(socket_descriptor);
}
