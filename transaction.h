//Stephen
#include "common.h"
#include "LinkedList.h"

struct Transaction
{
  private:
    LinkedList tItems;
    bool relevant;
  public:
    Transaction();
    Transaction(Linkedlist tItems, bool relevant
    ~Transaction();
    
    void addItem(int item);
    
    bool getRelavent();
    void setRelavent(bool newRelavent);
};
