// Libraries needed for implementing basic network connections
#include <stdio.h>      // Standard Input/Output
#include <sys/socket.h> // Defines sockaddr struct (addr_family, sock_addr) , int SOCK_DGRAM , accept(), bind(), connect(), listen(), recv(), send() etc.
#include <arpa/inet.h>  // in_addr structures, inet_addr()
#include <netinet/in.h> // For address structures
#include <string.h>     // strcmp used here
#include <unistd.h>     // file descriptor close()
// #include <sys/stat.h> // not needed
// #include <sys/types.h>// not needed
