#include <iostream>
#include "Bank_account.h"
using namespace std;

#pragma once
class Checking_account : public Bank_account
{
public:
	int Limit;

	Checking_account();
	Checking_account(int acc_number, string acc_holder);

	void Apply_fee();
};