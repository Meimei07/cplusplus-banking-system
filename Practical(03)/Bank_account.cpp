#include "Bank_account.h"
#include "FixedDeposit_account.h"
#include "Checking_account.h"
#include "Saving_account.h"

Bank_account::Bank_account()
{
	Account_number = 0;
	Account_holder = "unknown";
	Balance = 0;
	Account_type = "default";
	Status = 1; // 1=active, 0=unactive
}

Bank_account::Bank_account(string acc_type)
{
	Account_type = acc_type;
	Account_number = 0;
	Account_holder = "unknown";
	Balance = 0;
	Status = 1; // 1=active, 0=unactive
}

Bank_account::Bank_account(int acc_number, string acc_holder, string acc_type)
{
	Account_number = acc_number;
	Account_holder = acc_holder;
	Account_type = acc_type;
	Balance = 0;
	Status = 1;
}

bool Bank_account::Deposit(double amount, int acc_number)
{
	if (acc_number == this->Account_number) 
	{
		if (amount > 0) 
		{
			Balance += amount;
			cout << "Deposit successfully!\n";
			return true;
		}
		else 
		{
			cout << "invalid amount!\n";
			return false;
		}
	}
	else
	{
		cout << "incorrect account number\n";
		return false;
	}
}

bool Bank_account::Withdraw(double amount, int acc_number)
{
	if (acc_number == this->Account_number)
	{
		if (amount <= 0 || amount > Balance)
		{
			cout << "invalid amount!\n";
			return false;
		}
		else
		{
			Balance -= amount;
			cout << "Withdraw successfully!\n";
			return true;
		}
	}
	else
	{
		cout << "incorrect account number\n";
		return false;
	}
}

void Bank_account::Check_balance()
{
	cout << "\n|Account number: " << Account_number
		<< "|Your balance: " << Balance << "|\n";
}

void Bank_account::Get_account_info()
{
	cout << "\n|Account number: " << Account_number
		<< "|Account holder: " << Account_holder
		<< "|Account type: " << Account_type
		<< "|Balance: " << Balance
		<< "|Status: " << Status << "|";
}

void Bank_account::Display_transactions()
{
	for (auto transaction : Account_transactions)
	{
		transaction.Get_transaction_info();
	}
}

void Bank_account::Input()
{
	srand(time(0));
	Account_number = rand() % (1000000 - 100000) + 100000;
	cout << "Account holder: "; cin >> Account_holder;
	cout << "Balance: "; cin >> Balance;
}