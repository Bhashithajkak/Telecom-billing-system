#pragma once

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void Main_Menu();
void BackToMainMenu();
void Quit();
void BackOrExit(bool run);

class Month
{
public:
	int year;
	string month;
	double bill_amount;
	bool paid;

	Month()
	{
		year = NULL;
		month = "";
		bill_amount = NULL;
		paid = true;
	}

	Month(string Month)
	{
		year = NULL;
		month = Month;
		bill_amount = NULL;
		paid = true;
	}
};

class Node
{
public:
	string Id;
	string Mobile;
	string Name;
	string Address;
	Month months[12] = { Month("Januarry"),Month("February"),Month("March     "),Month("Appril    "),Month("May      "),
		Month("June       "),Month("July     "),Month("Auguest  "),Month("September"),Month("October  "),Month("November"),Month("December") };
	int Last_pay;
	double Balance;
	Node* next;
	
	Node()
	{
		Id = "";
		Mobile = "";
		Name = "";
		Address = "";
		Month months[12] = { Month("Januarry"),Month("February"),Month("March     "),Month("Appril    "),Month("May      "),
	Month("June       "),Month("July     "),Month("Auguest  "),Month("September"),Month("October  "),Month("November"),Month("December") };
		Last_pay = NULL;
		Balance = NULL;
		next = NULL;

	}

	Node(string id, string mobile, string name, string address, int bill_start)
	{
		Id = id;
		Mobile =mobile;
		Name = name;
		Address = address;
		Month months[12] = { Month("Januarry"),Month("February"),Month("March     "),Month("Appril    "),Month("May      "),
	Month("June       "),Month("July     "),Month("Auguest  "),Month("September"),Month("October  "),Month("November"),Month("December") };
		Last_pay = bill_start - 1;
		next = NULL;

	}
};

class Custormer
{
private:
	Node* head;
	Node* tail;
	

public:

	int size;

	//******************************Add a custormer*******************************
	void Add_customer(string id, string mobile, string name, string address,int bill_start)
	{
		Node* temp = new Node(id, mobile, name, address,bill_start);
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			size++;
		}
		else
		{
			tail->next = temp;
			tail = temp;
			size++;
		}
	}

	//****************************Display All custormers*********************************
	void Display_customers()
	{
		if (head == NULL)
		{
			cout << "\nEmpty list" << endl;
		}
		else
		{
			Node* current = head;
			for (int i = 0; i < size; i++)
			{
				cout << "ID	: " << (current->Id) << endl;
				cout << "Mobile	: " << (current->Mobile) << endl;
				cout << "Name : " << current->Name << endl;
				cout << "Address : " << current->Address << endl;
				cout << endl;
				current = current->next;
			}
		}

	}

	//*********************** Disply custormer info ************************************
	void Display_custormer_info(int key)
	{
		Node* current = head;
		for (int i = 0; i < key; i++)
		{
			current = current->next;
		}
		cout << "**********  Customer Details  ***********" << endl << endl;
		cout << "ID		 : " << (current->Id) << endl;
		cout << "Mobile	 : " << (current->Mobile) << endl;
		cout << "Name	 : " <<current->Name << endl;
		cout << "Address : " << current->Address << endl;
		cout << endl;
	}

	//******************************* Delete a customer *********************************
	void Delete_customer(int pos)
	{
		if (pos<0 || pos>size)
			cout << "\nInvalid Index" << endl;

		else if (pos == 0)
		{
			if (head == NULL)
				cout << "\nEmpty List" << endl;

			else
			{
				Node* temp = head;

				if (size == 1)
				{
					delete temp;
					head = NULL;
					tail = NULL;
				}

				else
				{
					head = temp->next;
					delete temp;
				}
				size--;
			}
		}

		else if (pos == size - 1)
		{
			if (head == NULL)
				cout << "\nEmpty List" << endl;

			else
			{
				Node* temp = tail;

				if (size == 1) {
					delete temp;
					head = NULL;
					tail = NULL;
				}

				else
				{
					Node* current = head;

					for (int i = 0; i < size - 2; i++)
					{
						current = current->next;
					}
					tail = current;
					tail->next = NULL;
					delete temp;
				}
				size--;
			}
		}

		else
		{
			Node* current = head;

			for (int i = 0; i < pos-1; i++)
				current = current->next;

			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;

		}

	}

	//****************************** Modify custormer ********************************
	void modify_custormer_mobile(int index)
	{
		system("cls");
		
		cout << "1.Change owner details" << endl;
		cout << "2.Back to the main menu" << endl;
		cout << "3.Quit" << endl;
		int value;
		cout << "Enter the index: ";
		cin >> value;

		Node* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		bool run2 = true;
		while (run2)
		{
			switch (value)
			{
			case 1:
			{
				// Change customer 
				system("cls");
				cout << "**** Owner details ****" << endl << endl;
				cout << "ID		 : " << current->Id << endl;
				cout << "Name	 : " << current->Name << endl;
				cout << "Address : " << current->Address << endl << endl << endl;

				cout << "1.Change ID" << endl;
				cout << "2.Change Name" << endl;
				cout << "3.Change Address" << endl;
				cout << "4.Back" << endl;
				cout << "5.Quit" << endl;
				cout << "Enter the index:	";

				int value2;
				cin >> value2;
				cout << endl;
				switch (value2)
				{
				case 1:
				{
					string temp = current->Id;
					//get new id for change id
					cout << "Enter the new ID : ";
					cin >> current->Id;
					system("cls");

					//showing modified detail
					Display_custormer_info(index);
					cout << endl << endl;
					//chek save or not
					cout << "1.Save" << endl;
					cout << "2.Cancel" << endl;
					int save;
					cin >> save;
					switch (save)
					{
					case 1:
						system("cls");
						cout << "\nSuccessfully saved!" << endl;
						break;
					case 2:
						current->Id = temp;
						run2 = false;
						break;
					default:
						cout << "\nInvalid input" << endl;
					}
					BackOrExit(run2);

					break;

				}
				case 2:
				{ //assign current value to temp until save
					string temp = current->Name;
					cout << "Enter the new Name : ";
					cin >> current->Name;
					system("cls");

					//showing modified detail
					Display_custormer_info(index);
					cout << endl << endl;
					//chek save or not
					cout << "1.Save" << endl;
					cout << "2.Cancel" << endl;
					int save;
					cin >> save;
					switch (save)
					{
					case 1:
						system("cls");
						cout << "\nSuccessfully saved!" << endl;
						break;
					case 2:
						current->Name = temp;
						break;
					default:
						cout << "\nInvalid input\a" << endl;
					}
					BackOrExit(run2);

					break;

				}
				case 3:
				{
					//assign current value to temp until save
					string temp = current->Address;
					cout << "Enter the new Address : ";
					cin >> current->Address;
					system("cls");

					//showing modified detail
					Display_custormer_info(index);
					cout << endl << endl;
					//chek save or not
					cout << "1.Save" << endl;
					cout << "2.Cancel" << endl;
					int save;
					cin >> save;
					switch (save)
					{
					case 1:
						system("cls");
						cout << "\nSuccessfully saved!" << endl;
						break;
					case 2:
						current->Address = temp;

						break;
					default:
						cout << "\nInvalid input" << endl;
						break;
					}
					BackOrExit(run2);

					break;
				}

				case 4:
				{
					run2 = false;
					modify_custormer_mobile(index);
				}
				case 5:
				{
					run2 = false;
					Quit();
				}
				default:
				{
					cout << "\nInvalid index" << endl;
					run2 = true;
					break;
				}

				}
			
			case 2:
			{
				Main_Menu();
				break;
			}
			case 3:
			{
				Quit();
				break;
			}
			default:
				cout << "\a" << endl;
				modify_custormer_mobile(index);
			}
			}
		}

	}

	//***************************** Search custormer Id ***********************************
	int search_custormer_id(string id)
	{
		Node* current = head;
		int found = 0;
		for (int i = 0; i < size; i++)
		{
			if ((current->Id).compare(id)==0)
			{
				found = 1;
				return i;
			}

			current = current->next;
		}

		if (found == 0)
		{
			cout << "\ncustormer not found" << endl;
		}
	}

	//**************************** Search custormer mobile ***********************************
	int search_custormer_mobile(string mobile)
	{
		Node* current = head;
		int found = 0;
		for (int i = 0; i < size; i++)
		{
			if ((current->Mobile).compare(mobile)==0)
			{
				found = 1;
				return i;
			}
			
			current = current->next;
		}

		if (found == 0)
		{
			cout << "\ncustomer not found" << endl;
		}
	}

	//******************** Bill Section *********************************
	void Bills()
	{
		system("cls");
		cout << "*********    Billing section  ************" << endl << endl;

		cout << "Enter the mobile number: ";
		string mobile;
		cin >> mobile;
		cout << endl << endl;
		cout << "1.View bill details" << endl;
		cout << "2.Pay bills" << endl;
		cout << "3.Add bill values" << endl;
		cout << "4.Back to  main menu" << endl << endl;
		cout << "Enter the value: ";
		int bills_value;
		cin >> bills_value;
		switch (bills_value)
		{
		case 1:
			show_UnpaidBills(search_custormer_mobile(mobile));
			cout << "Enter 1 Back to Bill Menu" << endl;
			cout << "Enter 2 Back to Main Menu" << endl;
			int num;
			cout << "Enter : ";
			cin >> num;
			cout << endl;
			if (num == 1)
			{
				Bills();
			}
			else if (num == 2)
			{
				Main_Menu();
			}
			else
			{
				cout << "\nInvalid Input" << endl;
				Quit();
			}
			break;
		case 2:
			Pay(search_custormer_mobile(mobile));
			cout << "Enter 1 Back to Bill Menu" << endl;
			cout << "Enter 2 Back to Main Menu" << endl;
			int num2;
			cout << "Enter : ";
			cin >> num2;
			cout << endl;
			if (num2 == 1)
			{
				Bills();
			}
			else if (num == 2)
			{
				Main_Menu();
			}
			else
			{
				cout << "\nInvalid Input" << endl;
				Quit();
			}
			break;
		case 3:
		{
			system("cls");
			cout << endl;

			cout << "**************  Add bill values   ****************" << endl;

			cout << "Enter the year: ";
			int year;
			cin >> year;
			cout << "Enter the month number: ";
			int month_num;
			cin >> month_num;
			cout << "Enter the bill amount: ";
			double Amount;
			cin >> Amount;
			Add_bill(month_num, year, Amount, search_custormer_mobile(mobile));
			cout << endl;
			cout << "\nBill added successfully!" << endl;
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 1000000000; j++)
				{

				}
				cout << "* " ;
			}
			system("cls");
			cout << "1.Add new Bill" << endl;
			cout << "2.Back to Main Menu" << endl;
			int num;
			cout << "Enter  your choice: ";
			cin >> num;
			cout << endl;
			if (num == 1)
			{
				Bills();
			}
			else if (num == 2)
			{
				Main_Menu();
			}
			else
			{
				cout << "\nInvalid Input" << endl;
				Quit();
			}
			
		}
		case 4:
			system("cls");
			Main_Menu();
			break;
		default:
			system("cls");
			cout << "\nInvalid input" << endl;
			Bills();

		}
	}

	//*********************** Add Bills ********************************
	void Add_bill(int month_num, int Year, double amount, int index)
	{
		Node* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		current->months[month_num - 1].year = Year;
		current->months[month_num - 1].bill_amount = amount;
		current->months[month_num - 1].paid = false;

	}

	//***************** Show Unpaid Bills *************************
	void show_UnpaidBills(int index)
	{
		system("cls");
		//travel to the appropiate customer
		Node* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		// show the details of unpaid bills
		cout << "***************           Unpaid Bills     ************" << endl << endl;
		cout << "Month" << "	:	" << "Bill amount(Rs.) " << endl;
		double total_unpaid = 00.00;
		for (int i = 0; i < 12; i++)
		{
			
			if (!current->months[i].paid)
				cout << current->months[i].month << "	:	" << current->months[i].bill_amount << endl;

			total_unpaid = total_unpaid + current->months[i].bill_amount;
		}
		cout << endl;
		cout << "Balance  " << "	:	" << current->Balance << endl;
		cout << endl << endl;
		total_unpaid = total_unpaid - current->Balance;
		cout << "--------------------------------------" << endl;
		cout << "Total   " << "	:	" << total_unpaid << endl;
		cout << "--------------------------------------" << endl;

	}

	// ****************   pay   ********************
	void Pay(int index)
	{
		system("cls");
		//travel to the appropiate customer
		Node* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		show_UnpaidBills(index);
		cout << endl << endl;
		cout << "Pay amount(Rs.) : ";
		double pay_amount;
		cin >> pay_amount;
		cout << "\nPaid successfully!" << endl;
		cout << endl;
		double pay_balance = pay_amount;
		for (int i = current->Last_pay; pay_balance < current->Last_pay + 1; i++)
		{
			pay_balance = pay_balance - current->months[current->Last_pay + 1].bill_amount;
			current->months[current->Last_pay + 1].paid = true;
			current->Last_pay++;

		}
		current->Balance = pay_balance;
	}
};
Custormer C;


