#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 1024
#define PORT_ADDR 6000
#define QSIZE 5

void main() {
    struct sockaddr_in server_address, client_address;

    int i, socket_descriptor_1, socket_descriptor_2, size_of_client_address, file_descriptor, character_count;
    char buffer_1[BUFSIZE], buffer_2[BUFSIZE];

    socket_descriptor_1 = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_ADDR);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(socket_descriptor_1, (struct sockaddr *)&server_address, sizeof(server_address));
    listen(socket_descriptor_1, QSIZE);

    size_of_client_address = sizeof(client_address);

    socket_descriptor_2 = accept(socket_descriptor_1, (struct sockaddr *)&client_address, &size_of_client_address);
    printf("\nRequest accepted...\n");
    close(socket_descriptor_1);

    character_count = read(socket_descriptor_2, buffer_1, BUFSIZE);
    buffer_1[character_count] = '\0';
    printf("\nFilename is %s", buffer_1);

    if ((file_descriptor = open(buffer_1, O_RDONLY)) >= 0) {
        printf("\n\nFile opened...");

        character_count = read(file_descriptor, buffer_2, BUFSIZE);
        while (character_count > 0) {
            printf("\n\nSending file...");
            write(socket_descriptor_2, buffer_2, character_count);

            printf("\n\nPrinting content of file:\n");
            for (i = 0; i < character_count; i++)
                printf("%c", buffer_2[i]);
            printf("\n");

            if (i == character_count)
                break;
        }
    } else
        printf("\n\nRequested file is not present...\n\n");

    close(file_descriptor);
    close(socket_descriptor_2);
}
