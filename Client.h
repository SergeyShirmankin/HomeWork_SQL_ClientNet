#pragma once
#include <iostream>
// ������������ ������ ������ ��� ������ � ��������
#define MESSAGE_BUFFER 4096
#define PORT 7777 // ����� �����, ������� ����� ������������ ��� ������ � ��������
void sendMess(std::string clientMessage); // ������������ ������ ���  �������� ��������� �������
std::string  recivMess(char arryChar[]);  //������������ ��������� ��� ���������� � �������
void sendRequest();
