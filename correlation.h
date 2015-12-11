//By Gabriel Pereyra
#ifndef CORRELATION_H
#define CORRELATION_H

#include "common.h"

struct Correlation
{
private:
	int cItems[50];
	int mOccurance;
	bool mRelevant;
	int mSize;

public:
	//contructors
	Correlation();
	~Correlation();

	void add(int cItem, int position); //add item to correlation

	//getters and setters
	int getOccurance();
	void setOccurance(int newOccurance);
	bool getRelevant();
	void setRelevant(bool newRelevant);
	int getSize();
	void setSize(int size);

	int getItem(int position);
	void clear();

	//operator overloads

	void operator=(Correlation& rhs);
};
#endif