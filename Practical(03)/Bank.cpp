#include "Bank.h"

Bank::Bank()
{
	Bank_name = "unknown";
	Branch = "unknown";
}

Bank::Bank(string bank_name, string branch)
{
	Bank_name = bank_name;
	Branch = branch;
}

void Bank::Add_customer(Customer& customer)
{
	customers.push_back(&customer);
}

void Bank::Find_customer(int customer_id)
{
	for (auto customer : customers)
	{
		if (customer->Customer_id == customer_id)
		{
			customer->Get_customer_info();
			return;
		}
	}
	cout << "There's no match customer with the entered ID!\n";
	cout << endl;
}

void Bank::Input()
{
	cout << "\nBank name: "; cin >> Bank_name;
	cout << "Branch: "; cin >> Branch;
}

void Bank::Display()
{
	cout << "\n|Bank name: " << Bank_name
		<< "|Branch: " << Branch << "|\n";
}