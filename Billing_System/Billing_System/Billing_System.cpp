#include <iostream>
#include <conio.h>
#include <string>
#include "Custormer.h"


using namespace std;

void Main_Menu();
void BackToMainMenu();
void Quit();
void BackOrExit(bool run);

int main()
{
	C.Add_customer("1001", "154222", "xxxxxx", "yyyyyy",2);
	C.Add_customer("200020802263", "0702475895", "aaaaaa", "zzzzzz",1);
	Main_Menu();
	
	return 0;
}

void Main_Menu()
{
	system("cls");
	cout << "----------------------------------------" << endl;
	cout << "        WELCOME TO THE MAIN MENU        " << endl;
	cout << "----------------------------------------" << endl;
	cout << endl << endl;
	cout << "1.Add Custormer" << endl;
	cout << "2.Veiw Custormer Details" << endl;
	cout << "3.Modify Custormer" << endl;
	cout << "4.Delete custormer" << endl;
	cout << "5.View all custormers" << endl;
	cout << "6.Billing section" << endl;
	cout << "7.Quit" << endl << endl;;

	cout << "Enter the index: ";
	int value;
	cin >> value;

	switch (value)
	{
	case 1:
	{
		// Add customer
		bool run_AddCustomer = true;
		while (run_AddCustomer) {
			system("cls");
			cout << "****************	ADD NEW CUSTORMER	**************" << endl << endl;
			cout << "Enter ID Number: ";
			string ID;
			cin >> ID;
			cout << endl;
			cout << "Enter Mobile Number: ";
			string Mobile;
			cin >> Mobile;
			cout << endl;
			cout << "Enter Name: ";
			string Name;
			cin >> Name;
			cout << endl;
			cout << "Enter Address: ";
			string Address;
			cin >> Address;
			cout << "Enter the month number to start calculating bill(As a number): ";
			int bill_month;
			cin >> bill_month;
			cout << endl;

			C.Add_customer(ID, Mobile, Name, Address,bill_month);

			C.Display_custormer_info(C.size-1);
			cout << endl << endl;
			//chek save or not
			cout << "1.Save" << endl;
			cout << "2.Cancel" << endl;
			int save_customer;
			cin >> save_customer;
			switch (save_customer)
			{
			case 1:
				system("cls");
				cout << "\nSuccessfully saved!" << endl;
				run_AddCustomer = false;
				break;
			case 2:
				C.Delete_customer(C.size-1);
				run_AddCustomer = false;
				break;
			default:
				cout << "\nInvalid input" << endl;
				break;
			}
			// Back to the  main menu
			BackToMainMenu();
		}
		break;
	}
	case 2:
	{
		//Veiw Customer Details
		system("cls");
		cout << "*******	Search custormer		*******" << endl << endl;
		cout << "Searching methods :- " << endl;
		cout << "1.Using NIC number" << endl;
		cout << "2.Using Mobile Number" << endl;
		cout << "3.Back to the main menu" << endl << endl;

		cout << "Enter the index : ";
		int Search_method;
		cin >> Search_method;
		switch (Search_method)
		{
		case 1:
		{
			system("cls");
			cout << "Enter the NIC number: ";
			string id;
			cin>> id;
			system("cls");
			C.Display_custormer_info(C.search_custormer_id(id));
			break;
		}

		case 2:
		{
			system("cls");
			cout << "Enter the Mobile number: ";
			string mobile;
			cin>> mobile;
			system("cls");
			C.Display_custormer_info(C.search_custormer_mobile(mobile));
			break;
		}
		case 3:
			Main_Menu();
			break;
		}
		// Back to main menu
		BackToMainMenu();
		break;
	}
	case 3:
	{
		//modify customer
		system("cls");
		cout << "Enter the Mobile number: ";
		string mobile;
		cin>> mobile;
		C.modify_custormer_mobile(C.search_custormer_mobile(mobile));
		BackToMainMenu();
		break;
	}
	case 4:
	{
		//Delete a customer
		{
			system("cls");
			cout << "************   Delete Custormer  ***********" << endl;
			cout << "Enter the mobile number: ";
			string mobile;
			cin>>mobile;
			C.Delete_customer(C.search_custormer_mobile(mobile));
			cout << "\n*Custormer deleted succesfuly*" << endl;
			BackToMainMenu();
			break;
		}
	}
	case 5:
	{
		//View all customers
		system("cls");
		cout << "************  All custormers  **********" << endl;
		C.Display_customers();
		cout << endl;
		BackToMainMenu();
		break;
	}
	case 6:
		system("cls");
		C.Bills();
		break;
	case 7:
	{
		Quit();
		break;
	}
	default:
		cout << "\nInvalid index" << endl;
		break;
	}
}

void BackToMainMenu()
{
	cout << "1.Back" << endl;
	cout << "2.Exit" << endl;
	int Back;
	cin >> Back;
	switch (Back)
	{
	case 1:
		Main_Menu();
		break;
	case 2:
		Quit();
		break;
	default:
		cout << "\nInvalid input" << endl;
		BackToMainMenu();
	}
}

void BackOrExit(bool run)
{
	cout << "1.Back" << endl;
	cout << "2.Exit" << endl;
	int Go_Back;
	cin >> Go_Back;
	switch (Go_Back)
	{
	case 1:
		run = true;
		break;
	case 2:
		run = false;
		Quit();
		break;
	default:
		cout << "\nInvalid input" << endl;
	}
}

void Quit()
{
	system("cls");
	cout << "\n\n\t*********	THANK YOU	*********" << endl;
}