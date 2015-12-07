#ifndef TRANSACTIONBASKET_H
#define TRANSACTIONBASKET_H

#include <string>

using namespace std;

struct TransactionBasket
{
	private:
		int* transactionList[100]; //list of all transactions basket is currently holding
		int size; //size of transaction basket

	public:
		//contructors
		TransactionBasket();
		TransactionBasket(string fileName);
};

#endif