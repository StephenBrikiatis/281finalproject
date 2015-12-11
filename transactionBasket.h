//By Gabriel Pereyra
#ifndef TRANSACTIONBASKET_H
#define TRANSACTIONBASKET_H

const int LARGEST_SIZE = 100000;

#include "transaction.h"

struct TransactionBasket
{
	private:
		int mSize; //size of transaction basket
		Transaction *mTransactionList = new Transaction[mSize]; //list of all transactions basket is currently holding

	public:	
		//contructors
		TransactionBasket();
		TransactionBasket(int newSize);
		TransactionBasket(string fileName);
		~TransactionBasket();

		//functions
		void populate(TransactionBasket otherBasket);

		//getters/setters
		int getSize();
		void setSize(int size);

		Transaction getTransaction(int position);
		void setTransaction(Transaction &newTrans, int choice);
};

#endif