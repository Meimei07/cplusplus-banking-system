#include "Account_type_menu.h"
#include "Bank_account_menu.h"
#include "Customer.h"

Bank_account* Account_type_menu::Display_acc_type_menu()
{
	cout << "\n---------- Account Type Menu ----------\n"
		<< "1. Saving account\n"
		<< "2. Checking account\n"
		<< "3. Fix deposit account\n"
		<< "Enter your option: ";
	int option;
	cin >> option;

	Bank_account* acc_type = nullptr;

	switch (option)
	{
	case 1: acc_type = new Saving_account(); break;
	case 2: acc_type = new Checking_account(); break;
	case 3: acc_type = new FixedDeposit_account(); break;
	default: cout << "invalid option\n\n"; Display_acc_type_menu(); break;
	}
	return acc_type;
}