//Stephen
#include "common.h"
#include "correlation.h"

struct CorrelationBasket 
{
private:
	Correlation* mCorrelations = new Correlation[1000]; //placeholder int
	int mSize;

public:
	CorrelationBasket();
	CorrelationBasket(Correlation *correlations[], int size);
	~CorrelationBasket();
	int populate(CorrelationBasket previousBasket);

	int getSize();
	void setSize(int size);

	Correlation getCorrelation(int choice);
};