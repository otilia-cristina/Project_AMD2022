#include<iostream>
#include<fstream>
#include <string>
//#include"Products.h"
#include"Login.h"


int main()
{
	cout << "*********************** Welcome to the AMD product store ************************" << endl;

	cout << "\n";
	cout << "\t\t\t\t|   1 Administrator   |\n";
	cout << "\t\t\t\t|   2 Client          |\n";
	cout << "\n";

	cout << "    What do you want to log in?   " << endl;
	cout << "\t\t\t\t| Please select!" << endl;
	cout << "\n";

	Login l;
	l.initializare("Users.txt");



	cout << "\n";
	cout << "\t\t\t\t  Please login    \n";
	cout << "\n";
	string user;
	cin >> user;
	int ok = 0;
	int s = 0;
	if (user == "Administrator")
	{

		bool status1 = l.logareAdm();

		if (!status1)
		{

			cout << "\n";
			cout << "\n\tLog in Faild Register First\n";

		}
		else
		{
			s++;
			cout << "***************************************************************************************" << endl;
			cout << "************************ WELCOME ADMIN AMD Drivers and Support ************************" << endl;
			cout << "*********************** YOU CAN:ADD ITEMS,DELETE ITEMS,ADD ADMIN ********************" << endl;
			cout << "\n";

			cout << "\n\t\t\t*------------ 1.   Add the product   ------------*";
			cout << "\n\t\t\t*------------ 2.   Add new admin     ------------*";
			cout << "\n\t\t\t*------------ 3.  Delete the product ------------*";
			cout << "\n";
			cout << "\t\t\t\t  Please choose    \n";


		}
	}
	else if (user == "Client")

	{

		bool status2 = l.logareClient();
		if (!status2)
		{

			cout << "\n\tLog in Faild Register First\n";

		}
		else
		{
			ok++;
			cout << "****************************************************************************************" << endl;
			cout << "************************ WELCOME CLIENT AMD Drivers and Support ************************" << endl;
			cout << "************************ YOU CAN:ADD/REMOVE ITEMS FROM YOURS CART **********************" << endl;
			cout << "\n";


		}

	}
	return 0;
}
