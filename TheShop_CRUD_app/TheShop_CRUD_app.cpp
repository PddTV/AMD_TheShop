#include <iostream>
#include <string.h>
#include <fstream>

std::fstream lgin("login.txt");
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
		return* this;
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

enum  tech{OpenGL = 1, DirectX = 2};

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
	char m_username[25] = { 0 };
	char m_password[10] = { 0 };
	int m_roleType = 0;



};

void signup(User& x) {
	lgin << id++ << ' ';
	std::cout << "username: ";
	std::cin.get(x.m_username, 25); std::cin.ignore();
	lgin << x.m_username << " ";
	std::cout << "password: ";
	std::cin.get(x.m_password, 10); std::cin.ignore();
	lgin << x.m_password;
	lgin << std::endl;
	std::cout << "Success!\n";
}

void login(void) {
	char username[25], password[10];
	std::cout << "//Login//\n";
	std::cout << "username: "; std::cin.get(password, 10); std::cin.ignore();
	char usrnm[1000][25], pswrd[1000][10];
	int id[1000];
	int i=0;
	while (lgin >> id[i] >> usrnm[i] >> pswrd[i])
	{
		if (!strcmp(username, usrnm[i])) {
			std::cout << "password: "; std::cin.get(password, 10); std::cin.ignore();
			while(strcmp(password,pswrd[i])

		}
		i++;
	}

	std::cin>>
}





int main() {
	
	User x,y;
	signup(x);
	signup(y);
	return 0;
}