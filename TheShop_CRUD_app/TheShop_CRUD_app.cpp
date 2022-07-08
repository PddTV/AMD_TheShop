#include <iostream>
#include <string.h>
#include <fstream>
#include <Windows.h>

class Product {
protected:
	float m_weight;
	float m_height;
	float m_TDP;
	int m_nm;
	int m_memory;
	float m_clock_freq;
	float m_price;
	std::string m_release_date;

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
		std::cin>>m_release_date;
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
	std::string m_socket;

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
		std::cin>>m_socket;
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

	CPU& AddProduct(void) {
		SetCore().SetThreads().SetSocket().SetWeight().SetHeight().SetTDP().SetNM().SetFreq().SetPrice().SetReleaseDate();
		return *this;
	}
};

class GPU :public Product {
protected:
	std::string m_max_resolution;
	std::string m_tech;
public:
	GPU& SetMaxResolution(/*std::string max_resolution*/) {
		//this->m_max_resolution = max_resolution;
		std::cout << "Max Resolution: ";
		std::cin>>m_max_resolution;
		//m_max_resolution[strlen(m_max_resolution) + 1] = '\0';
		return *this;
	}
	GPU& SetTechnologies(std::string r_tech) {
		//m_tech = r_tech;
		std::cout << "Support Technologies (OpenGL, DirectX): ";
		std::cin >> m_tech;
		return *this;
	}
	std::string GetTechnologies(void) {
		return m_tech;
	}
	std::string GetMaxResolution(void) {
		return m_max_resolution;
	}

	GPU& AddProduct(void) {
		SetMaxResolution().SetWeight().SetHeight().SetTDP().SetNM().SetFreq().SetPrice().SetReleaseDate();
		return *this;
	}
};

class APU : public CPU, public GPU {
public:
	GPU& AddProduct(void) {
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
	int m_roleType;

	User& AddMod(User& x) {
		x.m_roleType = 1;
		return *this;
	}
};

void signup(User& x) {
	static int id = 1;
	std::cout << "username: ";
	std::cin >> x.m_username;
	std::cout << "password: ";
	std::cin >> x.m_password;
	x.m_roleType = 0;

	std::fstream record;
	record.open("records.txt", std::fstream::app | std::fstream::out);
	record << id << ' ';
	record << x.m_username << ' ';
	record << x.m_password << ' ';
	record << x.m_roleType;
	record << '\n';
	record.close();
	std::cout << "Success!\n";
	id++;
	
	
}

void login(User& x) {
	int attempt = 1;
	std::string username, password, usern, pass;
	int lgid, roletype;
start_login:
	system("cls");//curata ecranul;
	std::cout << "username: ";
	std::cin >> username;
	std::cout << "password: ";
	std::cin >> password;
	std::fstream loginfin;
	loginfin.open("records.txt", /*std::fstream::app |*/ std::fstream::in);
	while (loginfin >> lgid >> usern >> pass >> roletype)
	{
		
		if (username == usern && password == pass) {
			std::cout << "Login Successful";
			loginfin.close();
			x.m_id = lgid;
			x.m_password = password;
			x.m_username = username;
			x.m_roleType = roletype;
			break;
		}
		attempt++;
		if (attempt <= 5) {
			std::cout << "Wrong username or password. Try again!!";
			Sleep(500);
			goto start_login;
		}
		else {
			std::cout << "5 failed login. Your are NUB";
			std::exit(11);
		}
	}
	loginfin.close();
}//nu merge pe alt utilizator, decat la primul

void MainMenu() {
	User x;
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
	case 1: {system("cls"); signup(x); goto start; }
	case 2: {system("cls"); login(x); goto start; }
	case 3: {std::cout << "ERROR 404 Not Found!! - Working in progress!!"; break; }
	case 4: {system("cls"); std::exit(-1); }
	}
}


int main() {
	User admin;
	admin.m_id = 0;
	admin.m_password = "admin";
	admin.m_roleType = 1;
	admin.m_username = "admin";

	//APU y;
	//y.IntroduceAllData();
	//std::cout<<y.GPU::GetWeight();//????y.GetWeigt?????

	MainMenu();
	return 0;
}