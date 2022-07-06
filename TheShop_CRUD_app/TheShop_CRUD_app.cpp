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

public:
	Product& SetWeight(float weight){
		this->m_weight = weight;
		return *this;
	}

	Product& SetHeight(float height) {
		this->m_height = height;
		return *this;
	}

	Product& SetTDP(float TDP) {
		this->m_TDP = TDP;
		return *this;
	}

	Product& SetNM(int nm) {
		this->m_nm = nm;
		return *this;
	}

	Product& SetMemory(int memory) {
		this->m_memory = memory;
		return *this;
	}

	Product& SetFreq(float freq) {
		this->m_clock_freq = freq;
		return *this;
	}

	Product& SetPrice(float price) {
		this->m_price = price;
		return *this;
	}

	Product& SetReleaseDate(std::string release_date) {
		this->m_release_date = release_date;
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
};

class GPU :public Product {
protected:
	std::string m_max_resolution;
	enum tech;


};

class APU :public Product, public CPU, public GPU {
	
};


int main() {
	return 0;
}