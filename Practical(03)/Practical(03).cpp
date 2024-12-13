#include <iostream>
#include <vector>
#include "Bank_menu.h"
using namespace std;

int main()
{
	vector<Bank*> banks;
	Bank_menu bank_menu(banks);
	bank_menu.Display_bank_menu();
}