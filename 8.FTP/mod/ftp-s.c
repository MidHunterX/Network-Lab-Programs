#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define PORT 5035
#define MAX 60
int i, j, tem;
char buff[4096], t;
FILE *f1;
void main() {
	int sockfd, newsockfd, clength;
	struct sockaddr_in serv_addr, cli_addr;
	char t[MAX], str[MAX];
	strcpy(t, "exit");
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);
	printf("\nBinded");
	bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	printf("\nListening...");
	listen(sockfd, 5);
	clength = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clength);
	close(sockfd);
	read(newsockfd, &str, MAX);
	printf("\nClient message\n File Name : %s\n", str);
	f1 = fopen(str, "r");
	while (fgets(buff, 4096, f1) != NULL) {
		write(newsockfd, buff, MAX);
		printf("\n");
	}
	fclose(f1);
	printf("\nFile Transferred\n");
}
