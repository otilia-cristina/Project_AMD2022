#pragma once
#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include "Products.h"
#include "Products.h"




using namespace std;

class Users 
{
public:
	string m_id;
	string m_username;
	string m_password;
	string m_role;
	void initializare(const string& m_id, const string& m_username, const string& m_password, const string& m_role);
};
void Users::initializare(const string& m_id, const string& m_username, const string& m_password, const string& m_role) {
	this->m_id = m_id;
	this->m_username = m_username;
	this->m_password = m_password;
	this->m_role = m_role;
}
class Administrator :public Users
{

public:
	vector<Administrator> admin;
	void initializare(const string& m_id, const string& m_username, const string& m_password, const string& m_role);
	
	void deleteProduse();
	void addProduse();
};

//incercare
void Administrator::deleteProduse() 
{
	fstream f1, f2;
	int counter = 0;
	cout << "\n\t\t Delete product";
	cout<<"\n\t\t\t Enter the product name you want delete \n"; 
	string  p_name, p_category, p_price, p_data;
	cin >> p_name;

	f1.open("Products.txt", ios::in);
	if (!f1)
	{
		cout << "File doesnt exist " << endl;
	}
	else 
	{   
		f2.open("ProduseleSterse.txt", ios::app | ios::out);
		string category, name, price, data, line;
		f1 >> category;
		f1 >> name;
		f1 >> price;
		f1 >> data;
		while (!f1.eof())
		{

			if ((name==p_name)&&(category==p_category)&&(price==p_price)&&(data==p_data))
			{   
				cout << "Product deleted succesfully";
				counter++;

			}
			else
			{
				f2 << category <<" " << name <<" " << price <<" " << data;
			}
			f1 >> category >> name >> price >> data;
			cout << endl;
		}
        f1.close();
		f2.close();
		remove("Products.txt");
		rename("ProduseleSterse.txt", "Products.txt");
		if(counter == 0)
		{
			cout << "The product in this category and with this name does not exist" << endl;
		}
	}

 }

void Administrator:: addProduse() 
{
	    string c, n, d,m;
		int p;
		string p_category, p_name, p_data;
		int p_price;
		cout << " Enter the product category you want add \n";
		cin >> p_category;
		cout << " Enter the product name you want add \n";
		cin >> p_name;
		cout << "Enter the product price you want add \n";
		cin >> p_price;
		cout << "Enter the product data you want add \n";
		cin >> p_data;
		int counter = 0;

		fstream f;
		f.open("Products.txt", ios::in);
		if(!f)
		{

			f.open("Products.txt", ios::app|ios::out);
			f << " " << p_category << " " << p_name << " " << p_price << " " << p_data << "\n";
			f.close();

	     }
		else
		{
			f >> c >> n >> p >> d;
			while (!f.eof())
			{
				if (c == p_category)
				{
					counter++;
			    }
				f >> c >> n >> p >> d;
			}
			f.close();
		}

		if (!counter == 1) 
		{
			f.open("Products.txt", ios::app | ios::out);
			f << " " << p_category << " " << p_name << " " << p_price << " " << p_data << "\n";
			f.close();

		}

}
void Administrator::initializare(const string& m_id, const string& m_username, const string& m_password, const string& m_role)
{
	this->m_id = m_id;
	this->m_username = m_username;
	this->m_password = m_password;
	this->m_role = m_role;
}
class Client :public Users {

public:
	void initializare(const string& m_id, const string& m_username, const string& m_password, const string& m_role);
};
void Client::initializare(const string& m_id, const string& m_username, const string& m_password, const string& m_role)
{
	this->m_id = m_id;
	this->m_username = m_username;
	this->m_password = m_password;
	this->m_role = m_role;
}
class Login :public Users {
public:
	vector<Users> users;
	void initializare(const string& file);
	bool logareAdm();
	bool logareClient();
};

void Login::initializare(const string& file)
{

	fstream in_file;
	in_file.open("Users.txt", ios::in);

	while (!in_file.eof())
	{
		/*
		size_t delimiter = line.find(' ');
		string  id = line.substr(0, delimiter);
		string username = line.substr(id.size(), delimiter);
		string passw0rd = line.substr(username.size(), delimiter);
		string  role = line.substr(delimiter + 1);

		*/
		string id, username, passw0rd, role, next;

		in_file >> id;
		in_file >> username;
		in_file >> passw0rd;
		in_file >> role;

		Users   new_user;
		new_user.initializare(id, username, passw0rd, role);
		users.push_back(new_user);
		getline(in_file, next);//trece la linia urmatoare
	}
	in_file.close();
}
bool Login::logareAdm()
{
	cout << "Enter your ID ::\t";
	cin >> m_id;
	cout << "Enter your User Name ::\t";
	cin >> m_username;
	cout << "Enter Password ::\t";
	cin >> m_password;

	for (Users a : users)
	{
		if (a.m_role == "1")
		{
			int ok = 0;
			if ((m_id == a.m_id) && (m_username == a.m_username) && (m_password == a.m_password))
			{
				ok++;
				break;

			}
			if (ok == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Login::logareClient()
{

	cout << "Enter your ID ::\t";
	cin >> m_id;
	cout << "Enter your User Name ::\t";
	cin >> m_username;
	cout << "Enter Password ::\t";
	cin >> m_password;


	for (Users c : users)
	{
		if (c.m_role == "2")
		{
			int ok = 0;
			if ((m_id == c.m_id) && (m_username == c.m_username) && (m_password == c.m_password))
			{
				ok++;
				break;
			}
			if (ok == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}

}



