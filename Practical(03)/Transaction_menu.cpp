#include "Transaction_menu.h"

Transaction_menu::Transaction_menu()
{
	Bank_acc_ptr = nullptr;
	Bank_acc_menu_ptr = nullptr;
}

Transaction_menu::Transaction_menu(Bank_account* bank_acc_ptr)
{
	Bank_acc_ptr = bank_acc_ptr;
	Bank_acc_menu_ptr = nullptr;
}

Transaction_menu::Transaction_menu(Bank_account* bank_acc_ptr, Bank_account_menu* bank_acc_menu_ptr)
{
	Bank_acc_ptr = bank_acc_ptr;
	Bank_acc_menu_ptr = bank_acc_menu_ptr;
}

void Transaction_menu::Display_transaction_menu()
{
	cout << "\n---------- Transaction Menu ----------\n"
		<< "1. Deposit\n"
		<< "2. Withdraw\n"
		<< "3. Check balance\n"
		<< "4. Display transaction info\n"
		<< "5. Display account info\n"
		<< "0. <- back to Bank Account Menu\n"
		<< "Enter your option: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1: Trans_deposit(); break;
	case 2: Trans_withdraw(); break;
	case 3: Trans_check_balance(); break;
	case 4: Display_trans_info(); break;
	case 5: Display_acc_info(); break;
	case 0: Back_to_bank_acc_menu(); break;
	default: cout << "invalid option\n\n"; Display_transaction_menu(); break;
	}
}

void Transaction_menu::Trans_deposit()
{
	Transaction trans;
	trans.Input(); // trans id, trans type, acc number, amount
	trans.Transaction_type = "Deposit";
	
	if (Bank_acc_ptr->Deposit(trans.Amount, trans.Acc_number) == true) 
	{
		Bank_acc_ptr->Account_transactions.push_back(trans);
	}
	Display_transaction_menu();
}

void Transaction_menu::Trans_withdraw()
{
	Transaction trans;
	trans.Input(); // trans id, trans type, acc number, amount
	trans.Transaction_type = "Withdraw";
	
	if (Bank_acc_ptr->Withdraw(trans.Amount, trans.Acc_number) == true)
	{
		Bank_acc_ptr->Account_transactions.push_back(trans);
	}
	Display_transaction_menu();
}

void Transaction_menu::Trans_check_balance()
{
	Bank_acc_ptr->Check_balance();
	Display_transaction_menu();
}

void Transaction_menu::Display_trans_info()
{
	Bank_acc_ptr->Display_transactions(); // trans id, trans type, acc number, amount
	Display_transaction_menu();
}

void Transaction_menu::Display_acc_info()
{
	Bank_acc_ptr->Get_account_info();
	Display_transaction_menu();
}

void Transaction_menu::Back_to_bank_acc_menu()
{
	//Bank_acc_menu_ptr->Display_bank_acc_menu();
}
