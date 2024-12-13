#include <iostream>
#include "Transaction.h"
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>
using namespace std;

#pragma once
class Bank_account
{
public:
	int Account_number;
	string Account_holder;
	double Balance;
	string Account_type;
	int Status;
	vector<Transaction> Account_transactions;	

	Bank_account();
	Bank_account(string acc_type);
	Bank_account(int acc_number, string acc_holder, string acc_type);

	bool Deposit(double amount, int acc_number);
	bool Withdraw(double amount, int acc_number);
	void Check_balance();
	void Get_account_info();
	void Display_transactions();
	void Input();
};