#include <iostream>
#include "Bank_account.h"
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>
using namespace std;

#pragma once
class Customer
{
public:
	string Customer_name;
	int Customer_id;
	string Address;
	vector<Bank_account*> Bank_accounts;

	Customer();
	Customer(string customer_name, int customer_id, string address);

	void Open_account(Bank_account bank_account);
	void Close_account(int account_number);
	void Get_customer_info();
	void Display_accounts();
	void Add_account(Bank_account& bank_acc);
	void Input();
};