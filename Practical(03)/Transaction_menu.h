#include <iostream>
#include "Bank.h"
#include "Customer.h"
#include "Transaction.h"
#include "Bank_account.h"
#include "Bank_account_menu.h"
using namespace std;

#pragma once
class Transaction_menu
{
public:
	Bank_account* Bank_acc_ptr;
	Bank_account_menu* Bank_acc_menu_ptr;
	Bank* Bank_ptr;

	Transaction_menu();
	Transaction_menu(Bank_account* bank_acc_ptr);
	Transaction_menu(Bank_account* bank_acc_ptr, Bank_account_menu* bank_acc_menu_ptr);

	void Display_transaction_menu();
	void Trans_deposit();
	void Trans_withdraw();
	void Trans_check_balance();
	void Display_trans_info();
	void Display_acc_info();
	void Back_to_bank_acc_menu();
};