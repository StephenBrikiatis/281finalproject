//By Gabriel Pereyra

#include "transactionBasket.h"

TransactionBasket::TransactionBasket()
{
	mSize = 0;
	Transaction *transactionList = new Transaction[mSize];
}

TransactionBasket::TransactionBasket(int newSize)
{
	mSize = newSize;
	Transaction *transactionList = new Transaction[mSize];
}

TransactionBasket::~TransactionBasket()
{
	/*mSize = NULL;
	delete[] mTransactionList;*/
}

//opens file and populates initial transactions
void TransactionBasket::populateWithFile(string fileName)
{
	//tmp variables for storing the data
	int transNum;
	int tmpItem;
	int tmpSize = 0;

	mSize = LARGEST_SIZE; //default largest data size
	Transaction *transactionList = new Transaction[mSize];

	ifstream data;
	data.open(fileName);

	while (!data.eof())
	{
		data >> transNum;
		data >> tmpItem;

		transactionList[transNum - 1].addItem(tmpItem); //-1 cause array positioning

		if (tmpSize != transNum)
			tmpSize++;
	}

	data.close();

	mSize = tmpSize;
}

//populates a new basket with the relevant transactions from the previous basket
void TransactionBasket::populate(TransactionBasket otherBasket)
{
	Transaction *tmpList = new Transaction[mSize]; //tmp list to copy relevant transactions
	int tmpSize = 0; //keeps track of new transactions to determine new size

	//fill temp list
	for (int i = 0; i < mSize; i++)
	{
		if (otherBasket.getTransaction(i).getRelevant() == true)
		{
			tmpList[tmpSize] = otherBasket.getTransaction(i);
			tmpSize++;
		}
	}

	//populate actual list
	for (int j = 0; j < tmpSize; j++)
	{
		mTransactionList[j] = tmpList[j];
	}

	mSize = tmpSize;
}

//getters and setters for the size member
int TransactionBasket::getSize()
{
	return mSize;
}
void TransactionBasket::setSize(int size)
{
	mSize = size;
}

//getter for accessing specific transactions
Transaction& TransactionBasket::getTransaction(int position)
{
	return mTransactionList[position];
}

void TransactionBasket::setTransaction(Transaction &newTrans, int choice)
{
	mTransactionList[choice] = newTrans;
}