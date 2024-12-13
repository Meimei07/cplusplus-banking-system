#include <iostream>
#include "Bank.h"
//#include "Customer_menu.h"
#include <vector>
using namespace std;

#pragma once
class Bank_menu
{
	// Bank -> Customer -> Bank_acc -> Transaction
public: 
	vector<Bank*> Banks;

	Bank_menu(vector<Bank*> banks);

	void Display_bank_menu();
	void Add_bank();
	void Display_bank();
	void Select_bank();
};