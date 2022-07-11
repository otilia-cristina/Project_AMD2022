#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"Login.h"

using namespace std;


class Products {
public:
	string m_category;
	string m_name;
	float m_weight;
	float m_height;
	int m_TDP;
	int m_memory;
	double m_frequency;
	int m_nms;
public:
	Products(float weight, float height, int TDP, int memory, double frequency, int nms) {

		m_weight = weight;
		m_height = height;
		m_TDP = TDP;
		m_memory = memory;
		m_frequency = frequency;
		m_nms = nms;
	}
	void print() {
		cout << m_weight << "  " << m_height << "  " << m_TDP << "  " << m_memory << "  " << m_frequency << m_nms << endl;
	}
};


class CPUs :public Products {
public:
	string m_soket;
	int m_numberCores;
	double m_numberThreads;
public:
	CPUs();

	CPUs(float weight, float height, int TDP, int memory, double frequency, int nms, string soket, int numberCores, double numberThreads) :Products(weight, height, TDP, memory, frequency, nms)
	{
		m_soket = soket;
		m_numberCores = numberCores;
		m_numberThreads = numberThreads;
	}
	void print() {
		Products::print();
		cout << m_soket << "  " << m_numberCores << "  " << m_numberThreads << endl;
	}

};



class GPUs :public Products {
public:
	string m_maxResolution;
	enum  Version_of_technologies { OpenGL, DirectX };


public:
	GPUs();
	GPUs(float weight, float height, int TDP, int memory, double frequency, int nms, string maxResolution, Version_of_technologies version) :Products(weight, height, TDP, memory, frequency, nms)
	{
		m_maxResolution = maxResolution;

	}
	void print() {

		cout << m_maxResolution << endl;
	}
	/*
	void printVersion(Version_of_technologies version, std::ostream& os)
	{
		switch (version)
		{
		case OpenGL:
			os << "OpenGL";
			break;
		case  DirectX:
			os << " DirectX";
			break;
		default:
			break;

		}
	}

	*/


};



string getVersion(GPUs::Version_of_technologies version) {
	string versionName[] = { "OpenGL","DirectX" };
	return versionName[version];
}


class APUs : public CPUs, public GPUs
{
public:
	string m_category, m_name;
public:
	APUs();
	APUs(float weight, float height, int TDP, int memory, double frequency, int nms, string soket, int numberCores, double numberThreads, string maxResolution, Version_of_technologies version) :
		CPUs(weight, height, TDP, memory, frequency, nms, soket, numberCores, numberThreads), GPUs(weight, height, TDP, memory, frequency, nms, maxResolution, version) {

	}
	void print() {
		CPUs::print();
		GPUs::print();
	}

};


class Menu
{
public:
	string m_category, m_name, m_data;
	int m_price;
	vector<Menu>menuAll;
	vector<Menu> menuCPUs;
	vector<Menu> menuGPUs;
	vector<Menu> menuAPUs;
	void categorii(const string& filee);
	void initializ(string m_category, string name);
	void print_menu();
	void filtrareprod(const string& filee);
	void filtrare(string m_category, string m_name, int m_price, string m_data);
	void print_filtrarePret();
};
void Menu::initializ(string m_category, string m_name)
{
	this->m_category = m_category;
	this->m_name = m_name;

}
void Menu::filtrare(string m_category, string m_name, int m_price, string m_data)
{
	this->m_category = m_category;
	this->m_name = m_name;
	this->m_price = m_price;
	this->m_data = m_data;
}


void Menu::categorii(const string& filee)
{

	fstream fs;
	fs.open("Products.txt", ios::in);

	while (!fs.eof())
	{
		string category, name, data, next;
		int price;
		fs >> category;
		fs >> name;
		fs >> price;
		fs >> data;

		if (category == "CPUs")
		{
			Menu new_cpu;
			new_cpu.initializ(category, name);
			menuCPUs.push_back(new_cpu);
		}

		if (category == "GPUs")
		{
			Menu new_gpu;
			new_gpu.initializ(category, name);
			menuGPUs.push_back(new_gpu);
		}

		if (category == "APUs")
		{
			Menu new_apu;
			new_apu.initializ(category, name);
			menuAPUs.push_back(new_apu);
		}
		Menu new_all;
		new_all.initializ(category, name);
		menuAll.push_back(new_all);

		getline(fs, next);//trece la linia urmatoare


	}

	fs.close();
}
void Menu::print_menu()
{
	cout << "Products from the category CPUs " << endl;
	for (Menu c : menuCPUs)
	{
		cout << c.m_category << " " << c.m_name << endl;
	}
	cout << endl;
	cout << "Products from the category GPUs " << endl;
	for (Menu g : menuGPUs)
	{
		cout << g.m_category << " " << g.m_name << endl;
	}
	cout << endl;
	cout << "Products from the category APUs " << endl;
	for (Menu a : menuAPUs)
	{
		cout << a.m_category << " " << a.m_name << endl;
	}


}
void Menu::filtrareprod(const string& filee)
{
	fstream fs;
	fs.open("Products.txt", ios::in);

	while (!fs.eof())
	{
		string category, name, data, next;
		int price;

		fs >> category;
		fs >> name;
		fs >> price;
		fs >> data;


		Menu new_all;
		new_all.filtrare(category, name, price, data);
		menuAll.push_back(new_all);

		getline(fs, next);//trece la linia urmatoare


	}
}
void Menu::print_filtrarePret()
{
	cout << "Select filter\n";
	string filtrareprd;
	cin >> filtrareprd;
	cout << "\n";
	cout << "Enter the price ::\t";
	cin >> m_price;

	if (filtrareprd == "Price")
	{
		for (Menu m : menuAll)
		{
			int count = 0;
			if (m.m_price <= m_price)
			{
				count++;

			}
			if (count > 0)
			{
				cout << m.m_category << " " << m.m_name << " " << m.m_price << endl;
			}

		}


	}


}

