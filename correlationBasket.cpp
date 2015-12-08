//Stephen
#include "correlationBasket.h"

CorrelationBasket::CorrelationBasket()
{
	mSize = 0;
	for(int i =0; i < 10; i++)
	{
		mCorrelations[i] = new Correlation;
	}
}

CorrelationBasket::CorrelationBasket(Correlation *correlations[], int size)
{
	mSize = size;

	for(int i = 0; i < mSize; i++)
	{
		mCorrelations[i] = correlations[i];
	}
}

int CorrelationBasket::populate(CorrelationBasket previousBasket)
{
	for(int i =0; i < mSize; i++)
	{
		if(previousBasket.mCorrelations[i].relavent == true)
		{

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