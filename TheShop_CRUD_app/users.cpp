#include <iostream>
#include <string>
#include <Windows.h>
#include "users.h"

void signup(User& x) {
start:
	static int id = 1;
	std::fstream nextId;
	nextId.open("nextid_register.txt", std::fstream::in);
	nextId >> id;
	nextId.close();
	std::cout << "username: ";
	std::cin >> x.m_username;
	std::cout << "password: ";
	std::cin >> x.m_password;
	if (!verify_singup(x.m_username)) {
		std::cout << "Username was taken! Try again!!";
		Sleep(700);
		system("cls");
		goto start;
	}
	x.m_roleType = 0;
	std::fstream record;
	record.open("users.txt", std::fstream::app | std::fstream::out);
	record << id << ' ';
	record << x.m_username << ' ';
	record << x.m_password << ' ';
	record << x.m_roleType;
	record << '\n';
	record.close();
	nextId.open("nextid_register.txt", std::fstream::out);
	nextId << ++id;
	std::cout << "Success!\n";
	nextId.close();
}
bool login(User& x) {
start_login:
	int attempt = 0;
	std::string username, password, usern, pass;
	int lgid, roletype;

	system("cls");//curata ecranul;
	std::cout << "username: ";
	std::cin >> username;
	std::cout << "password: ";
	std::cin >> password;
	std::fstream loginfin;
	loginfin.open("users.txt", std::fstream::in);


	while (loginfin >> lgid >> usern >> pass >> roletype)
	{
		if (username == usern && password == pass) {
			attempt = 1;
			std::cout << "Login Successful";
			loginfin.close();
			x.m_id = lgid;
			x.m_password = password;
			x.m_username = username;
			x.m_roleType = roletype;
			break;
		}

	}
	if (attempt == 0) {
		std::cout << "Wrong username or password. Try again!!";
		Sleep(700);
		goto start_login;
	}
	return roletype;
}
bool verify_singup(std::string x) {
	std::string usern, pass;
	int lgid, roletype;
	std::fstream verify;
	verify.open("users.txt", std::fstream::in);
	while (verify >> lgid >> usern >> pass >> roletype)
		if (x == usern) {
			verify.close();
			return 0;
		}
	verify.close();
	return 1;
}