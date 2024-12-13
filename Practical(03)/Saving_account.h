#include <iostream>
#include "Bank_account.h"
using namespace std;

#pragma once
class Saving_account : public Bank_account
{
public:
	int Interest_rate;

	Saving_account();
	Saving_account(int acc_number, string acc_holder);

	void Apply_interest_rate();
};