//By Gabriel Pereyra
#ifndef TRANSACTIONBASKET_H
#define TRANSACTIONBASKET_H

#include "transaction.h"

#include "common.h"

const int LARGEST_SIZE = 100000;

using namespace std;

struct TransactionBasket
{
	private:
		int mSize; //size of transaction basket
		Transaction *mTransactionList = new Transaction[mSize]; //list of all transactions basket is currently holding

	public:	
		//contructors
		TransactionBasket(int newSize);
		TransactionBasket(string fileName);
		~TransactionBasket();

		//functions
		void populate(TransactionBasket otherBasket);
		void compare(CorrelationBasket correlations);

		//getters/setters
		int getSize();
		void setSize(int size);
		Transaction getTransaction(int position);
};

#endif