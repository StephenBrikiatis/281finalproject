//By Gabriel Pereyra
#ifndef TRANSACTIONBASKET_H
#define TRANSACTIONBASKET_H

#include "transaction.h"
#include "correlationBasket.h"

#include <string>
#include <fstream>

const int LARGEST_SIZE = 100000;

using namespace std;

struct TransactionBasket
{
	private:
		int size; //size of transaction basket
		Transaction *transactionList = new Transaction[size]; //list of all transactions basket is currently holding

	public:	
		//contructors
		TransactionBasket(int newSize);
		TransactionBasket(string fileName);
		~TransactionBasket();

		void populate(TransactionBasket otherBasket);
		void compare(CorrelationBasket correlation);

		//getters/setters
		int getSize();
		void setSize(int size);
		Transaction getTransaction(int position);
};

#endif