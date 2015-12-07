#ifndef CORRELATION_H
#define CORRELATION_H

struct Correlation
{
	private:
		LinkedList<int> cItems;
		int occurance;
		bool relevant;

	public:
		//contructors
		Correlation();
		~Correlation();

		void add(int cItem); //add item to correlation

		//getters and setters
		int getOccurance();
		void setOccurance(int newOccurance);
		bool getRelevant();
		void setRelevant(bool newRelevant);
};

#endif