#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "users.h"

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
	Product& SetWeight() {
		std::cout << "Weight: ";
		std::cin >> m_weight;
		return *this;
	}
	Product& SetHeight() {
		std::cout << "Height: ";
		std::cin >> m_height;
		return *this;
	}
	Product& SetTDP() {
		std::cout << "TDP: ";
		std::cin >> m_TDP;
		return *this;
	}
	Product& SetNM() {
		std::cout << "nm: ";
		std::cin >> m_nm;
		return *this;
	}
	Product& SetMemory() {
		std::cout << "Memory: ";
		std::cin >> m_memory;
		return *this;
	}
	Product& SetFreq() {
		std::cout << "Clock Frequency: ";
		std::cin >> m_clock_freq;
		return *this;
	}
	Product& SetPrice() {
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
};
class CPU :public virtual Product {
protected:
	int m_core = 0;
	int m_threads = 0;
	std::string m_socket;

public:
	CPU& SetCore() {
		std::cout << "Core: ";
		std::cin >> m_core;
		return *this;
	}
	CPU& SetThreads() {
		std::cout << "Treads: ";
		std::cin >> m_threads;
		return*this;
	}
	CPU& SetSocket() {
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
	GPU& SetMaxResolution() {
		std::cout << "Max Resolution: ";
		std::cin >> m_max_resolution;
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

void ElementeProduct(char weight[], char height[], char TDP[], char nm[], char memory[], char freq[], char price[], char releasedate[]);
void ElementeCPU(char core[], char threads[], char socket[]);
void ElementeGPU(char max_resolurion[], char tech[]);

void ListProduct(std::string filename);
void DeleteProduct(char product_name[], std::string filename);
void AddProduct(char product_name[], std::string username);

void Filter(std::string criteria, char compare_option, std::string value);