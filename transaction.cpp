//Stpehen
#include "transaction.h"

Transaction::Transaction()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		tItems[i] = -1;
	}
	mSize = 0;
	mRelevant = false;
}

Transaction::Transaction(LinkedList<int> newList, bool relevent)
{
	mRelevant = relevent;
}

Transaction::~Transaction()
{

}

void Transaction::addItem(int item)
{
	tItems[mSize] = item;
	mSize++;
}

bool Transaction::checkIfExists(int item)
{
	for (int i = 0; i < mSize; i++)
	{
		if (tItems[i] == item)
		{
			return true;
		}
	}

	return false;
}

bool Transaction::getRelevant()
{
	return mRelevant;
}

void Transaction::setRelevant(bool relevent)
{
	mRelevant = relevent;
}

int Transaction::getSize()
{
	return mSize;
}

void Transaction::setSize(int size)
{
	mSize = size;
}

int Transaction::getItem(int position)
{
	return tItems[position];
}

void Transaction::clear()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		tItems[i] = 0;
	}
}

//= operator overload 
void Transaction::operator= (Transaction& rhs)
{
	clear();
	for (int i = 0; i < rhs.getSize(); i++)
	{
		tItems[i] = rhs.getItem(i);
	}
	mRelevant = rhs.getRelevant();
	mSize = rhs.getSize();
}