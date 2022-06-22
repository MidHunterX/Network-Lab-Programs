#include"network-libs.h"
void main() {
    struct sockaddr_in server_addr;
    int sock_desc;
    sock_desc = socket(AF_INET, SOCK_DGRAM, 0);
    #include"udp-addr.h"
    bind(sock_desc, (struct sockaddr *)&server_addr, sizeof(server_addr));
    while (1) {
        printf("Client : ");
        scanf("%[^\n]%*c", msg);
        sendto(sock_desc, msg, sizeof(msg), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (!(strcmp(msg, "end"))) break;
        recvfrom(sock_desc, msg, sizeof(msg), 0, NULL, NULL);
        printf("Server : %s\n", msg);
    }
}
