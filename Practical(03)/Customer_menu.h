#include <iostream>
#include "Customer.h"
#include "Bank_menu.h"
#include "Bank.h"
using namespace std;

#pragma once
class Customer_menu
{
public:
	Bank* Bank_ptr;
	Bank_menu* Bank_menu_prt;

	Customer_menu();
	Customer_menu(Bank* bankptr);
	Customer_menu(Bank* bank_ptr, Bank_menu* bank_menu_ptr);

	void Display_customer_menu();
	void Add_customer();
	void Display_customer();
	void Find_customer();
	void Select_customer();
	void Back_to_bank_menu();
};