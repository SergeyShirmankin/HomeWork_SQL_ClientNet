#pragma once
#include <iostream>
// ������������ ������ ������ ��� ������ � ��������
#define MESSAGE_BUFFER 256
#define PORT 7777 // ����� �����, ������� ����� ������������ ��� ������ � ��������
void sendMess(std::string clientMessage); // ������������ ������ ���  �������� ��������� �������
std::string  recivMess(char arryChar[]);  //������������ ��������� ��� ���������� � �������
void sendRequest();
void reciveStateProgram(char [MESSAGE_BUFFER]);
void msgTofile(std::string tmpMsg);