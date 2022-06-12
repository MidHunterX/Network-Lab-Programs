/*
* A socket is one endpoint of a two-way communication on the network.
* It is bound to a port number.
* Acts as an endpoint for delivering and receiving data.
* Each socket within the network has a unique name associated with it called a socket descriptor.
*/
#include"network-libs.h"

void main() {

    // Struct address information
    struct sockaddr_in client_addr, server_addr; // only sockaddr_in predefined
    int sock_desc, client_sock, client_size;

    // Create a socket that returns a socket descriptor
    // socket(domain, type, protocol)
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);


    /*   Structure   *\
    * --------------- *
    * If the socket descriptor socket was created in the AF_INET domain, the format of the name buffer is expected to be sockaddr_in, as defined in the include file netinet/in.h:
    struct in_addr {
        ip_addr_t s_addr;
    };
    struct sockaddr_in {
        unsigned char  sin_len;
        unsigned char  sin_family;
        unsigned short sin_port;
        struct in_addr sin_addr;
        unsigned char  sin_zero[8];
    };
    * The sin_family field must be set to AF_INET.
    * The sin_port field is set to the port to which the application must bind. It must be specified in network byte order. If sin_port is set to 0, the caller leaves it to the system to assign an available port.
    * The sin_addr.s_addr field is set to the Internet address and must be specified in network byte order.
    Source : https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-bind-bind-name-socket */

    // Init port and IP
    #include "tcp-addr.h"
    /* Macro included in custom header
    -----------------------------------
    char msg1[50] = "", msg2[50] = "";
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = 2000;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); */


    /*    BIND()    *\
    * -------------- *
    * The bind() function binds a unique local name to the socket with descriptor socket.
    * After calling socket(), a descriptor does not have a name associated with it.
    * bind(socket, addr, addr_len) */
    // Bind the socket descriptor to the server address:
    bind(sock_desc, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Turn on the socket to listen for incoming connections:
    listen(sock_desc, 1);
    client_size = sizeof(client_addr);
    client_sock = accept(sock_desc, (struct sockaddr *)&client_addr, &client_size);
    // The server-side code stops and waits at accept() until a client calls connect().

    // After connection :
    while (1) {
        // The recv() function shall receive a message from a connection-mode or connectionless-mode socket.
        // recv (socket, buffer, length, flag)
        recv(client_sock, msg1, sizeof(msg1), 0);
        if (strcmp(msg1, "end") == 0) break;
        printf("\nClient : %s", msg1);
        printf("\nServer : ");
        scanf("%[^\n]%*c", msg2);
        send(client_sock, msg2, sizeof(msg2), 0);
        if (strcmp(msg2, "end") == 0) break;
    }

    // Closing the socket:
    close(client_sock);
    close(sock_desc);
}
