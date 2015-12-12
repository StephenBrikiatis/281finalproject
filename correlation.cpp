//By Gabriel Pereyra
#include "correlation.h"

//constructor and destructor
Correlation::Correlation()
{
	mOccurance = 0;
	mRelevant = true;
	mSize = 0;
}
Correlation::~Correlation()
{
	for (int i = 0; i < 50; i++)
	{
		cItems[i] = 0;
	}
	mOccurance = NULL;
	mRelevant = NULL;
}

//adds item to the correlation
void Correlation::add(int cItem, int position)
{
	cItems[position] = cItem;
	mSize++;
}

void Correlation::addItem(int item)
{
	cItems[mSize] = item;
	mSize++;
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
	return mSize;
}

void Correlation::setSize(int size)
{
	mSize = size;
}

//get specific item from linked list
int Correlation::getItem(int position)
{
	return cItems[position];
}

void::Correlation::clear()
{
	for (int i = 0; i < 50; i++)
	{
		cItems[i] = 0;
	}
	mOccurance = 0;
	mSize = 0;
	mRelevant = false;
}

//= operator overload 
void Correlation::operator= (Correlation& rhs)
{
	clear();
	for (int i = 0; i < 50; i++)
	{
		cItems[i] = rhs.getItem(i);
	}
	rhs.setOccurance(mOccurance);
	rhs.setRelevant(mRelevant);
}