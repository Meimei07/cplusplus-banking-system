#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#pragma once
class Transaction
{
public:
	int Transaction_id;
	string Transaction_type;
	double Amount;
	int Acc_number;

	Transaction();
	Transaction(int trans_id, string trans_type, double amount, int acc_number);
	void Get_transaction_info();
	void Input();
};