#pragma once
#include <iostream>
#include <string>
#include <fstream>

class User {
public:
	int m_id = 0;
	std::string m_username;
	std::string m_password;
	bool m_roleType = 0;

	void AddMod(std::string username) {
		std::string password, usern;
		int lgid, roletype;
		bool valid = 0;
		std::fstream read_user, write_user;
		read_user.open("users.txt", std::fstream::in);
		write_user.open("temp.txt", std::fstream::app | std::fstream::out);
		while (read_user >> lgid >> usern >> password >> roletype) {
			write_user << lgid << ' ';
			write_user << usern << ' ';
			write_user << password << ' ';
			if (usern == username) {
				roletype = 1;
				valid = 1;
			}
			write_user << roletype;
			write_user << '\n';
		}
		if (valid)
			std::cout << "\nSuccess!!";
		else
			std::cout << "\nUsername not found!! (" << username << ")";
		read_user.close();
		write_user.close();
		remove("users.txt");
		rename("temp.txt", "users.txt");
	}
};

bool verify_singup(std::string x);
void signup(User& x);
bool login(User& x);