#include <iostream>
#include <string.h>
#include <fstream>
#include <Windows.h>

//===========================
// Product Section
//===========================

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

//===========================
// User Section
//===========================

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
void SecondaryMenu(bool type);
void MainMenu(void);
void MeniuTipProdus(void);
void ElementeProduct(float weight, float height, float TDP, int nm, int memory, float freq, float price, char releasedate[]);
void ElementeCPU(int core, int threads, std::string socket);
void ElementeGPU(std::string max_resolurion, char tech[]);
void ListProduct(std::string filename);
void DeleteProduct(std::string product_name, std::string filename);
//void Filter(int option, User& criteria);
//void FilterP(int compare_option, User& criteria);
void AddProduct(std::string product_name, std::string username);

int main() {
	MainMenu();
	return 0;
}
User x;
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
void MainMenu(void) {
	
	int option;
	std::cout << "AMD Shop Menu:\n";
start:
	std::cout << "\n\nSelect Option:\n\n";
	std::cout << "1. SignUp\n";
	std::cout << "2. SignIn and Enter to your menu\n";
	std::cout << "3. Exit\n\n";
	std::cout << "Your choice: ";
	std::cin >> option;
	switch (option) {
	case 1: {system("cls"); signup(x); goto start; }
	case 2: {system("cls"); SecondaryMenu(login(x)); goto start; }
	case 3: {system("cls"); std::exit(-99); }
	default: { std::cout << "No valid option!!\n"; Sleep(700); system("cls"); goto start; }
	}
}
void SecondaryMenu(bool type) {
start:
	int option;
	if (type)
	{
		std::cout << "\n1. Add a product in database\n";
		std::cout << "2. List of products from database\n";
		std::cout << "3. Delete a product from database\n";
		std::cout << "4. Add admin\n";
		std::cout << "5. Return to Main Menu\n\n";
		std::cout << "Your choice: ";
		std::cin >> option;
		switch (option) {
		case 1: { system("cls"); MeniuTipProdus(); goto start; }
		case 2: { system("cls"); ListProduct("products.txt"); goto start; }
		case 3: { 
			std::string product_name;
			std::cin.ignore();
			std::cout << "Product name: ";
			std::cin >> product_name;
			DeleteProduct(product_name, "products.txt"); 
			//system("cls"); 
			goto start; 
		}
		case 4: {
			std::string username;
			std::cout << "\n username: ";
			std::cin >> username;
			x.AddMod(username); system("cls"); goto start;
		}
		case 5: {system("cls"); MainMenu(); break; }
		default: { std::cout << "No valid option!!\n"; Sleep(700); system("cls"); goto start; }
		}
	}
	else {
		std::cout << "\n1. List of Products\n";
		std::cout << "2. Add a product to cart\n";
		std::cout << "3. Show the cart\n";
		std::cout << "4. Delete a product from cart\n";
		std::cout << "5. Return to Main Menu\n";
		std::cout << "Your choice: ";
		std::cin >> option;
		std::cin.ignore();
		switch (option) {
		case 1: { system("cls"); ListProduct("products.txt"); goto start; }
		case 2: { 
			//char nameproduct[100];
			std::string nameproduct;
			//std::cin.ignore();
			std::cout << "\nName of product: ";
			std::cin >> nameproduct;
			//std::cin.getline(nameproduct,100,'\n');
			//std::cout << nameproduct << std::endl;
			AddProduct(nameproduct, x.m_username);
			//system("cls"); 
			goto start; 
		}
		case 3: { system("cls"); goto start; }
		case 4: { std::string product_name;
			std::cout << "Product name: ";
			std::cin >> product_name;
			std::string filename = x.m_username + "_cart.txt";
			DeleteProduct(product_name, filename);  system("cls"); goto start;
		}
		case 5: {system("cls"); MainMenu(); break; }
		default: { std::cout << "No valid option!!\n"; Sleep(700); system("cls"); goto start; }
		}
	}
}
void MeniuTipProdus(void) {
	int option;
	std::cout << "Choose type of product:";
	std::cout << "\n1. CPU\n";
	std::cout << "2. GPU\n";
	std::cout << "3. APU\n";
	std::cout << "Your choice: ";
	std::cin >> option;
	switch (option) {
	case 1: {CPU y; y.AddProduct().RegisterProduct("products.txt"); system("cls"); SecondaryMenu(1); break; }
	case 2: {GPU y; y.AddProduct().RegisterProduct("products.txt"); system("cls"); SecondaryMenu(1); break; }
	case 3: {APU y; y.AddProduct().RegisterProduct("products.txt"); system("cls"); SecondaryMenu(1); break; }
	}
}

void ElementeProduct(char weight[], char height[], char TDP[], char nm[], char memory[], char freq[], char price[], char releasedate[]) {
	std::cout << "\n\t\t-> Weight: " << weight << "mm; ";
	std::cout << "\n\t\t-> Height: " << height << "mm; ";
	std::cout << "\n\t\t-> TDP: " << TDP << ';';
	std::cout << "\n\t\t-> nm: " << nm << ';';
	std::cout << "\n\t\t-> Memory: " << memory << "GB;";
	std::cout << "\n\t\t-> Clock Frequency: " << freq << "GHz; ";
	std::cout << "\n\t\t-> Price: " << price << "Eur; ";
	std::cout << "\n\t\t-> Release Date: " << releasedate << ';';
}
void ElementeCPU(char core[], char threads[], char socket[]) {
	std::cout << "\n\t\t-> Core: " << core << ';';
	std::cout << "\n\t\t-> Threads: " << threads << ';';
	std::cout << "\n\t\t-> Socket: " << socket << ';';
}
void ElementeGPU(char max_resolurion[], char tech[]) {
	std::cout << "\n\t\t-> Max Resolution: " << max_resolurion << ';';
	std::cout << "\n\t\t-> Support Technologies: " << tech << ';';
}
void ListProduct(std::string filename) {
	std::string	type;
	char name[100], weight[10], height[10], tdp[10], freq[10], price[10], nm[10], memory[10], core[10], threads[10], releasedate[25], tech[25], socket[10], max_resolution[15];
	std::fstream read_from_file;
	read_from_file.open(filename, std::fstream::in);
	int i = 0;
	while (read_from_file >> type) {
		i++;
		read_from_file.getline(name, 100, ';');
		std::cout <<'\n'<< i << ". " << name << ": ";
		if (type == "CPU") {
			read_from_file.getline(core, 10, ';');
			read_from_file.getline(threads, 10, ';');
			read_from_file.getline(socket, 10, ';');
			ElementeCPU(core, threads, socket); 
			read_from_file.getline(weight, 10, ';');
			read_from_file.getline(height, 10, ';');
			read_from_file.getline(tdp, 10, ';');
			read_from_file.getline(nm, 10, ';');
			read_from_file.getline(memory, 10, ';');
			read_from_file.getline(freq, 10, ';');
			read_from_file.getline(price, 10, ';');
			read_from_file.getline(releasedate, 10, ';');
			ElementeProduct(weight, height, tdp, nm, memory, freq, price, releasedate);
		}
		else if (type == "GPU") {
			read_from_file.getline(max_resolution, 15, ';');
			read_from_file.getline(tech, 25, ';');
			ElementeGPU(max_resolution,tech); 
			read_from_file.getline(weight, 10, ';');
			read_from_file.getline(height, 10, ';');
			read_from_file.getline(tdp, 10, ';');
			read_from_file.getline(nm, 10, ';');
			read_from_file.getline(memory, 10, ';');
			read_from_file.getline(freq, 10, ';');
			read_from_file.getline(price, 10, ';');
			read_from_file.getline(releasedate, 10, ';');
			ElementeProduct(weight, height, tdp, nm, memory, freq, price, releasedate);
		}
		else {
			read_from_file.getline(core, 10, ';');
			read_from_file.getline(threads, 10, ';');
			read_from_file.getline(socket, 10, ';');
			ElementeCPU(core, threads, socket); 
			read_from_file.getline(max_resolution, 15, ';');
			read_from_file.getline(tech, 25, ';');
			ElementeGPU(max_resolution, tech); 
			read_from_file.getline(weight, 10, ';');
			read_from_file.getline(height, 10, ';');
			read_from_file.getline(tdp, 10, ';');
			read_from_file.getline(nm, 10, ';');
			read_from_file.getline(memory, 10, ';');
			read_from_file.getline(freq, 10, ';');
			read_from_file.getline(price, 10, ';');
			read_from_file.getline(releasedate, 10, ';');
			ElementeProduct(weight, height, tdp, nm, memory, freq, price, releasedate);
		}
	}
	read_from_file.close();
}

void AddProduct(/*char*/std::string product_name, std::string username) {
	std::string type;
	char name[100], weight[10], height[10], tdp[10], freq[10], price[10], nm[10], memory[10], core[10], threads[10], releasedate[25], tech[25], socket[10], max_resolution[15];
	std::fstream readproduct;
	readproduct.open("products.txt", std::fstream::in);
	while (readproduct >> type) {
		readproduct.getline(name, 100, ';');
		char prdnm[100]; ;
		strcpy_s(prdnm, product_name.c_str());
		std::cout << name << ' ' << strcmp(name, prdnm) << ' ';
		std::cout << product_name<< '\n';
		//PROBLEMA LA COMPARARE
		if ((strcmp(name, prdnm))==0)
		{
			//----------------------CitireProdus----------------------//
			if (type == "CPU") {
				readproduct.getline(core, 10, ';');
				readproduct.getline(threads, 10, ';');
				readproduct.getline(socket, 10, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
			else if (type == "GPU") {
				readproduct.getline(max_resolution, 15, ';');
				readproduct.getline(tech, 25, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
			else {
				readproduct.getline(core, 10, ';');
				readproduct.getline(threads, 10, ';');
				readproduct.getline(socket, 10, ';');
				readproduct.getline(max_resolution, 15, ';');
				readproduct.getline(tech, 25, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
			//--------------------------------------------------------//
			std::fstream writef;
			std::string filename;
			filename = username + "_cart.txt";
			writef.open(filename, std::fstream::app | std::fstream::out);
			//----------------------ScriereProdus----------------------//
			writef << type << ' ' << name << "; ";
			if (type == "CPU") {
				writef << core << "; " << threads << "; " << socket << "; " << weight << "; " << height << "; " << tdp << "; " << nm << "; " << memory << "; " << freq << "; " << price << "; " << releasedate << "; \n";
			}
			else if (type == "GPU") {
				writef << max_resolution << "; " << tech << "; " << weight << "; " << height << "; " << tdp << "; " << nm << "; " << memory << "; " << freq << "; " << price << "; " << releasedate << "; \n";
			}
			else {
				writef << core << "; " << threads << "; " << socket << "; " << max_resolution << "; " << tech << "; " << weight << "; " << height << "; " << tdp << "; " << nm << "; " << memory << "; " << freq << "; " << price << "; " << releasedate << "; \n";
			}
			//---------------------------------------------------------//
			writef.close();
		}
		else
		{
			if (type == "CPU") {
				readproduct.getline(core, 10, ';');
				readproduct.getline(threads, 10, ';');
				readproduct.getline(socket, 10, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
			else if (type == "GPU") {
				readproduct.getline(max_resolution, 15, ';');
				readproduct.getline(tech, 25, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
			else {
				readproduct.getline(core, 10, ';');
				readproduct.getline(threads, 10, ';');
				readproduct.getline(socket, 10, ';');
				readproduct.getline(max_resolution, 15, ';');
				readproduct.getline(tech, 25, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
		}
	}
	readproduct.close();
}
/*PARTIAL FUNCTIONAL*/

void DeleteProduct(std::string product_name, std::string filename) {
	product_name += ";";
	std::fstream readproduct;
	readproduct.open(filename, std::fstream::in); 
	std::string type, name;
	bool valid=0;
	char str[5000];
	while (readproduct >> type>>name) {
		std::cout << product_name<<" ";
		std::cout << name<<'\n';
		if (name != product_name) {
			std::fstream writeproduct;
			writeproduct.open("temp.txt", std::fstream::app | std::fstream::out);
			writeproduct << type << ' ' << name << ' ';
			readproduct.getline(str, 5000, '\n');
			writeproduct << str << '\n';
			valid = 1;
			writeproduct.close();
		}
		readproduct.ignore(5000i64, '\n');
	}
	readproduct.close();
	if (valid) {
		std::cout << "\nSuccess";
		char filenm[100];
		strcpy_s(filenm, filename.c_str());
		remove(filenm);
		rename("temp.txt", filenm);
		Sleep(700);
	}
	else std::cerr << "\nNu s-a gasit produs";
	std::cin.ignore();

}
/*PARTIAL FUNCTIONAL*/
