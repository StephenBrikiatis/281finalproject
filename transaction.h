//Stephen
#include "common.h"

struct Transaction
{
  private:
    LinkedList<int> tItems;
    bool mRelevant;
  public:
    Transaction();
    Transaction(LinkedList<int> tItems, bool relevant);
    ~Transaction();
    
    void addItem(int item);
    
    bool getRelavent();
    void setRelavent(bool newRelavent);
};
