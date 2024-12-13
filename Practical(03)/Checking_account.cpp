#include "Checking_account.h"

Checking_account::Checking_account()
{
	Account_number = 0;
	Account_holder = "unknown";
	Account_type = "Checking account";
	Balance = 0;
	Status = 1;
	Limit = 3;
}

Checking_account::Checking_account(int acc_number, string acc_holder)
{
	Account_number = acc_number;
	Account_holder = acc_holder;
	Account_type = "Checking account";
	Balance = 0;
	Status = 1;
	Limit = 3;
}

void Checking_account::Apply_fee()
{
	if (Account_transactions.size() > Limit)
	{
		cout << "You are out of limit!\n";
		Balance -= Balance * (Limit / 100);
	}
	Bank_account::Withdraw(Balance, Account_number);
}
