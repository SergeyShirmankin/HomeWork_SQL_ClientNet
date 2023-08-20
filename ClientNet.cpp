#pragma comment(lib,"ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include "Client.h"
#include "ClientNet.h"
#include "file.h"
#pragma warning (disable:4996)
SOCKET Connection;
//----------------------------------------------------------------------------------
//-----------------------------------------------------
void ClientHandler()
{
	char msg[256];
	while (true)
	{
		recv(Connection, msg, sizeof(msg), NULL);
		//std::cout << msg << std::endl;
	}
}
//----------------------------------------------------------------------------------

 void mainClientNet()
{
	//WSAStartup
	 std::string Message;
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(7777);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)& addr, sizeof(addr)) != 0)
	{
		std::cout << "Error: failed connect to server.\n";
		return;
	}
	std::cout << "Connected!\n";
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)sendRequest, NULL, NULL, NULL);
	char msg1[256];
	while (true)
	{
		if (readFile(Message))
		{
			strcpy(msg1, Message.c_str());
			send(Connection, msg1, sizeof(msg1), NULL);
		}
	   Sleep(10);
	}
	system("pause");
}