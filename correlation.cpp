#include "correlation.h"

Correlation::Correlation()
{
	mOccurance = 0;
	mRelevant = false;
}

Correlation::Correlation()
{

}

void Correlation::add(int cItem)
{
	cItems.insert(cItem);
}

int Correlation::get