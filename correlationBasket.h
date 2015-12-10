//Stephen
#ifndef CORRELATIONBASKET_H
#define CORRELATIONBASKET_H
#include "common.h"
#include "correlation.h"


struct CorrelationBasket 
{
private:
	Correlation* mCorrelations = new Correlation[1000]; //placeholder int
	int mMinOccurance;
	int mSize;

public:
	CorrelationBasket();
	~CorrelationBasket();

	void updateOccurances(TransactionBasket currentBasket);
	void updateRelevance();

	int getSize();
	void setSize(int size);
	int getMinOccurance();
	void setMinOccurance(int size);

	Correlation getCorrelation(int choice);

	void setCorrelation(Correlation newCorrelation, int choice);
};

#endif