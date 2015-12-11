//Stpehen
#include "transaction.h"

Transaction::Transaction()
{
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
	tItems.insert(item);
}

bool Transaction::checkIfExists(int item)
{
	return tItems.isExist(item);
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
	return tItems.getCount();
}

int Transaction::getItem(int position)
{
	return tItems.getData(position);
}

//= operator overload 
void Transaction::operator= (Transaction& rhs)
{
	tItems.clear();
	for (int i = 0; i < rhs.getSize(); i++)
	{
		tItems.insert(rhs.getItem(i));
	}
	rhs.setRelevant(mRelevant);
}
