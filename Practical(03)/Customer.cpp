#include "Customer.h"

Customer::Customer()
{
	Customer_name = "unknown";
	Customer_id = 0;
	Address = "unknown";
}

Customer::Customer(string customer_name, int customer_id, string address)
{
	Customer_name = customer_name;
	Customer_id = customer_id;
	Address = address;
}

void Customer::Open_account(Bank_account bank_account)
{
	Bank_accounts.push_back(&bank_account);
}

void Customer::Close_account(int account_number)
{
	for (auto bank_account : Bank_accounts)
	{
		if (bank_account->Account_number == account_number)
		{
			bank_account->Status = 0; // close or unactivate acc
		}
	}
}

void Customer::Get_customer_info()
{
	cout << "\n|Customer name: " << Customer_name
		<< "|Cusomer ID: " << Customer_id
		<< "|Address: " << Address << "|\n";
}

void Customer::Display_accounts()
{
	for (auto bank_account : Bank_accounts)
	{
		bank_account->Get_account_info();
	}
	cout << endl;
}

void Customer::Add_account(Bank_account& bank_acc)
{
	Bank_accounts.push_back(&bank_acc);
}

void Customer::Input()
{
	srand(time(0));
	Customer_id = rand() % 1000;
	cout << "\nCustomer name: "; cin >> Customer_name;
	cout << "Address: "; cin >> Address;
}
