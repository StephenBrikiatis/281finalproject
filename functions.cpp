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

void createBasket(CorrelationBasket currentBasket, int comboLength)
{
	LinkedList<int> numbers;
	int numbersLength;

	numbers = createListOfNums(currentBasket);
	numbersLength = numbers.getCount();

	if(comboLength > numbersLength)
	{
		cout << "Can't make a combination with that few numbers" << endl;
		return;
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