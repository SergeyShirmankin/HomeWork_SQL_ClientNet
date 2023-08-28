#include "LogPass.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Client.h"
#include "prepMess.h"
#include "file.h"

#pragma warning(disable : 4996)
#define DEBUG_STEP_1
#define DEBUG_STEP_2
//#define DEBUG_STEP_3

char buffer[MESSAGE_BUFFER] ="��� ������ �� ������� !!!!";
char message[MESSAGE_BUFFER] = "not message";
int socket_descriptor;
std::string tempCin;
std::string tempMessage;
Log_pass  objLogPass;
std::string tempStateProgram;
bool autorization = false;//���������� ��� ������������
//-------------------------------------------------------------------
void delete_()
{
	std::string Msg = "*--:" + objLogPass.get_NameUserSend() + ":--:14:" + objLogPass.get_CurrentState() + ":1:1--&";
	msgTofile(Msg);
}
//----------------------------------------------------------------------
			// ���������� ��������� ������ ����� ���� 
void msgTofile(std::string tmpMsg)
{
	if (createFile(tmpMsg))
		std::cout << "��������� ������� ���� ������ :  " << std::endl;
	else
		std::cout << "��������� �� ���� ����������� ������ :  " << std::endl;
	tempStateProgram = objLogPass.get_CurrentState();
}
//----------------------------------------------------------------------
std::string  recivMess(char arryChar[]) //������������ ��������� ��� ���������� � ������� 
{
	char tempChar = 't';//������������� ������ ������  ��������� "temp"
	int i = 0;
	std::string tempStr = "";
	while (tempChar != '\0')
	{
		tempChar = arryChar[i];
		tempStr = tempStr + tempChar;
		i++;
	}
	return  tempStr;

}
//-----------------------------------------------------------------------------------
void sendRequest()
{
	PrevMess objPrevMess;
	bool breakCicle = false;
	while (true)
	{
		if (autorization == false)
		{
			std::cout << "��� ���������� ������ ��������  --end--   ���  --log--  ��� �������� ������ � ������  --enter-- ����������� �� ������� " << std::endl;
			std::cout << ">>" << std::endl;
			std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
			tempMessage = tempCin + " " + tempMessage;
			strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
			if (tempMessage.size() != 0)
			{
				if (tempMessage.compare("end ") == 0 || tempMessage.compare("log ") == 0 || tempMessage.compare("enter ") == 0)
				{
					if (tempMessage.compare("end ") == 0)
					{
						std::cout << "��������� ����������" << std::endl;
					    delete_();
						exit(0);
					}
					else if (tempMessage.compare("log ") == 0)
					{
						tempMessage = objPrevMess.InterfaceLogPass(objPrevMess.managerInterLogPass);//�������� ��������� ���� ��� �������� ������ � ������ ��� ����������� �� �������
						msgTofile(tempMessage);
						//strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
						return;
					}
					else if (tempMessage.compare("enter ") == 0)
					{
						tempMessage = objPrevMess.enterLogPass(objLogPass.get_StateProgram());//����������� ��� ������� � �������
						msgTofile(tempMessage);
						return;
					}
				}
			}
		}


		else
			//-------------------------------------------------------------------------------------------------------------------------
			//-----------------------------��������� ������ ������������---------------------------------------------------------------
			//-------------------------------------------------------------------------------------------------------------------------
		{
			char key;
			int countUsers = -1;
			while (autorization == true)
			{

				std::cout << "\n��� ������ ������� ������� 'e' ��� ����������� ������� ����� �� � ent";
				std::cout << "\n>> ";
				std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
				tempMessage = tempCin + " " + tempMessage;
				if (tempMessage.compare("e ") == 0)// �������� �� ������� ������
				{
					autorization = false;
				}
				else
				{
					system("cls");
					std::string Msg = "*--:"+objLogPass.get_NameUserSend()+":--:9:"+ objLogPass.get_CurrentState() +":1:1--&"; //9 ������ ����������� �������������
					msgTofile(Msg);
					std::cout << "Online users: ";
					autorization = false; //����� �� ���������
				}
			}

		}
	}
}
//-----------------------------------------------------------------------------------------

void reciveStateProgram(char bufferMsg [MESSAGE_BUFFER] )
{
	objLogPass.parserMessage(bufferMsg);
	std::string tmpStateProgram = objLogPass.get_CurrentState();
	if (tmpStateProgram.compare("3") == 0)// �������� �������� ���� � ������
	{
		std::cout << "\n>> ��������� ��������� �� �������\n ";
		std::cout << ">> �������� �������� ���� � �������!!!\n";
	}
	else if (tmpStateProgram.compare("4") == 0)//�� ������� �������  ��� �������
	{
		std::cout << "\n>> ��������� ��������� �� �������\n ";
		std::cout << ">> �� ������� ������� ����� �������!!!\n ";
	}
	else if (tmpStateProgram.compare("5") == 0)//����� ����� � ������ ��� ����
	{
		std::cout << "\n>> ��������� ��������� �� ������� \n";
		std::cout << ">> ����� ������ ��� ����!!!\n";
	}
	else if (tmpStateProgram.compare("7") == 0 )//�������� �����������
	{
		std::cout << "\n>> ��������� ��������� �� ������� \n";
		std::cout << ">> �������� �����������!!!!\n";
		autorization = true; 
		objLogPass.set_CurrentState("13");
	}

	else if (tmpStateProgram.compare("8") == 0)//���� �������
	{
		std::cout << "\n>> ��������� ��������� �� ������� \n";
		std::cout << ">> ���� �������!!!\n";
	}
	else
	{
		std::cout << "������ �� �������� " << std::endl;;
	}
}