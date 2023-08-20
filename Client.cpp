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

void sendRequest() 
{
	bool autorization = false;//���������� ��� ������������

	PrevMess objPrevMess;
	bool breakCicle = false;

#ifdef  DEBUG_STEP_1
	while (1)
	{
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
				//strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
			}
			else if (tempMessage.compare("enter ") == 0)
			{
				tempMessage = objPrevMess.enterLogPass(objLogPass.get_StateProgram());//����������� ��� ������� � �������
				strcpy(message, tempMessage.c_str());
#ifdef  DEBUG_STEP_2
				objLogPass.parserMessage(message);
#endif
			}
		}

#endif
#ifdef  DEBUG_STEP_3
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
#endif
			//--------------------------------------------------------------------------------------------------------------------------
			//--------------------------------------------------------------------------------------------------------------------------
			//--------------------------------------------------------------------------------------------------------------------------	    
			// ���������� ��������� ������ ����� ���� 
	        if ( createFile(tempMessage))
				std::cout << "��������� ������� ���� ������ :  " <<std::endl;
			else 
				std::cout << "��������� �� ���� ����������� ������ :  " << std::endl;
			



			objLogPass.parserMessage(buffer);


			tempStateProgram = objLogPass.get_CurrentState();
			std::string  tempRequestProgram = objLogPass.get_Request();
			if (tempStateProgram.compare("3") == 0)// �������� �������� ���� � ������
			{
				std::cout << "\n>> ��������� ��������� �� �������\n ";
				std::cout << ">> �������� �������� ���� � �������!!!\n";
			}
			else if (tempStateProgram.compare("4") == 0)//�� ������� �������  ��� �������
			{
				std::cout << "\n>> ��������� ��������� �� �������\n ";
				std::cout << ">> �� ������� ������� ����� �������!!!\n ";
			}
			else if (tempStateProgram.compare("5") == 0)//����� ����� � ������ ��� ����
			{
				std::cout << "\n>> ��������� ��������� �� ������� \n";
				std::cout << ">> ����� ������ ��� ����!!!\n";
			}
			else if (tempStateProgram.compare("7") == 0 && tempRequestProgram.compare("6") == 0)//�������� �����������
			{
				std::cout << "\n>> ��������� ��������� �� ������� \n";
				std::cout << ">> �������� �����������!!!!\n";
				autorization = true;
				//             objLogPass.set_CurrentState("--");
			}


#ifdef  DEBUG_STEP_2
		 tempStateProgram = objLogPass.get_CurrentState();
		 const std::string tempCurrState = "100";
		if ((tempStateProgram.compare("7") == 0)&& autorization == false)//�������� �����������
		{
			std::cout << "\n>> ��������� ��������� �� ������� \n";
			std::cout << ">> �������� �����������!!!!\n";
			autorization = true;
			objLogPass.set_CurrentState(tempCurrState);

		}
#endif
			else if (tempStateProgram.compare("8") == 0)//���� �������
			{
				std::cout << "\n>> ��������� ��������� �� ������� \n";
				std::cout << ">> ���� �������!!!\n";
			}
			else
			{
				std::cout << "������ �� �������� " << std::endl;;
			}
		}
		
	}



