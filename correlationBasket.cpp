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
	int newSize =0;

	for(int i =0; i < previousBasket.getSize(); i++)
	{
		if(previousBasket.mCorrelations[i].getRelevent() == true)
		{
			newSize++;
			mCorrelations[newSize] = previousBasket.mCorrelations[i];
		}
	}

	mSize = newSize;
}

int CorrelationBasket::getSize()
{
	return mSize;
}

void CorrelationBasket::setSize(int size)
{
	mSize = size;
}