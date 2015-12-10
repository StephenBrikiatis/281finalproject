//By Gabriel Pereyra
#ifndef CORRELATION_H
#define CORRELATION_H

#include "common.h"

struct Correlation
{
	private:
		LinkedList<int> cItems;
		int mOccurance;
		bool mRelevant;

	public:
		//contructors
		Correlation();
		~Correlation();

		void add(int cItem); //add item to correlation
		void checkOccurance(TransactionBasket currentBasket);

		//getters and setters
		int getOccurance();
		void setOccurance(int newOccurance);
		bool getRelevant();
		void setRelevant(bool newRelevant);
		int getSize();

		int getItem(int position);
};

#endif