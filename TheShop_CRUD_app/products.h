#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

class Product {
protected:
	char m_name[100];
	float m_weight;
	float m_height;
	float m_TDP;
	int m_nm;
	int m_memory;
	float m_clock_freq;
	float m_price;
	char m_release_date[25];

public:
	Product& SetName() {
		std::cin.ignore();
		std::cout << "Name: ";
		std::cin.getline(m_name, 100);
		return *this;
	}
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
	Product& SetReleaseDate() {
		std::cin.ignore();
		std::cout << "Release date: ";
		std::cin.getline(m_release_date, 25);
		return *this;
	}
	std::string GetName(void) {
		return m_name;
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
	int GetNM(void) {
		return m_nm;
	}
	int GetMemory(void) {
		return m_memory;
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
	void AddProduct(std::string product_name, std::string username) {
		//nothing;
	}
};
class CPU :public virtual Product {
protected:
	int m_core = 0;
	int m_threads = 0;
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
		std::cin >> m_socket;
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
		SetName();
		SetCore().SetThreads().SetSocket().SetWeight().SetHeight().SetTDP().SetNM().SetMemory().SetFreq().SetPrice().SetReleaseDate();
		std::cout << "Succes!!\n";
		Sleep(700);
		return *this;
	}
	void RegisterProduct(std::string filename) {
		std::fstream recordP;
		recordP.open(filename, std::fstream::app | std::fstream::out);
		recordP << "CPU ";
		recordP << GetName() << "; ";
		recordP << GetCore() << "; ";
		recordP << GetThreads() << "; ";
		recordP << GetSocket() << "; ";
		recordP << GetWeight() << "; ";
		recordP << GetHeight() << "; ";
		recordP << GetTDP() << "; ";
		recordP << GetNM() << "; ";
		recordP << GetMemory() << "; ";
		recordP << GetFreq() << "; ";
		recordP << GetPrice() << "; ";
		recordP << GetReleaseDate() << ";\n";
		recordP.close();
	}
};
class GPU :public virtual Product {
protected:
	std::string m_max_resolution;
	char m_tech[25];
public:
	GPU& SetMaxResolution(/*std::string max_resolution*/) {
		//this->m_max_resolution = max_resolution;
		std::cout << "Max Resolution: ";
		std::cin >> m_max_resolution;
		//m_max_resolution[strlen(m_max_resolution) + 1] = '\0';
		return *this;
	}
	GPU& SetTechnologies() {
		std::cin.ignore();
		std::cout << "Support Technologies (OpenGL, DirectX): ";
		std::cin.getline(m_tech, 25);
		return *this;
	}
	std::string GetTechnologies(void) {
		return m_tech;
	}
	std::string GetMaxResolution(void) {
		return m_max_resolution;
	}
	GPU& AddProduct(void) {
		SetName();
		SetMaxResolution().SetTechnologies().SetWeight().SetHeight().SetTDP().SetNM().SetMemory().SetFreq().SetPrice().SetReleaseDate();
		std::cout << "Succes!!\n";
		Sleep(700);
		return *this;
	}
	void RegisterProduct(std::string filename) {
		std::fstream recordP;
		recordP.open(filename, std::fstream::app | std::fstream::out);
		recordP << "GPU ";
		recordP << GetName() << "; ";
		recordP << GetMaxResolution() << "; ";
		recordP << GetTechnologies() << "; ";
		recordP << GetWeight() << "; ";
		recordP << GetHeight() << "; ";
		recordP << GetTDP() << "; ";
		recordP << GetNM() << "; ";
		recordP << GetMemory() << "; ";
		recordP << GetFreq() << "; ";
		recordP << GetPrice() << "; ";
		recordP << GetReleaseDate() << ";\n";
		recordP.close();
	}
};
class APU : public CPU, public GPU {
public:
	APU& AddProduct(void) {
		SetName();
		SetCore().SetThreads().SetSocket();
		SetMaxResolution().SetTechnologies().SetWeight().SetHeight().SetTDP().SetNM().SetMemory().SetFreq().SetPrice().SetReleaseDate();
		std::cout << "Succes!!\n";
		Sleep(700);
		return *this;
	}
	void RegisterProduct(std::string filename) {
		std::fstream recordP;
		recordP.open(filename, std::fstream::app | std::fstream::out);
		recordP << "APU ";
		recordP << GetName() << "; ";
		recordP << GetCore() << "; ";
		recordP << GetThreads() << "; ";
		recordP << GetSocket() << "; ";
		recordP << GetMaxResolution() << "; ";
		recordP << GetTechnologies() << "; ";
		recordP << GetWeight() << "; ";
		recordP << GetHeight() << "; ";
		recordP << GetTDP() << "; ";
		recordP << GetNM() << "; ";
		recordP << GetMemory() << "; ";
		recordP << GetFreq() << "; ";
		recordP << GetPrice() << "; ";
		recordP << GetReleaseDate() << ";\n";
		recordP.close();
	}
};

void ElementeProduct(float weight, float height, float TDP, int nm, int memory, float freq, float price, char releasedate[]);
void ElementeCPU(int core, int threads, std::string socket);
void ElementeGPU(std::string max_resolurion, char tech[]);

void ListProduct(std::string filename);
void DeleteProduct(char product_name[], std::string filename);
void AddProduct(char product_name[], std::string username);
//void Filter(int option, User& criteria);
//void FilterP(int compare_option, User& criteria);