#include <iostream>
#include "prepMess.h"
#include <vector>
#include "Client.h"
#define DEBUG_STEP_2

PrevMess::PrevMess()//����������� �� ���������
{
	managerInterLogPass = true;
}


	std::string PrevMess::addLogPass()
	{
		std::cout << " ������� ����� ������ ������������: " << std::endl;
		std::cout << ">> ";
		std::cin >> login;//������ ����� �����
		std::cout << "������� ������ ������: " << std::endl;
		std::cout << ">> ";
		std::cin >> password;
		std::string resultStr = password + ":" + login;
		return resultStr;
	}

	std::string PrevMess::InterfaceLogPass(bool StartFunction)//�������� ��������� ���� �� ������� ������ � ����� ��� ���������� �� �������
	{
			std::string tempStr;
			std::string tempOP;
		//	char* op;//������ ������� ��������
		//----------------------------------------------------------------------
			if (StartFunction)
			{
				while(true)
				{ 
				std::cout << "��� ����������� ������� ����� �������\n ";
				std::cout << ">> ";
				std::cin >> tempOP;
				if (tempOP.size()!= 0)
				//{
				//	std::vector<char>chars(tempOP.begin(), tempOP.end());//��������������� string ->char
				//	chars.push_back('\0');
				//	op = &chars[0];
				//	switch (*op)
				//	{
				//	case'n':
						tempStr = addLogPass();
						tempStr = "*" + tempStr + ":--:2:1:1:1:--&";
						return tempStr;
					//defalt:
					//	std::cout << "����������� ������� �����";
					//}
				}
			}
			//----------------------------------------------------------------------

	}

	//-----------------------------------------------------------------------------------------------
	// ----------------------------�������  ������������---------------------------------------------
	//---------------------------------------------------------------------------------------------
	std::string PrevMess::enterLogPass(std::string _stateProgram)
	{
		std::string _password;
		std::string _login;
		std::string  resultStr;
		std::cout << " ������� ����� ������ ������������: " << std::endl;
		std::cout << ">> ";
		std::cin >> _login;//������ ����� �����
		std::cout << "������� ������\n";
		std::cout << ">> ";
		std::cin >> _password;

#ifdef  DEBUG_STEP_2
		_stateProgram = "7";
#endif
		resultStr = "*" + _password + ":" + _login + ":--:6:" + _stateProgram + ":1:1:--&";
		return resultStr;
	}
	void  PrevMess::showMessages()
	{
		int a = 5;
	}