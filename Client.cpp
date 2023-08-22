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

char buffer[MESSAGE_BUFFER] ="Нет ответа от сервера !!!!";
char message[MESSAGE_BUFFER] = "not message";
int socket_descriptor;
std::string tempCin;
std::string tempMessage;
Log_pass  objLogPass;
std::string tempStateProgram;

//----------------------------------------------------------------------
			// отправляем сообщение потоку через файл 
void msgTofile(std::string tmpMsg)
{
	if (createFile(tmpMsg))
		std::cout << "Сообщение успешно было потоку :  " << std::endl;
	else
		std::cout << "Сообщение не было отправленно потоку :  " << std::endl;
	tempStateProgram = objLogPass.get_CurrentState();
}
//----------------------------------------------------------------------
std::string  recivMess(char arryChar[]) //формирование сообщения для полученная с сервера 
{
	char tempChar = 't';//инициализация пустой ячейки  значением "temp"
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
	bool autorization = false;//переменная для авторизацииж

	PrevMess objPrevMess;
	bool breakCicle = false;
	//while (1)
	
		if (autorization == false)
		{
			std::cout << "Для завершения работы наберите  --end--   или  --log--  для создание логина и пароля  --enter-- авторизации на сервере " << std::endl;
			std::cout << ">>" << std::endl;
			std::getline(std::cin >> tempCin, tempMessage);//забираем всю строку
			tempMessage = tempCin + " " + tempMessage;
			strcpy(message, tempMessage.c_str());//преооразуем строку в массив char
			if (tempMessage.compare("end ") == 0)
			{
				std::cout << "Закрываем соединение" << std::endl;
				exit(0);
			}
			else if (tempMessage.compare("log ") == 0)
			{
				tempMessage = objPrevMess.InterfaceLogPass(objPrevMess.managerInterLogPass);//Создаесм стартовое окно для создания логина и пароля или авторизация на сервере
				msgTofile(tempMessage);
				//strcpy(message, tempMessage.c_str());//преооразуем строку в массив char
				return;
			}
			else if (tempMessage.compare("enter ") == 0)
			{
				tempMessage = objPrevMess.enterLogPass(objLogPass.get_StateProgram());//Авторизация под логинои и паролем
				strcpy(message, tempMessage.c_str());
				objLogPass.parserMessage(message);
				return;
			}
		}

			else
				//-------------------------------------------------------------------------------------------------------------------------
				//-----------------------------Программа работы ссобщениямми---------------------------------------------------------------
				//-------------------------------------------------------------------------------------------------------------------------
			{
				char key;
				int countUsers = -1;
				while (autorization == true)
				{
					// breakCicle=false;
					std::cout << "\nДля выхода нажмите клавишу 'e' для продолжения нажмите любую кл и ent";
					std::cout << "\n>> ";
					std::getline(std::cin >> tempCin, tempMessage);//забираем всю строку
					tempMessage = tempCin + " " + tempMessage;
		         if (tempMessage.compare("e ") == 0)// Внимание не рабочий пример
					{
						tempMessage = "*--:--:--:--:--:--:--:--&";//Формируем пустое сообщение
						strcpy(message, tempMessage.c_str());//преооразуем строку в массив char
						autorization = false;
						break;
					}
					else
					{
						std::string resultStr = "*--:--:--:9:--:1:1:--&";
						strcpy(message, resultStr.c_str());//преооразуем строку в массив char
						std::cout << "Сообщение успешно было отправленно на сервер:  " << std::endl;
						std::cout << "Дождитесь ответа от сервера ..." << std::endl;
					}
				}

			}	    
			 const std::string tempCurrState = "100";
			if ((tempStateProgram.compare("7") == 0)&& autorization == false)//успешная авторизация
			{
				std::cout << "\n>> Сообщение полученно от сервера \n";
				std::cout << ">> Успешное авторизация!!!!\n";
				autorization = true;
				objLogPass.set_CurrentState(tempCurrState);

			}
		}
//-----------------------------------------------------------------------------------------

void reciveStateProgram(char bufferMsg [MESSAGE_BUFFER] )
{
	objLogPass.parserMessage(bufferMsg);
	std::string tmpStateProgram = objLogPass.get_CurrentState();
	if (tmpStateProgram.compare("3") == 0)// успешное создание лога и пароля
	{
		std::cout << "\n>> Сообщение полученно от сервера\n ";
		std::cout << ">> Успешное создание лога и павроля!!!\n";
	}
	else if (tmpStateProgram.compare("4") == 0)//Не удалось создать  лог ипароль
	{
		std::cout << "\n>> Сообщение полученно от сервера\n ";
		std::cout << ">> Не удалось создать логин ипароль!!!\n ";
	}
	else if (tmpStateProgram.compare("5") == 0)//Такой логин и пароль уже есть
	{
		std::cout << "\n>> Сообщение полученно от сервера \n";
		std::cout << ">> Такой пароль уже есть!!!\n";
	}
	else if (tmpStateProgram.compare("7") == 0 )//успешная авторизация
	{
		std::cout << "\n>> Сообщение полученно от сервера \n";
		std::cout << ">> Успешное авторизация!!!!\n";
		//autorization = true;
		//             objLogPass.set_CurrentState("--");
	}

	else if (tmpStateProgram.compare("8") == 0)//Нету доступа
	{
		std::cout << "\n>> Сообщение полученно от сервера \n";
		std::cout << ">> Нету доступа!!!\n";
	}
	else
	{
		std::cout << "Сервер не отвечает " << std::endl;;
	}
}