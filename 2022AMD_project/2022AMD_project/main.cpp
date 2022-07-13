#include<iostream>
#include<fstream>
#include <string>
#include"Products.h"
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

			cout << "\n\t\t\t*------------ 1.   Add the product     ------------*";
			cout << "\n\t\t\t*------------ 2.   Delete the product  ------------*";
			cout << "\n\t\t\t*------------ 3.   Add new admin       ------------*";
			cout << "\n";
			cout << "\t\t\t\t  Please choose    \n";


			Administrator a1;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
				//incercare
				//a1.addProduse();
			case 2:
				//incercare
				//a1.deleteProduse();
			default:
				break;
			}

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
	// daca s-a logat un admin sau un client se afiseaza meniul, altfel nu

	if ((s > 0) || (ok > 0))
	{
		Menu m;
		
		m.categorii("Products.txt");
		cout << "\n";
		cout << "********************************** THIS IS THE STORE MENU ********************************************" << endl;
		cout << "\n";
		m.print_menu();
		
		cout << "\n";
		cout << "*********************** YOU CAN FILTER THE PRODUCTS AFTER ************************" << endl;

		cout << "\n";
		cout << "\t\t\t\t|   1 Price    |\n";
		cout << "\n";
	
		Menu p;
		p.filtrareprod("Products.txt");
		p.print_filtrarePret();
		
		
	}
	return 0;
}
