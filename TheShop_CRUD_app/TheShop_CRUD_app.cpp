#include <iostream>

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
};

class CPU :public Product {
protected:
	int m_core;
	int m_threads;
	std::string m_socket;
};

class GPU :public Product {
protected:
	std::string m_max_resolution;
	std::string m_vers_tech;
};

class APU :public Product, public CPU, public GPU {
	
};