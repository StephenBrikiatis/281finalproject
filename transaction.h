//Stephen
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "common.h"

struct Transaction
{
  private:
    LinkedList<int> tItems;
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
	int getItem(int position);

	void operator=(Transaction& rhs);
};

#endif