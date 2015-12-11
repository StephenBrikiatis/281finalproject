/*
Modified by:   Gabriel Pereyra
Class:         CSI-281-03
Assignment:    PA_4
Date Assigned: 10/01/2015
Due Date:      10/15/2015
Description:
Implementation for linked lists and doubly linked lists so they can be tested
for a variety of things. These things include, search, remove, and insert operations
on list of varying sizes, from 10 to 10,000. A timer then checks and calculates how long
it takes to peform certain operations and these times are outputted to a text file.

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
/* ***       Author:  Wei Kian Chen
*  Last Update:  January 14, 2014
*        Class:  CSI-281
*     Filename:  linkedList.h
*
*  Description:
*      This is the template linked list definition.
*
*  Certification of Authenticity:
*     I certify that this assignment is entirely my own work.
**********************************************************************/

#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
	template <typename R>
	struct Node
	{
		R       mData;
		Node<T> *mNext;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To initialize date object
		*************************************************************************/
		Node()
		{
			mData = R();
			mNext = NULL;
		}


		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(R data)
		{
			mData = data;
			mNext = NULL;
		}
	};


private:
	Node<T> *mHead, *mTail;
	int     mCount;

public:
	LinkedList();
	~LinkedList();

	int  getCount();
	T    getData(int index);
	void setData(int index, T data);

	void clear();
	void display();
	bool insert(T data);
	bool insertUnsorted(T data);
	bool isEmpty();
	bool isExist(T searchKey);
	bool isExistSorted(T searchKey);
	bool remove(T searchKey);
	bool removeUnsorted(T searchKey);
	T    removeAt(int index);
	bool searchFor(T searchKey);

	T operator[](int index);
	void operator=(LinkedList &rhs);
};


/*      Pre:  None
*     Post:  This object is initialized using the default
*  Purpose:  To initialize date object
*****************************************************************************/
template <typename T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


/*      Pre:  None
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
*****************************************************************************/
template <typename T>
LinkedList<T>::~LinkedList()
{
	// remove all nodes
	clear();

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;

	// reinitialize count
	mCount = 0;
}


/*      Pre:  The object is instantiated
*     Post:  The number of nodes in the linked list is returned to the caller
*  Purpose:  To retrieve the number of nodes in the list
*****************************************************************************/
template <typename T>
int LinkedList<T>::getCount()
{
	return mCount;
}


/*      Pre:  The list is instantiated and the index is valid
*     Post:  The data in the specified index is returned to the caller
*  Purpose:  To retrieve the specified nodes in the list
*****************************************************************************/
template <typename T>
T LinkedList<T>::getData(int index)
{
	int     i;
	Node<T> *tmp;

	if (index < 0 || index >= mCount)
		return T();

	tmp = mHead;
	for (i = 0; i < index; i++)
		tmp = tmp->mNext;

	return tmp->mData;
}


/*      Pre:  The list is instantiated, the index is valid and the data is
*            available
*     Post:  The data in the specified index is updated with the specified
*            data
*  Purpose:  To update the specified nodes in the list
*****************************************************************************/
template <typename T>
void LinkedList<T>::setData(int index, T data)
{
	int     i;
	Node<T> *tmp;

	if (index < 0 || index >= mCount)
		return;

	tmp = mHead;
	for (i = 0; i < index; i++)
		tmp = tmp->mNext;

	tmp->mData = data;
}



/*      Pre:  The list is initiated
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
*****************************************************************************/
template <typename T>
void LinkedList<T>::clear()
{
	while (mCount > 0)
	{
		removeAt(0);
	}

	mHead = NULL;
	mTail = NULL;
}



/*      Pre:  The list is instantiated
*     Post:  The entire list is displayed on the screen
*  Purpose:  To show the content of the list
*****************************************************************************/
template <typename T>
void LinkedList<T>::display()
{
	Node<T> *tmp;

	if (mHead == NULL)
	{
		cout << "The list is empty\n";
		return;
	}

	tmp = mHead;
	while (tmp != NULL)
	{
		cout << tmp->mData << " ";
		tmp = tmp->mNext;
	}
	cout << endl;
}


/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert a data into the list in ascending order.  However, if
*            the data already existed in the list, it will not be added again
*****************************************************************************/
template <typename T>
bool LinkedList<T>::insert(T data)
{
	Node<T> *tmp, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	if (newNode == NULL)
		return false;

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		if (data <= mHead->mData)
		{
			newNode->mNext = mHead;
			mHead = newNode;
		}
		else if (data >= mTail->mData)
		{
			mTail->mNext = newNode;
			mTail = newNode;
		}
		else
		{
			tmp = mHead;
			oneBefore = mHead;
			while (tmp->mData < data)
			{
				oneBefore = tmp;
				tmp = tmp->mNext;
			}

			if (tmp->mData != NULL)
			{
				newNode->mNext = tmp;
				oneBefore->mNext = newNode;
			}
			else
			{
				delete newNode;
				return false;
			}
		}
	}

	mCount++;

	return true;
}

/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted from the tail
*  Purpose:  To insert a data into the list from the tail
*****************************************************************************/
template <typename T>
bool LinkedList<T>::insertUnsorted(T data)
{
	Node<T> *newNode;

	newNode = new Node<T>(data);
	if (newNode == NULL)
		return false;

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
		mCount++;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
		mCount++;
	}

	return true;
}

/*      Pre:  The list is instantiated
*     Post:  The function returns true is the list is empty; false otherwise
*  Purpose:  To determine if the list is empty
*****************************************************************************/
template <typename T>
bool LinkedList<T>::isEmpty()
{
	return mHead == NULL;
}


/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  The function returns true if the search key exists in the list;
*            otherwise false
*  Purpose:  To determine if a specific value exists in the list or not
*****************************************************************************/
template <typename T>
bool LinkedList<T>::isExist(T searchKey)
{
	Node<T> *tmp;

	tmp = mHead;
	while (tmp != NULL)
	{
		if (tmp->mData == searchKey)
			return true;

		tmp = tmp->mNext;
	}

	return false;
}

/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  The function returns true if the search key exists in the list;
*            otherwise false
*  Purpose:  To determine if a specific value exists in the list or not
*****************************************************************************/
template <typename T>
bool LinkedList<T>::isExistSorted(T searchKey)
{
	Node<T> *tmp;
	if (searchKey < mHead->mData || searchKey > mTail->mData)
		return false;

	tmp = mHead;
	while (tmp != NULL)
	{
		if (tmp->mData == searchKey)
			return true;

		tmp = tmp->mNext;
	}

	return false;
}


/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  If the searchKey exists, removes it from the list and the
*            function returns true; otherwise the function does nothing
*            and returns false
*  Purpose:  To remove a specific value from the list
*****************************************************************************/
template <typename T>
bool LinkedList<T>::remove(T searchKey)
{
	Node<T> *tmp, *prev;

	if (mHead == NULL)
		return false;
	else if (searchKey < mHead->mData || searchKey > mTail->mData)
		return false;

	tmp = mHead;
	prev = NULL;
	for (int i = 0; i < mCount; i++)
	{
		if (searchKey == tmp->mData)
			break;

		prev = tmp;
		tmp = tmp->mNext;
	}

	if (tmp != NULL)
	{
		if (tmp == mHead)
		{
			tmp = mHead;

			mHead = mHead->mNext;
			if (mHead == NULL)
				mTail = NULL;

			tmp->mNext = NULL;
		}
		else if (tmp == mTail)
		{
			prev->mNext = NULL;
			mTail = prev;
		}
		else
		{
			prev->mNext = tmp->mNext;
			tmp->mNext = NULL;
		}

		delete tmp;
		mCount--;

		return true;
	}

	return false;
}

/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  If the searchKey exists, removes it from the unsorted list and the
*            function returns true; otherwise the function does nothing
*            and returns false
*  Purpose:  To remove a specific value from the unsorted list
*****************************************************************************/
template <typename T>
bool LinkedList<T>::removeUnsorted(T searchKey)
{
	Node<T> *tmp, *prev;

	if (mHead == NULL)
		return false;

	tmp = mHead;
	prev = NULL;
	for (int i = 0; i < mCount; i++)
	{
		if (searchKey == tmp->mData)
			break;

		prev = tmp;
		tmp = tmp->mNext;
	}

	if (tmp != NULL)
	{
		if (tmp == mHead)
		{
			tmp = mHead;

			mHead = mHead->mNext;
			if (mHead == NULL)
				mTail = NULL;

			tmp->mNext = NULL;
		}
		else if (tmp == mTail)
		{
			prev->mNext = NULL;
			mTail = prev;
		}
		else
		{
			prev->mNext = tmp->mNext;
			tmp->mNext = NULL;
		}

		delete tmp;
		mCount--;

		return true;
	}

	return false;
}

/*      Pre:  The list is instantiated and the index is valid
*     Post:  Remove the element in the specified index location and returns
*            its content to the caller.  If the index location is invalid, the
*            function returns the default value
*  Purpose:  To remove an item in the specified index location
*****************************************************************************/
template <typename T>
T LinkedList<T>::removeAt(int index)
{
	T data = T();
	Node<T> *tmp = mHead;
	Node<T> *previous = NULL;

	if (index >= 0 && index < mCount)
	{
		tmp = mHead;
		for (int i = 0; i < index; i++)
		{
			previous = tmp;
			tmp = tmp->mNext;
		}

		if (tmp == mHead)
		{
			tmp = mHead;
			mHead = mHead->mNext;

			if (mCount == 1)
				mTail = NULL;
		}
		else if (tmp == mTail)
		{
			previous->mNext = NULL;
			mTail = previous;
		}
		else
			previous->mNext = tmp->mNext;

		data = tmp->mData;
		tmp->mNext = NULL;
		delete tmp;
		mCount--;
	}

	return data;
}

/*      Pre:  A search key is provided
*     Post:  True is returned if the element is found, false if it isn't
*  Purpose:  To check if a value exists in the list
*****************************************************************************/
template <typename T>
bool LinkedList<T>::searchFor(T searchKey)
{
	Node<T> *tmp = mHead;

	for (int i = 0; i < mCount; i++)
	{
		if (tmp->mData == searchKey)
			return true;
		else
			tmp = tmp->mNext;
	}

	return false;
}


/*      Pre:  The list is instantiated and the index is valid
*     Post:  The data in the specified index is returned to the caller
*  Purpose:  To retrieve the specified nodes in the list using [] operator
*****************************************************************************/
template <typename T>
T LinkedList<T>::operator[](int index)
{
	return getData(index);
}

template <typename T>
void LinkedList<T>::operator=(LinkedList &rhs)
{
	int size = rhs.getCount();
	clear();

	for (int i = 0; i < size; i++)
	{
		insert(rhs.getData(i));
	}
}

#endif