#include <iostream>
#include "Bank_account.h"
using namespace std;

#pragma once
class FixedDeposit_account : public Bank_account
{
public:
	int Fix_date;
	int Withdraw_date;
	double Penalty_fee;

	FixedDeposit_account();
	FixedDeposit_account(int acc_number, string acc_holder);

	void Withdraw_early(double amount);
};