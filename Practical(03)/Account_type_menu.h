#include <iostream>
#include "Bank_account.h"
#include "Saving_account.h"
#include "Checking_account.h"
#include "FixedDeposit_account.h"
#include "Customer.h"
using namespace std;

#pragma once
class Account_type_menu
{
public:
	Customer* CustomerPtr;
	FixedDeposit_account* fix_acc;

	Bank_account* Display_acc_type_menu();
};