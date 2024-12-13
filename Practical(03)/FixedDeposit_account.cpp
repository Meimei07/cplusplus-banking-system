#include "FixedDeposit_account.h"

FixedDeposit_account::FixedDeposit_account()
{
	Account_number = 0;
	Account_holder = "unknown";
	Account_type = "Fix deposit account";
	Balance = 0;
	Status = 1;
	Fix_date = 10;
	Penalty_fee = 10;
}

FixedDeposit_account::FixedDeposit_account(int acc_number, string acc_holder)
{
	Account_number = acc_number;
	Account_holder = acc_holder;
	Account_type = "Fix deposit account";
	Balance = 0;
	Status = 1;
	Fix_date = 10;
	Penalty_fee = 10;
}

void FixedDeposit_account::Withdraw_early(double amount)
{
	cout << "Withdraw date: "; cin >> Withdraw_date;
	cout << "Fix date: "; cin >> Fix_date;
	if (Withdraw_date < Fix_date)
	{
		cout << "Penalty fee: " << Penalty_fee << endl;
		Balance -= Penalty_fee * amount;
	}
	Bank_account::Withdraw(amount, Account_number);
}