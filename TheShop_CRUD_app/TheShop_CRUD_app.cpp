#include <iostream>
#include <string.h>
#include <fstream>
#include <Windows.h>

//std::fstream lgin("login.txt");
int id;

class Product {
protected:
	float m_weight;
	float m_height;
	float m_TDP;
	int m_nm;
	int m_memory;
	float m_clock_freq;
	float m_price;
	char m_release_date[25];

public:
	Product& SetWeight(/*float weight*/) {
		//this->m_weight = weight;
		std::cout << "Weight: ";
		std::cin >> m_weight;
		return *this;
	}
	Product& SetHeight(/*float height*/) {
		//this->m_height = height;
		std::cout << "Height: ";
		std::cin >> m_height;
		return *this;
	}
	Product& SetTDP(/*float TDP*/) {
		//this->m_TDP = TDP;
		std::cout << "TDP: ";
		std::cin >> m_TDP;
		return *this;
	}
	Product& SetNM(/*int nm*/) {
		//this->m_nm = nm;
		std::cout << "nm: ";
		std::cin >> m_nm;
		return *this;
	}
	Product& SetMemory(/*int memory*/) {
		//this->m_memory = memory;
		std::cout << "Memory: ";
		std::cin >> m_memory;
		return *this;
	}
	Product& SetFreq(/*float freq*/) {
		//this->m_clock_freq = freq;
		std::cout << "Clock Frequency: ";
		std::cin >> m_clock_freq;
		return *this;
	}
	Product& SetPrice(/*float price*/) {
		//this->m_price = price;
		std::cout << "Price: ";
		std::cin >> m_price;
		return *this;
	}
	Product& SetReleaseDate(/*std::string release_date*/) {
		//this->m_release_date = release_date;
		std::cout << "Release date: ";
		std::cin.ignore();
		std::cin.get(m_release_date, 25);
		return *this;
	}
	float GetWeight(void) {
		return m_weight;
	}
	float GetHeight(void) {
		return m_height;
	}
	float GetTDP(void) {
		return m_TDP;
	}
	float GetNM(void) {
		return m_nm;
	}
	float GetFreq(void) {
		return m_clock_freq;
	}
	float GetPrice(void) {
		return m_price;
	}
	std::string GetReleaseDate(void) {
		return m_release_date;
	}
};

class CPU :public Product {
protected:
	int m_core;
	int m_threads;
	char m_socket[25];

public:
	CPU& SetCore(/*int core*/) {
		//this->m_core = core;
		std::cout << "Core: ";
		std::cin >> m_core;
		return *this;
	}
	CPU& SetThreads(/*int threads*/) {
		//this->m_threads = threads;
		std::cout << "Treads: ";
		std::cin >> m_threads;
		return*this;
	}
	CPU& SetSocket(/*std::string socket*/) {
		//this->m_socket = socket;
		std::cout << "Socket: ";
		std::cin.ignore();
		std::cin.get(m_socket, 25);
		return *this;
	}
	int GetCore(void) {
		return m_core;
	}
	int GetThreads(void) {
		return m_threads;
	}
	std::string GetSocket(void) {
		return m_socket;
	}

	CPU& IntroduceAllData(void) {
		SetCore().SetThreads().SetSocket().SetWeight().SetHeight().SetTDP().SetNM().SetFreq().SetPrice().SetReleaseDate();
		return *this;
	}
};

enum  tech { OpenGL = 1, DirectX = 2 };

class GPU :public Product {
protected:
	char m_max_resolution[25];
	tech m_tech;
public:
	GPU& SetMaxResolution(/*std::string max_resolution*/) {
		//this->m_max_resolution = max_resolution;
		std::cout << "Max Resolution: ";
		std::cin.ignore();
		std::cin.get(m_max_resolution, 25);
		//m_max_resolution[strlen(m_max_resolution) + 1] = '\0';
		return *this;
	}
	//GPU& SetTechnologies(tech r_tech) {
	//	m_tech = r_tech;
	//	//std::cin >> m_tech;
	//	return *this;
	//}
	//tech GetTechnologies(void) {
	//	return m_tech;
	//}
	std::string GetMaxResolution(void) {
		return m_max_resolution;
	}

	GPU& IntroduceAllData(void) {
		SetMaxResolution().SetWeight().SetHeight().SetTDP().SetNM().SetFreq().SetPrice().SetReleaseDate();
		return *this;
	}
};

class APU : public CPU, public GPU {
public:
	GPU& IntroduceAllData(void) {
		SetCore().SetThreads().SetSocket();
		SetMaxResolution().SetWeight().SetHeight().SetTDP().SetNM().SetFreq().SetPrice().SetReleaseDate();
		return *this;
	}
};


class User {
public:
	int m_id;
	std::string m_username;
	std::string m_password;
	int m_roleType = 0;



};


void signup(User& x) {
	std::ofstream record("records.txt");
	record << id++ << ' ';
	std::cout << "username: ";
	std::cin >> x.m_username; std::cin.ignore();
	record << x.m_username << " ";
	std::cout << "password: ";
	std::cin >> x.m_password; std::cin.ignore();
	record << x.m_password;
	record << std::endl;
	std::cout << "Success!\n";
}

int attempt = 1;
void login(User& x) {

	std::string username, password, usern, pass;
	int lgid;
start_login:
	system("cls");//curata ecranul;
	std::cout << "username: ";
	std::cin >> username;
	std::cout << "password: ";
	std::cin >> password;
	std::ifstream lgin("records.txt");
	while (lgin >> lgid >> usern >> pass)
	{
		if (username == usern && password == pass) {
			attempt = 1;
			std::cout << "Login Successful";
		}
		else {
			attempt++;
			if (attempt <= 5) {
				std::cout << "Wrong username or password. Try again!!";
				Sleep(500);
				goto start_login;
			}
			else std::cout << "5 failed login. Your are NUB";
			std::exit(11);
		}

	}
	lgin.close();
	x.m_id = lgid;
	x.m_password = password;
	x.m_username = username;
	x.m_roleType = 0;
}


User x[1000], y;

int main() {
	int option;
	std::cout << "AMD Shop Menu:\n";
start:
	std::cout << "\n\nSelect Option:\n\n";
	std::cout << "1. SignUp\n";
	std::cout << "2. SignIn\n";
	std::cout << "3. Your menu\n";
	std::cout << "4. Exit\n\n";
	std::cout << "Your choice: ";
	std::cin >> option;
	switch (option) {
	case 1: {system("cls"); signup(x[id++]); goto start; }
	case 2: {system("cls"); login(y); goto start; }
	case 3: {std::cout << "In lucru!!"; break; }
	case 4: {system("cls"); std::exit(-1); }
	}
	return 0;
}