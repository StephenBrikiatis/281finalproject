//Stephen
#include "correlationBasket.h"

CorrelationBasket::CorrelationBasket()
{
	mSize = 0;
	mMinOccurance = 0;
}

CorrelationBasket::CorrelationBasket(int newSize)
{
	mSize = newSize;
	Correlation *mCorrelations = new Correlation[mSize];
}

CorrelationBasket::~CorrelationBasket()
{

}

//populates a new basket with the relevant correlations from the previous basket
void CorrelationBasket::populate (CorrelationBasket otherBasket)
{
	Correlation *tmpList = new Correlation[mSize]; //tmp list to copy relevant transactions
	int tmpSize = 0; //keeps track of new transactions to determine new size

	//fill temp list
	for (int i = 0; i < mSize; i++)
	{
		if (otherBasket.getCorrelation(i).getRelevant() == true)
		{
			tmpList[tmpSize] = otherBasket.getCorrelation(i);
			tmpSize++;
		}
	}

	//populate actual list
	for (int j = 0; j < tmpSize; j++)
	{
		mCorrelations[j] = tmpList[j];
	}

	mSize = tmpSize;
}

//goes through all correlations and updates their relevance by Gabe
void CorrelationBasket::updateRelevance()
{
	for (int i = 0; i < mSize; i++)
	{
		if (mCorrelations[i].getOccurance() < mMinOccurance)
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

Correlation& CorrelationBasket::getCorrelation(int choice)
{
	return mCorrelations[choice];
}

void CorrelationBasket::setCorrelation(Correlation &newCore, int choice)
{
	mCorrelations[choice] = newCore;
	mSize++;
}

void CorrelationBasket::operator= (CorrelationBasket &rhs)
{
	mMinOccurance = rhs.getMinOccurance();
	mSize = rhs.getSize();
	for (int i = 0; i < mSize; i++)
	{
		mCorrelations[i] = rhs.getCorrelation(i);
	}
}