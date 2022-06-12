#include"network-libs.h"

void main() {
    struct sockaddr_in server_addr;
    int sock_desc;
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    #include "tcp-addr.h"
    connect(sock_desc, (struct sockaddr *)&server_addr, sizeof(server_addr));
    while (1) {
        printf("\nClient : ");
        scanf("%[^\n]%*c", msg2);
        send(sock_desc, msg2, sizeof(msg2), 0);
        if (strcmp(msg2, "end") == 0) break;
        recv(sock_desc, msg1, sizeof(msg1), 0);
        if (strcmp(msg1, "end") == 0) break;
        printf("\nServer : %s", msg1);
    }
    close(sock_desc);
}
