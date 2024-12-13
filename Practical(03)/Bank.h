#include <iostream>
#include "Customer.h"
#include <vector>
using namespace std;

#pragma once
class Bank
{
public:
	string Bank_name;
	string Branch;
	vector<Customer*> customers;

	Bank();
	Bank(string bank_name, string branch);

	void Add_customer(Customer& customer);
	void Find_customer(int customer_id);
	void Input();
	void Display();
};