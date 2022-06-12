char msg1[50] = "", msg2[50] = "";
server_addr.sin_family = AF_INET;
server_addr.sin_port = 2000;
server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
