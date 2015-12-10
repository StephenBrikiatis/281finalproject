//Stephen
#include "correlationBasket.h"

CorrelationBasket::CorrelationBasket()
{
	mSize = 0;
	mMinOccurance = 0;
}

//goes through all correlations and updates their relevance by Gabe
void CorrelationBasket::updateRelevance()
{
	for (int i = 0; i < mSize; i++)
	{
		if (mCorrelations[i].getOccurance < mMinOccurance)
		{
			mCorrelations[i].setRelevant(false);
		}
	}
}

int CorrelationBasket::getSize()
{
	return mSize;
}

void CorrelationBasket::setSize(int size)
{
	mSize = size;
}

int CorrelationBasket::getMinOccurance()
{
	return mMinOccurance;
}

void CorrelationBasket::setMinOccurance(int occurance)
{
	mMinOccurance = occurance;
}

Correlation CorrelationBasket::getCorrelation(int choice)
{
	return mCorrelations[choice];
}

void CorrelationBasket::setCorrelation(Correlation newCore, int choice)
{
	mCorrelations[choice] = newCore;
}