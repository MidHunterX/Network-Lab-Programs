#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    struct sockaddr_in client_address, server_address;
    int socket_descriptor_1, socket_descriptor_2;
    char message_1[10] = "", message_2[10] = "";

    socket_descriptor_1 = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = 2000;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(socket_descriptor_1, (struct sockaddr *)&server_address, sizeof(server_address));

    listen(socket_descriptor_1, 1);

    int size_of_client_address = sizeof(client_address);

    socket_descriptor_2 = accept(socket_descriptor_1, (struct sockaddr *)&client_address, &size_of_client_address);

    while (1) {
        recv(socket_descriptor_2, message_1, sizeof(message_1), 0);

        if (strcmp(message_1, "end") == 0)
            break;

        printf("\nClient : %s", message_1);

        printf("\nServer : ");
        scanf("%s", message_2);

        send(socket_descriptor_2, message_2, sizeof(message_2), 0);

        if (strcmp(message_2, "end") == 0)
            break;
    }

    close(socket_descriptor_2);
    close(socket_descriptor_1);
}
