#include "Saving_account.h"

Saving_account::Saving_account()
{
	Account_number = 0;
	Account_holder = "unknown";
	Account_type = "Saving account";
	Interest_rate = 0.01;
	Balance = 0;
	Status = 1;
}

Saving_account::Saving_account(int acc_number, string acc_holder)
{
	Account_number = acc_number;
	Account_holder = acc_holder;
	Account_type = "Saving account";
	Interest_rate = 0.01;
	Balance = 0;
	Status = 1;
}

void Saving_account::Apply_interest_rate()
{
	Balance += Balance * Interest_rate;
}