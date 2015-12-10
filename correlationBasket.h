//Stephen
#include "common.h"
#include "correlation.h"

struct CorrelationBasket 
{
private:
	Correlation* mCorrelations = new Correlation[1000]; //placeholder int
<<<<<<< HEAD
	int mMinOccurance;
=======
>>>>>>> origin/master
	int mSize;

public:
	CorrelationBasket();
	~CorrelationBasket();

	int populate(CorrelationBasket previousBasket);
	void updateOccurances(TransactionBasket currentBasket);
	void updateRelevance();

	int getSize();
	void setSize(int size);
	int getMinOccurance();
	void setMinOccurance(int size);

	Correlation getCorrelation(int choice);
};