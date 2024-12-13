#include <iostream>
#include "Bank_account.h"
#include "Customer.h"
#include "Bank_menu.h"
#include "Account_type_menu.h"
#include "Customer_menu.h"
using namespace std;

#pragma once
class Bank_account_menu
{
public:
	Customer* Customer_ptr;
	Customer_menu* Customer_menu_ptr;

	Bank_account_menu();
	Bank_account_menu(Customer* customer_ptr);
	Bank_account_menu(Customer* customer_ptr, Customer_menu* customer_menu_ptr);

	void Display_bank_acc_menu();
	void Add_bank_acc();
	void Display_bank_acc();
	void Find_bank_acc();
	void Select_bank_acc();
	void Back_to_customer_menu();
};