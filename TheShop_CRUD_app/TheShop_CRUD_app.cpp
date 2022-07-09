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
class CPU :public virtual Product {
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
class GPU :public virtual Product {
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
	bool m_roleType;

	User& AddMod(User& x) {
		x.m_roleType = 1;
		return *this;
	}
};

bool verify_singup(std::string x);
void signup(User& x);
bool login(User& x);
void MainMenu(void);
void SecondaryMenu(bool type);

int main() {
	User admin;
	admin.m_id = 0;
	admin.m_password = "admin";
	admin.m_roleType = 1;
	admin.m_username = "admin";

	/*APU y;
	y.AddProduct();
	std::cout<<y.GetWeight();*/
	MainMenu();
	return 0;
}

void signup(User& x) {
start:
	static int id = 1;
	std::fstream nextId;
	nextId.open("nextid_register.txt", std::fstream::in);
	if (!(nextId >> id));
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
	record.open("records.txt", std::fstream::app | std::fstream::out);
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
	loginfin.open("records.txt", std::fstream::in);


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
	verify.open("records.txt", std::fstream::in);
	while (verify >> lgid >> usern >> pass >> roletype)
		if (x == usern) {
			verify.close();
			return 0;
		}
	verify.close();
	return 1;
}
void MainMenu(void) {
	User x;
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
		case 1: { /*AddProduct in database (products.txt, delimitat de ;)*/ system("cls"); goto start; }
		case 2: { system("cls"); /*Lista products.txt*/; goto start; }
		case 3: {/*DeleteProduct per linie (un alt fisier cu datele fara cel selectat, temp.txt, apoi stergere cel vechi si redenumire temp.txt in products.txt*/ system("cls"); goto start; }
		case 4: {/*change type, procedura asemanatoare ca la delete*/  system("cls"); goto start; }
		case 5: {system("cls"); MainMenu(); break; }
		default: { std::cout << "No valid option!!\n"; Sleep(700); system("cls"); goto start; }
		}
	}
	else {
		std::cout << "\n1. Add a product to cart\n";
		std::cout << "2. Show the cart\n";
		std::cout << "3. Delete a product from cart\n";
		std::cout << "4. Return to Main Menu\n";
		std::cout << "Your choice: ";
		std::cin >> option;
		switch (option) {
		case 1: { /*AddProduct in cart (cart_username.txt, delimitat de ;)*/ system("cls"); goto start; }
		case 2: { system("cls"); goto start; }
		case 3: { /*DeleteProduct per linie (un alt fisier cu datele fara cel selectat, temp.txt, apoi stergere cel vechi si redenumire temp.txt in cart_username.txt*/ system("cls"); goto start; }
		case 4: {system("cls"); MainMenu(); break; }
		default: { std::cout << "No valid option!!\n"; Sleep(700); system("cls"); goto start; }
		}
	}
}