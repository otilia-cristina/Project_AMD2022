#pragma once
#pragma once
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;



class Users {
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
class Administrator :public Users {

public:
	void initializare(const string& m_id, const string& m_username, const string& m_password, const string& m_role);
};
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
	vector<Administrator> admin;
	vector<Client> client;
	void initializare(const string& file);
	void print_users();
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

