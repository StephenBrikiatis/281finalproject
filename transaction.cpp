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
#include "transaction.h"

/*  Author:  Stephen Brikiatis
*	   Pre:  None
*     Post:  Transaction constructed or destructed
*  Purpose:  To construct or destruct a transaction
*************************************************************************/
Transaction::Transaction()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		tItems[i] = -1;
	}
	mSize = 0;
	mRelevant = false;
}
Transaction::~Transaction()
{

}

/*  Author:  Stephen Brikiatis
*	   Pre:  None
*     Post:  An item is added to tItems, and size is incremented accordingly
*  Purpose:  To add an item to tItems
*************************************************************************/
void Transaction::addItem(int item)
{
	tItems[mSize] = item;
	mSize++;
}

/*  Author:  Stephen Brikiatis
*	   Pre:  None
*     Post:  Returns true if item exists in tItems, false if not
*  Purpose:  To determine whether an item exists in tItems
*************************************************************************/
bool Transaction::checkIfExists(int item)
{
	for (int i = 0; i < mSize; i++)
	{
		if (tItems[i] == item)
		{
			return true;
		}
	}

	return false;
}

/*  Author:  Stephen Brikiatis
*	   Pre:  None
*     Post:  Transaction items are cleared
*  Purpose:  To clear transaction items
*************************************************************************/
void Transaction::clear()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		tItems[i] = 0;
	}
}

/*  Author:  Stephen Brikiatis
*	   Pre:  Item must exist in the tItems
*     Post:  Requested item at position is returned
*  Purpose:  To access items from private member titems
*************************************************************************/
int Transaction::getItem(int position)
{
	return tItems[position];
}

/*  Author:  Stephen Brikiatis
*	   Pre:  None
*     Post:  Data is modified or accessed accordingly
*  Purpose:  Getters and setters for private bool relevance
*************************************************************************/
bool Transaction::getRelevant()
{
	return mRelevant;
}
void Transaction::setRelevant(bool relevent)
{
	mRelevant = relevent;
}

/*  Author:  Stephen Brikiatis
*	   Pre:  None
*     Post:  Data is modified or accessed accordingly
*  Purpose:  Getters and setters for private int size
*************************************************************************/
int Transaction::getSize()
{
	return mSize;
}
void Transaction::setSize(int size)
{
	mSize = size;
}

/*  Author:  Stephen Brikiatis
*	   Pre:  = operator is called
*     Post:  Every member from the rhs operator is transferred to lhs
*  Purpose:  To make = can be called on transaction objects accurately
*************************************************************************/
void Transaction::operator= (Transaction& rhs)
{
	clear();
	for (int i = 0; i < rhs.getSize(); i++)
	{
		tItems[i] = rhs.getItem(i);
	}
	mRelevant = rhs.getRelevant();
	mSize = rhs.getSize();
}