#include"network-libs.h"

void main() {
    struct sockaddr_in client_addr, server_addr;
    int sock_desc,n;
    sock_desc = socket(AF_INET, SOCK_DGRAM, 0);
	#include"udp-addr.h"
    bind(sock_desc, (struct sockaddr *)&server_addr, sizeof(server_addr));
    n=sizeof(client_addr);
    while (1) {
        recvfrom(sock_desc, msg, sizeof(msg), 0, (struct sockaddr *)&client_addr,&n);
        if (!(strcmp(msg, "end"))) break;
        printf("Client : %s\n", msg);
        printf("Server : ");
        scanf("%[^\n]%*c", msg);
        sendto(sock_desc, msg, sizeof(msg), 0, (struct sockaddr *)&client_addr, n);
    }
}
