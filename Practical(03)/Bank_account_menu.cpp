#include "Bank_account_menu.h"
#include "Transaction_menu.h"

Bank_account_menu::Bank_account_menu()
{
	Customer_ptr = nullptr; 
	Customer_menu_ptr = nullptr;
}

Bank_account_menu::Bank_account_menu(Customer* customer_ptr)
{
	Customer_ptr = customer_ptr;
	Customer_menu_ptr = nullptr;
}

Bank_account_menu::Bank_account_menu(Customer* customer_ptr, Customer_menu* customer_menu_ptr)
{
	Customer_ptr = customer_ptr;
	Customer_menu_ptr = customer_menu_ptr;
}

void Bank_account_menu::Display_bank_acc_menu()
{
	cout << "\n---------- Bank Account Menu ----------\n"
		<< "1. Add bank account\n"
		<< "2. Display bank account\n"
		<< "3. Find bank account\n"
		<< "4. Select bank account\n"
		<< "0. <- back to Customer Menu\n"
		<< "Enter your option: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1: Add_bank_acc(); break;
	case 2: Display_bank_acc(); break;
	case 3: Find_bank_acc(); break;
	case 4: Select_bank_acc(); break;
	case 0: Back_to_customer_menu(); break;
	default: cout << "invalid option\n\n"; Display_bank_acc_menu(); break;
	}
}

void Bank_account_menu::Add_bank_acc()
{
	Account_type_menu acc_type_menu;
	Bank_account* accType = acc_type_menu.Display_acc_type_menu();
	accType->Input();
	Customer_ptr->Add_account(*accType); // add info of accType into Bank_accounts array
	cout << "Bank account added successfully!\n";
	Display_bank_acc_menu();
}

void Bank_account_menu::Display_bank_acc()
{
	if (Customer_ptr->Bank_accounts.size() == 0)
	{
		cout << "no available bank account yet\n";
		Display_bank_acc_menu();
	}

	for (auto bank_account : Customer_ptr->Bank_accounts)
	{
		bank_account->Get_account_info(); //acc number, acc holder, acc type, balance, status
	}
	Display_bank_acc_menu();
}

void Bank_account_menu::Find_bank_acc()
{
	int acc_number;
	cout << "Enter account number: "; cin >> acc_number;

	for (auto bank_acc : Customer_ptr->Bank_accounts)
	{
		if (bank_acc->Account_number == acc_number)
		{
			bank_acc->Get_account_info();
			Display_bank_acc_menu();
		}
	}

	cout << "There's no match bank account with entered account number!\n";
	Display_bank_acc_menu();
}

void Bank_account_menu::Select_bank_acc()
{
	if (Customer_ptr->Bank_accounts.size() == 0)
	{
		cout << "no available bank account yet\n";
		Display_bank_acc_menu();
	}

	cout << "\n---------- Select Bank Account ----------\n";

	for (int i = 0; i < Customer_ptr->Bank_accounts.size(); i++)
	{
		cout << i + 1 << ". "
			<< Customer_ptr->Bank_accounts[i]->Account_number
			<< " (" << Customer_ptr->Bank_accounts[i]->Account_type
			<< ")\n";
	}

	int option;
	cout << "Enter your option: "; cin >> option;

	if (option > 0 && option <= Customer_ptr->Bank_accounts.size()) {
		cout << "Account number: "
			<< Customer_ptr->Bank_accounts[option - 1]->Account_number
			<< " is selected.\n";

		Bank_account* bankAccount = Customer_ptr->Bank_accounts[option - 1];
		Transaction_menu transactionMenu(bankAccount);
		transactionMenu.Display_transaction_menu();
	}
	else
	{
		cout << "invalid option\n";
	}

	Display_bank_acc_menu();
}

void Bank_account_menu::Back_to_customer_menu()
{
	//Customer_menu_ptr->Display_customer_menu();
}
