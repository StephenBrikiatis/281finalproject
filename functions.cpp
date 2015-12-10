#include "Header.h"

//checks user input to see if it matches a file on database
bool checkUserInput(string input)
{
	bool validate = false;

	for (int i = 0; i < DATABASE_SIZE; i++)
	{
		if (input == database[i])
		{
			validate = true;
			break;
		}
	}

	return validate;
}

CorrelationBasket createBasket(CorrelationBasket currentBasket, int comboLength)
{
	LinkedList<int> numbers;
	CorrelationBasket newBasket;
	int numbersLength, r = 0, index = 0;

	numbers = createListOfNums(currentBasket);
	numbersLength = numbers.getCount();

	if(comboLength > numbersLength)
	{
		cout << "Can't make a combination with that few numbers" << endl;
		return;
	}

	while(r >= 0)
	{
		if(index <= (numbersLength +(r -comboLength)))
		{
			newBasket.
		}
	}
}

LinkedList<int> createListOfNums(CorrelationBasket currentBasket)
{
	LinkedList<int> listOfNums;
	int basketSize = 0, correSize = 0, compare;
	Correlation tmp;
	bool exists = false;

	basketSize = currentBasket.getSize();
	tmp = currentBasket.getCorrelation(0);
	correSize = tmp.getSize();

	for(int i = 0; i < basketSize; i++)
	{
		tmp = currentBasket.getCorrelation(i);
		if(tmp.getRelevant(
		for(int j = 0; j < correSize; j++)
		{
			compare = tmp.getItem(j);
			for(int k = 0; k < listOfNums.getCount(); k++)
			{
				listOfNums.getData(k);
			}
			listOfNums.insert(compare);
		}
	}

	return listOfNums;
}