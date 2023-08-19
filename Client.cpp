#include "LogPass.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Client.h"
#include "prepMess.h"

#pragma warning(disable : 4996)
#define DEBUG_STEP_1
#define DEBUG_STEP_2
#define DEBUG_STEP_3

char buffer[MESSAGE_BUFFER] ="Ќет ответа от сервера !!!!";
char message[MESSAGE_BUFFER] = "not message";
int socket_descriptor;
std::string tempCin;
std::string tempMessage;
Log_pass  objLogPass;
std::string tempStateProgram;


//#ifdef DEBUG
//#else
//#endif

//----------------------------------------------------------------------
//----------------------------------------------------------------------
std::string  recivMess(char arryChar[]) //формирование сообщени€ дл€ полученна€ с сервера 
{
	char tempChar = 't';//инициализаци€ пустой €чейки  значением "temp"
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
	bool autorization = false;//переменна€ дл€ авторизацииж

	PrevMess objPrevMess;
	bool breakCicle = false;

#ifdef  DEBUG_STEP_1
	while (1)
	{
		if (autorization == false)
		{
			std::cout << "ƒл€ завершени€ работы наберите  --end--   или  --log--  дл€ создание логина и парол€  --enter-- авторизации на сервере " << std::endl;
			std::cout << ">>" << std::endl;
			std::getline(std::cin >> tempCin, tempMessage);//забираем всю строку
			tempMessage = tempCin + " " + tempMessage;
			strcpy(message, tempMessage.c_str());//преооразуем строку в массив char
			if (tempMessage.compare("end ") == 0)
			{
				std::cout << "«акрываем соединение" << std::endl;
				exit(0);
			}
			else if (tempMessage.compare("log ") == 0)
			{
				tempMessage = objPrevMess.InterfaceLogPass(objPrevMess.managerInterLogPass);//—оздаесм стартовое окно дл€ создани€ логина и парол€ или авторизаци€ на сервере
				strcpy(message, tempMessage.c_str());//преооразуем строку в массив char
			}
			else if (tempMessage.compare("enter ") == 0)
			{
				tempMessage = objPrevMess.enterLogPass(objLogPass.get_StateProgram());//јвторизаци€ под логинои и паролем
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
				//-----------------------------ѕрограмма работы ссобщени€мми---------------------------------------------------------------
				//-------------------------------------------------------------------------------------------------------------------------
			{
				char key;
				int countUsers = -1;
				while (autorization == true)
				{
					// breakCicle=false;
					std::cout << "\nƒл€ выхода нажмите клавишу 'e' дл€ продолжени€ нажмите любую кл и ent";
					std::cout << "\n>> ";
					std::getline(std::cin >> tempCin, tempMessage);//забираем всю строку
					tempMessage = tempCin + " " + tempMessage;
		         if (tempMessage.compare("e ") == 0)// ¬нимание не рабочий пример
					{
						tempMessage = "*--:--:--:--:--:--:--:--&";//‘ормируем пустое сообщение
						strcpy(message, tempMessage.c_str());//преооразуем строку в массив char
						autorization = false;
						break;
					}
					else
					{
						std::string resultStr = "*--:--:--:9:--:1:1:--&";
						strcpy(message, resultStr.c_str());//преооразуем строку в массив char
						std::cout << "—ообщение успешно было отправленно на сервер:  " << std::endl;
						std::cout << "ƒождитесь ответа от сервера ..." << std::endl;
					}
				}

			}
#endif
			//--------------------------------------------------------------------------------------------------------------------------
			//--------------------------------------------------------------------------------------------------------------------------
			//--------------------------------------------------------------------------------------------------------------------------



		//	std::cout << "—ообщение успешно было отправленно на сервер:  " << message << std::endl;
		//	std::cout << "ƒождитесь ответа от сервера ..." << std::endl;

		//	//std::cout << "—ообщение полученно от сервера " << std::endl;

		//	objLogPass.parserMessage(buffer);
		//	//std::cout << "—ообщение полученно от сервера " << std::endl;

		//	tempStateProgram = objLogPass.get_CurrentState();
		//	std::string  tempRequestProgram = objLogPass.get_Request();
		//	if (tempStateProgram.compare("3") == 0)// успешное создание лога и парол€
		//	{
		//		std::cout << "\n>> —ообщение полученно от сервера\n ";
		//		std::cout << ">> ”спешное создание лога и паврол€!!!\n";
		//	}
		//	else if (tempStateProgram.compare("4") == 0)//Ќе удалось создать  лог ипароль
		//	{
		//		std::cout << "\n>> —ообщение полученно от сервера\n ";
		//		std::cout << ">> Ќе удалось создать логин ипароль!!!\n ";
		//	}
		//	else if (tempStateProgram.compare("5") == 0)//“акой логин и пароль уже есть
		//	{
		//		std::cout << "\n>> —ообщение полученно от сервера \n";
		//		std::cout << ">> “акой пароль уже есть!!!\n";
		//	}
		//	else if (tempStateProgram.compare("7") == 0 && tempRequestProgram.compare("6") == 0)//успешна€ авторизаци€
		//	{
		//		std::cout << "\n>> —ообщение полученно от сервера \n";
		//		std::cout << ">> ”спешное авторизаци€!!!!\n";
		//		autorization = true;
		//		//             objLogPass.set_CurrentState("--");
		//	}


#ifdef  DEBUG_STEP_2
		 tempStateProgram = objLogPass.get_CurrentState();
		 const std::string tempCurrState = "100";
		if ((tempStateProgram.compare("7") == 0)&& autorization == false)//успешна€ авторизаци€
		{
			std::cout << "\n>> —ообщение полученно от сервера \n";
			std::cout << ">> ”спешное авторизаци€!!!!\n";
			autorization = true;
			objLogPass.set_CurrentState(tempCurrState);

		}
#endif
		//	else if (tempStateProgram.compare("8") == 0)//Ќету доступа
		//	{
		//		std::cout << "\n>> —ообщение полученно от сервера \n";
		//		std::cout << ">> Ќету доступа!!!\n";
		//	}
		//	else
		//	{
		//		std::cout << "—ервер не отвечает " << std::endl;;
		//	}
		//}
		// закрываем сокет, завершаем соединение
	}
}


