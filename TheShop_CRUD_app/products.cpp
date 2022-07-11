#include <iostream>
#include <string>
#include <Windows.h>
#include "products.h"


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
		std::cout << '\n' << i << ". " << name << ": ";
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
void AddProduct(char product_name[], std::string username) {
	std::string type;
	char name[100], weight[10], height[10], tdp[10], freq[10], price[10], nm[10], memory[10], core[10], threads[10], releasedate[25], tech[25], socket[10], max_resolution[15];
	std::fstream readproduct;
	readproduct.open("products.txt", std::fstream::in);
	while (readproduct >> type) {
		readproduct.ignore();
		readproduct.getline(name, 100, ';');
		std::cout << ">>" << name << "<< " << strcmp(name, product_name) << ">>";
		std::cout << product_name << "<<\n";
		if ((strcmp(name, product_name)) == 0)
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
void DeleteProduct(char product_name[], std::string filename) {
	std::fstream readproduct;
	readproduct.open(filename, std::fstream::in);
	std::string type;
	char name[100];
	bool valid = 0;
	char str[5000];
	while (readproduct >> type) {
		readproduct.getline(name, 100, ';');
		//std::cout << name << "<<\n";
		strcpy_s(name, name + 1);
		std::cout << ">>" << product_name << "<< ";
		std::cout << strcmp(product_name, name) << " >>";
		std::cout << name << "<<\n";
		system("pause");
		if (strcmp(product_name, name))
		{
			std::fstream writeproduct;
			writeproduct.open("temp.txt", std::fstream::app | std::fstream::out);
			writeproduct << type << ' ' << name << "; ";
			readproduct.getline(str, 5000, '\n');
			writeproduct << str << '\n';
			writeproduct.close();
		}
		else {
			valid = 1;
			readproduct.ignore(5000, '\n');
		}

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