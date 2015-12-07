#ifndef TRANSACTIONBASKET_H
#define TRANSACTIONBASKET_H

#include <string>

using namespace std;

struct TransactionBasket
{
	private:
		Transaction* transactionList[100]; //list of all transactions basket is currently holding
		int size; //size of transaction basket

	public:
		//contructors
		TransactionBasket();
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