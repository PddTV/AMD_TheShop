#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "menu.h"
#include "users.h"
#include "products.h"

User x;

void MainMenu(void) {

	int option;
	std::cout << "AMD Shop Menu:\n";
start:
	std::cout << "\n\nSelect Option:\n\n";
	std::cout << "1. SignUp\n";
	std::cout << "2. SignIn and Enter to your menu\n";
	std::cout << "3. Exit\n\n";
	std::cout << "Your choice: "; fflush(stdin);
	std::cin >> option;
	switch (option) {
	case 1: {system("cls"); signup(x); goto start; }
	case 2: {system("cls"); SecondaryMenu(login(x)); goto start; }
	case 3: {system("cls"); std::exit(-99); }
	default: { std::cout << "No valid option!!\n"; fflush(stdin); Sleep(700); system("cls"); goto start; }
	}

}
void SecondaryMenu(bool type) {
	while (~0) {
		if (type)
		{
			int option;
			std::cout << "\n1. Add a product in database\n";
			std::cout << "2. List of products from database\n";
			std::cout << "3. Delete a product from database\n";
			std::cout << "4. Add admin\n";
			std::cout << "5. Return to Main Menu\n\n";
			std::cout << "Your choice: ";
			std::cin >> option;
			switch (option) {
			case 1: { system("cls"); MeniuTipProdus(); break; }
			case 2: { system("cls"); ListProduct("products.txt"); break; }
			case 3: {
				char product_name[100];
				std::cout << "Product name: "; std::cin.ignore();
				std::cin.getline(product_name, 100, '\n');
				DeleteProduct(product_name, "products.txt");
				//system("cls"); 
				break;
			}
			case 4: {
				fflush(stdin);
				std::string username;
				std::cout << "\n username: ";
				std::cin >> username;
				x.AddMod(username); system("cls"); break;
			}
			case 5: {system("cls"); MainMenu(); break; }
			default: { std::cout << "No valid option!!\n"; Sleep(700); system("cls"); break; }
			}
		}
		else {
			int option;
			std::cout << "\n1. List of Products\n";
			std::cout << "2. Add a product to cart\n";
			std::cout << "3. Show the cart\n";
			std::cout << "4. Delete a product from cart\n";
			std::cout << "5. Return to Main Menu\n";
			std::cout << "Your choice: ";
			std::cin >> option;


			switch (option) {
			case 1: { system("cls"); ListProduct("products.txt"); break; }
			case 2: {
				char nameproduct[100];
				std::cin.ignore();
				std::cout << "\nName of product: "; fflush(stdin);
				std::cin.getline(nameproduct, 100, '\n');
				AddProduct(nameproduct, x.m_username);
				system("cls"); 
				break;
			}
			case 3: { system("cls");
				std::string filename = x.m_username + "_cart.txt";
				ListProduct(filename); break;
			}
			case 4: { char product_name[100];
				std::cout << "Product name: "; std::cin.ignore();
				std::cin.getline(product_name, 100);
				std::string filename = x.m_username + "_cart.txt";
				DeleteProduct(product_name, filename);  system("cls"); break;
			}
			case 5: {system("cls"); MainMenu(); break; }
			default: { std::cout << "No valid option!!\n"; Sleep(700); system("cls"); fflush(stdin); std::cin.ignore(); break; }
			}
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
