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
	return cItems.getData(position);
}