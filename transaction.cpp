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

bool Transaction::getRelavent()
{
	return mRelevant;
}

void Transaction::setRelavent(bool relevent)
{
	mRelevant = relevent;
}

void Transaction::updateRelevnet(CorrelationBasket currentBasket)
{

}