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
    
    bool getRelavent();
    void setRelavent(bool newRelavent);

	void updateRelavent(CorrelationBasket currentBasket);
};
