//Stephen
#include "common.h"
#include "correlationBasket.h"

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

	void updateRelevant(CorrelationBasket currentBasket);
};
