#pragma once
#include <iostream>
#include <string>
class PrevMess {
	public:
		PrevMess();//����������� �� ���������
		//��������� ���� ��� ����� ������ ������
		//��������� ��������� ��� ������� ��� �� ��� �������� ��������
		std::string InterfaceLogPass(bool StartFunction);//�������� �������� ��� �������� � ������
		std::string addLogPass();
		std::string enterLogPass(std::string);
		void showMessages();
	private:
		//Log_pass* ptrObject;// ��������� �� ������
		std::string login;//���� ������
		std::string password;// ���� ������
	public:
		bool managerInterLogPass; //��������� ������� �������
};