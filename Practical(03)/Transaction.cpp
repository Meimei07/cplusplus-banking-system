#include "Transaction.h"

Transaction::Transaction()
{
	Transaction_id = -1;
	Transaction_type = "transaction-type";
	Amount = 0;
	Acc_number = 0;
}

Transaction::Transaction(int trans_id, string trans_type, double amount, int acc_number)
{
	Transaction_id = trans_id;
	Transaction_type = trans_type;
	Amount = amount;
	Acc_number = acc_number;
}

void Transaction::Get_transaction_info()
{
	cout << "|Transaction ID: " << Transaction_id
		<< "|Transaction type: " << Transaction_type
		<< "|Account number: " << Acc_number
		<< "|Amount: " << Amount << "|\n";
}

void Transaction::Input()
{
	srand(time(0));
	Transaction_id = rand() % 100;
	cout << "Account number: "; cin >> Acc_number;
	cout << "Amount: "; cin >> Amount;
}