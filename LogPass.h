#pragma once
#pragma once
#include <iostream>
#include <string>

class Log_pass
{
public:
	Log_pass();//����������� �� ���������
//	~Log_pass();//��������� �� ���������
	void parserMessage(char arrChar[]);
	void set_PasswUser(const std::string&);
	void set_NameUserSend(const std::string&);
	void set_NameUserRecive(const std::string&);
	void set_Request(const std::string&);
	void set_CurrentState(const std::string&);
	void set_Messaqge(const std::string&);
	void set_NumMess(const std::string&);  //���������� ��������
	void set_NumCurrMess(const std::string&); //����� ���������
	void set_StateProgram(int);
	void addLogPass();

	std::string& get_PasswordUser();
	std::string& get_NameUserSend();
	std::string& get_NameUserRecive();
	std::string& get_Request();
	std::string& get_CurrentState();
	std::string& get_Messaqge();
	std::string get_StateProgram();
	std::string& get_NumMess();  //���������� ��������
	std::string& get_NumCurrMess(); //����� ���������
//-----------------------------------------------------------------------
private:
	int countObjectLogPass;//������� �������� ����� � �������
	std::string StateProgram;

	std::string PasswordUser;//������ ������������  ����������� ���������
	std::string NameUserSend;// ��� ������������  ����������� ���������
	std::string NameUserRecive;//  ��� ������������ ������������ ���������
	std::string Request;// ������ �� ���������� ��������� (�������)
	std::string CurrentState;//������� ��������� ���������
	std::string NumCurrMess; //����� ���������
	std::string NumMess;  //���������� ��������
	std::string Messaqge;
};
