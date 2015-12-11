//Stephen
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "common.h"

const int ARRAY_SIZE = 50;

struct Transaction
{
  private:
	int tItems[ARRAY_SIZE];
	int mSize;
    bool mRelevant;

  public:
    Transaction();
    Transaction(LinkedList<int> newList, bool relevant);
    ~Transaction();
    
    void addItem(int item);
	bool checkIfExists(int item);
    
    bool getRelevant();
    void setRelevant(bool newRelevant);
	int getSize();
	void setSize(int size);
	int getItem(int position);
	void clear();

	void operator=(Transaction& rhs);
};

#endif