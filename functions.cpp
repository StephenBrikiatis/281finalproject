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

//outputs current correlation and their occurances to the output file
void printCorrelations(CorrelationBasket currentBasket, ofstream output)
{
	int correlationNum = 1;

	for (int i = 0; i < currentBasket.getSize(); i++)
	{
		output << correlationNum << " [";
		for (int j = 0; j < currentBasket.getCorrelation(i).getSize(); j++)
		{
			output << " " << currentBasket.getCorrelation(i).getItem(j);
		}
		output << "] Occurance: ";
		output << currentBasket.getCorrelation(i).getOccurance() << "  ";
	}

	output << endl << endl;
}

CorrelationBasket createBasket(CorrelationBasket currentBasket, int comboLength)
{
	LinkedList<int> numbers;
	CorrelationBasket newBasket;
	Correlation holder, resetHolder;
	int numbersLength, r = 0, index = 0, coreCount = 0;

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
			holder.add(numbers.getData(index));

			if(r == comboLength-1)
			{
				newBasket.setCorrelation(holder, coreCount);
				holder = resetHolder;
				coreCount++;
				index++;
			}
			else
			{
				index = (holder.getItem(r) + 1);
			}
		}
		else
		{
			r--;
			if(r > 0)
			{
				index = (holder.getItem(r) +1);
			}
			else
			{
				index = (holder.getItem(0) +1);
			}
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
		if(tmp.getRelevant())
		{
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
	}

	return listOfNums;
}