//By Gabriel Pereyra

#include "transactionBasket.h"

TransactionBasket::TransactionBasket(int newSize)
{
	size = newSize;
	Transaction *transactionList = new Transaction[size];
}

TransactionBasket::TransactionBasket(string fileName)
{
	//tmp variables for storing the data
	int transNum;
	int tmpItem;

	size = LARGEST_SIZE; //default largest data size
	Transaction *transactionList = new Transaction[size];

	ifstream data;
	data.open(fileName);

	if (data.good())
	{
		while (!data.eof())
		{
			data >> transNum;
			data >> tmpItem;

			transactionList[transNum - 1].addItem(tmpItem); //-1 cause array positioning
		}
	}
}

TransactionBasket::~TransactionBasket()
{
	size = NULL;
	delete transactionList;
}

//populates a new basket with the relevant transactions from the previous basket
void TransactionBasket::populate(TransactionBasket otherBasket)
{
	Transaction *tmpList = new Transaction[size]; //tmp list to copy relevant transactions
	int tmpSize = 0; //keeps track of new transactions to determine new size

	//fill temp list
	for (int i = 0; i < size; i++)
	{
		if (otherBasket.getTransaction(i).getRelavent() == true)
		{
			tmpList[tmpSize] = otherBasket.getTransaction(i);
			tmpSize++;
		}
	}

	//populate actual list
	for (int j = 0; j < tmpSize; j++)
	{
		getTransaction(j) = tmpList[j];
	}
}