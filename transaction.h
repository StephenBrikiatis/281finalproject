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
    
    bool getRelevant();
    void setRelevant(bool newRelavent);

	void updateRelevant(CorrelationBasket currentBasket);
};
