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
	bool autorization = false;//���������� ��� ������������

	PrevMess objPrevMess;
	bool breakCicle = false;
	//while (1)
	
		if (autorization == false)
		{
			std::cout << "��� ���������� ������ ��������  --end--   ���  --log--  ��� �������� ������ � ������  --enter-- ����������� �� ������� " << std::endl;
			std::cout << ">>" << std::endl;
			std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
			tempMessage = tempCin + " " + tempMessage;
			strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
			if (tempMessage.compare("end ") == 0)
			{
				std::cout << "��������� ����������" << std::endl;
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
				strcpy(message, tempMessage.c_str());
				objLogPass.parserMessage(message);
				return;
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
					// breakCicle=false;
					std::cout << "\n��� ������ ������� ������� 'e' ��� ����������� ������� ����� �� � ent";
					std::cout << "\n>> ";
					std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
					tempMessage = tempCin + " " + tempMessage;
		         if (tempMessage.compare("e ") == 0)// �������� �� ������� ������
					{
						tempMessage = "*--:--:--:--:--:--:--:--&";//��������� ������ ���������
						strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
						autorization = false;
						break;
					}
					else
					{
						std::string resultStr = "*--:--:--:9:--:1:1:--&";
						strcpy(message, resultStr.c_str());//����������� ������ � ������ char
						std::cout << "��������� ������� ���� ����������� �� ������:  " << std::endl;
						std::cout << "��������� ������ �� ������� ..." << std::endl;
					}
				}

			}	    
			 const std::string tempCurrState = "100";
			if ((tempStateProgram.compare("7") == 0)&& autorization == false)//�������� �����������
			{
				std::cout << "\n>> ��������� ��������� �� ������� \n";
				std::cout << ">> �������� �����������!!!!\n";
				autorization = true;
				objLogPass.set_CurrentState(tempCurrState);

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
		//autorization = true;
		//             objLogPass.set_CurrentState("--");
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