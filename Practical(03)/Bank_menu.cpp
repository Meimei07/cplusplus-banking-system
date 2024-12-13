#include "Bank_menu.h"
#include "Customer_menu.h"

Bank_menu::Bank_menu(vector<Bank*> banks)
{
	Banks = banks;
}

void Bank_menu::Display_bank_menu()
{
	cout << "---------- Bank Menu ----------\n"
		<< "1. Add bank\n"
		<< "2. Show bank\n"
		<< "3. Select bank\n"
		<< "Enter your option: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1: Add_bank(); break;
	case 2: Display_bank(); break;
	case 3: Select_bank(); break;
	default: cout << "invalid option\n\n"; Display_bank_menu(); break;
	}
}

void Bank_menu::Add_bank()
{
	Bank bank;
	bank.Input(); //Bank name & branch
	Banks.push_back(&bank);
	cout << "Bank added successfully!\n\n";
	Display_bank_menu();
}

void Bank_menu::Display_bank()
{
	if (Banks.size() == 0)
	{
		cout << "No available bank yet\n\n";
		Display_bank_menu();
	}

	for (auto bank : Banks)
	{
		bank->Display(); //Bank name & branch
	}
	cout << endl;
	Display_bank_menu();
}

void Bank_menu::Select_bank()
{
	if (Banks.size() == 0)
	{
		cout << "No available bank yet\n\n";
		Display_bank_menu();
	}

	cout << "\n---------- Select Bank ----------\n";
	for (int i = 1; i <= Banks.size(); i++)
	{
		cout << i << ". " << Banks[i-1]->Bank_name << endl;
	}

	int option;
	cout << "Enter your option: "; cin >> option;

	if (option > 0 && option <= Banks.size()) {
		cout << "Bank: " << Banks[option - 1]->Bank_name << " is selected.\n\n";

		Bank* bank = Banks[option - 1];
		Customer_menu customer_menu(bank);
		customer_menu.Display_customer_menu();
	}
	else
	{
		cout << "invalid option\n\n";
	}

	Display_bank_menu();
}
