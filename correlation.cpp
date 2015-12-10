//By Gabriel Pereyra
#include "correlation.h"

//constructor and destructor
Correlation::Correlation()
{
	mOccurance = 0;
	mRelevant = true;
}
Correlation::~Correlation()
{
	cItems.clear();
	mOccurance = NULL;
	mRelevant = NULL;
}

//adds item to the correlation
void Correlation::add(int cItem)
{
	cItems.insert(cItem);
}

//goes through all transactions to see how many times a correlation occurs, by Gabe
void Correlation::checkOccurance(TransactionBasket currentBasket)
{
	Transaction tmpTransaction;
	int itemCheck;
	bool correlationFound;

	//go through every transaction
	for (int i = 0; i < currentBasket.getSize(); i++)
	{
		tmpTransaction = currentBasket.getTransaction(i);
		correlationFound = true;

		//accessing every number in Correlation
		for (int j = 0; getSize(); j++)
		{
			if (!tmpTransaction.checkIfExists(getItem(j)))
			{
				correlationFound = false;
			}
		}

		//update occurance accordingly
		if (correlationFound)
		{
			mOccurance++;
		}
	}
}

//getters and setters for occurance
int Correlation::getOccurance()
{
	return mOccurance;
}
void Correlation::setOccurance(int newOccurance)
{
	mOccurance = newOccurance;
}

//getters and setters for relevance
bool Correlation::getRelevant()
{
	return mRelevant;
}
void Correlation::setRelevant(bool newRelevant)
{
	mRelevant = newRelevant;
}

//getters and setters for the size member
int Correlation::getSize()
{
	return cItems.getCount();
}

//get specific item from linked list
int Correlation::getItem(int position)
{
	return cItems.getData(position);
}