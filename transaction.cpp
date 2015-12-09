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

void Transaction::updateRelavent(CorrelationBasket currentBasket)
{
	int correlationSize =0;
	Correlation tmpCore;
	LinkedList<int> tmpList;
	for(int i = 0; i < currentBasket.getSize(); i++)
	{
		tmpCore = currentBasket.getCorrelation[i];
		tmpList = 
			for(int k = 0; k < tItems.getCount(); k++)
			{
			
			}
		}
	}
}