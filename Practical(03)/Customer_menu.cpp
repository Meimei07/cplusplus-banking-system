#include "Customer_menu.h"
#include "Bank_account_menu.h"

Customer_menu::Customer_menu()
{
	Bank_ptr = nullptr;
	Bank_menu_prt = nullptr;
}

Customer_menu::Customer_menu(Bank* bankptr)
{
	Bank_ptr = bankptr;
	Bank_menu_prt = nullptr;
}

Customer_menu::Customer_menu(Bank* bank_ptr, Bank_menu* bank_menu_ptr)
{
	Bank_ptr = bank_ptr;
	Bank_menu_prt = bank_menu_ptr;
}

void Customer_menu::Display_customer_menu()
{
	cout << "---------- Customer Menu ----------\n"
		<< "1. Add customer\n"
		<< "2. Display customer\n"
		<< "3. Find customer\n"
		<< "4. Select customer\n"
		<< "0. <- back to Bank Menu\n"
		<< "Enter your option: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1: Add_customer(); break;
	case 2: Display_customer(); break;
	case 3: Find_customer(); break;
	case 4: Select_customer(); break;
	case 0: Back_to_bank_menu(); break;
	default: cout << "invalid option\n\n"; Display_customer_menu(); break;
	}
}

void Customer_menu::Add_customer()
{
	Customer customer;
	customer.Input(); // name, id, address
	//Bank_ptr->Add_customer(customer);
	Bank_ptr->customers.push_back(&customer);
	cout << "Customer added successfully!\n\n";
	Display_customer_menu();
}

void Customer_menu::Display_customer()
{
	if (Bank_ptr->customers.size() == 0)
	{
		cout << "No customer yet\n\n";
		Display_customer_menu();
	}

	for (auto customer : Bank_ptr->customers)
	{
		customer->Get_customer_info(); // name, id, address
	}
	cout << endl;
	Display_customer_menu();
}

void Customer_menu::Find_customer()
{
	int customer_id;
	cout << "Enter customer ID: "; cin >> customer_id;

	Bank_ptr->Find_customer(customer_id);
	Display_customer_menu();
}

void Customer_menu::Select_customer()
{
	if (Bank_ptr->customers.size() == 0)
	{
		cout << "No customer yet\n\n";
		Display_customer_menu();
	}

	cout << "\n---------- Select Customer ----------\n";

	int index = 1;
	for (auto customer : Bank_ptr->customers)
	{
		cout << index << ". "
			<< Bank_ptr->customers[index - 1]->Customer_name << endl;
		index++;
	}

	int option;
	cout << "Enter option: "; cin >> option;

	if (option > 0 && option <= Bank_ptr->customers.size()) {
		cout << "Customer: " << Bank_ptr->customers[option - 1]->Customer_name
			<< " is selected.\n";

		Customer* customer = Bank_ptr->customers[option - 1];
		Bank_account_menu bank_account_menu(customer);
		bank_account_menu.Display_bank_acc_menu();
	}
	else
	{
		cout << "invalid option\n\n";
	}
	Display_customer_menu();
}

void Customer_menu::Back_to_bank_menu()
{
	//Bank_menu_prt->Display_bank_menu();
}
