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

bool Transaction::getRelevant()
{
	return mRelevant;
}

void Transaction::setRelevant(bool relevent)
{
	mRelevant = relevent;
}

void Transaction::updateRelevant(CorrelationBasket currentBasket)
{
	/*int correlationSize =0;
	Correlation tmpCore;
	LinkedList<int> tmpList;
	for(int i = 0; i < currentBasket.getSize(); i++)
	{
		tmpCore = currentBasket.getCorrelation[i];
		if(tmpCore.getRelevant() == true)
		{
			tmpCore.cItems.getCount();
			for(int j = 0; j < tItems.getCount(); j++)
			{
				
			}
		}
	}*/

	Correlation tmpCorr;
	LinkedList<int> tmpList;
	bool isRelavent = false;
	int itemCheck;

	//loop accessing correlations in basket
	for (int i = 0; i < currentBasket.getSize(); i++)
	{
		tmpCorr = currentBasket.getCorrelation(i);

		bool itemsFound = true;
		//loop accessing numbers in correlation
		for (int j = 0; j < tmpCorr.getSize(); j++)
		{
			itemCheck = tmpCorr.getItem(j);
			
			//checks if item exists in transaction
			if (!tItems.isExist(itemCheck))
			{
				itemsFound = false;
				break;
			}
		}

		//breaks loop if a correlation is found in a transaction
		if (itemsFound == true)
		{
			isRelavent = true;
			break;
		}
	}

	//updates relavence
	setRelevant(isRelavent);
}