/*
Modified by:   Gabriel Pereyra and Stephen Brikiatis
Class:         CSI-281-03
Assignment:    Final Project
Date Assigned: 12/12/2015
Due Date:      11/16/2015
Description:
An implementaion for Apriori. Reads a file and finds correlations within the data
and then outputs that data to a text file. This system also times the data extraction
and is open to variable minimum thresholds.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/
#include "correlation.h"

/*  Author:  Gabriel Pereyra
*	   Pre:  None
*     Post:  Correlation constructed or destructed
*  Purpose:  To construct or destruct a correlation
*************************************************************************/
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

/*  Author:  Stephen Brikiatis
*	   Pre:  None
*     Post:  An item is added to cItems at the specified position
*  Purpose:  To add an item to cItems at the specified position
*************************************************************************/
void Correlation::add(int cItem, int position)
{
	cItems[position] = cItem;
	mSize++;
}

/*  Author:  Gabriel Pereyra
*	   Pre:  None
*     Post:  An item is added to cItems, and size is incremented accordingly
*  Purpose:  To add an item to cItems
*************************************************************************/
void Correlation::addItem(int item)
{
	cItems[mSize] = item;
	mSize++;
}

/*  Author:  Stephen Brikiatis
*	   Pre:  None
*     Post:  Every member is cleared
*  Purpose:  To clear a correlation object
*************************************************************************/
void::Correlation::clear()
{
	for (int i = 0; i < 50; i++)
	{
		cItems[i] = NULL;
	}
	mOccurance = 0;
	mSize = 0;
	mRelevant = true;
}

/*  Author:  Gabriel Pereyra
*	   Pre:  Item must exist in the cItems
*     Post:  Requested item at position is returned
*  Purpose:  To access items from private member citems
*************************************************************************/
int Correlation::getItem(int position)
{
	return cItems[position];
}

/*  Author:  Gabriel Pereyra
*	   Pre:  None
*     Post:  Data is modified or accessed accordingly
*  Purpose:  Getters and setters for private int occurance
*************************************************************************/
int Correlation::getOccurance()
{
	return mOccurance;
}
void Correlation::setOccurance(int newOccurance)
{
	mOccurance = newOccurance;
}

/*  Author:  Gabriel Pereyra
*	   Pre:  None
*     Post:  Data is modified or accessed accordingly
*  Purpose:  Getters and setters for private bool relevance
*************************************************************************/
bool Correlation::getRelevant()
{
	return mRelevant;
}
void Correlation::setRelevant(bool newRelevant)
{
	mRelevant = newRelevant;
}

/*  Author:  Gabriel Pereyra
*	   Pre:  None
*     Post:  Data is modified or accessed accordingly
*  Purpose:  Getters and setters for private int size
*************************************************************************/
int Correlation::getSize()
{
	return mSize;
}
void Correlation::setSize(int size)
{
	mSize = size;
}

/*  Author:  Stephen Brikiatis
*	   Pre:  = operator is called
*     Post:  Every member from the rhs operator is transferred to lhs
*  Purpose:  To make = can be called on correlation objects accurately
*************************************************************************/
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