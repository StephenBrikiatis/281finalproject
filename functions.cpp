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
		return newBasket;
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

//function that begins counting all occurances of correlations
void updateOccurances(CorrelationBasket currentCorrelations, TransactionBasket currentTransactions)
{
	for (int i = 0; i < currentCorrelations.getSize(); i++)
	{
		checkOccurance(currentCorrelations.getCorrelation(i), currentTransactions);
	}
}

//goes through all transactions to see how many times a correlation occurs, by Gabe
void checkOccurance(Correlation currentCorrelation, TransactionBasket currentTransactions)
{
	Transaction tmpTransaction;
	int itemCheck;
	bool correlationFound;

	//go through every transaction
	for (int i = 0; i < currentTransactions.getSize(); i++)
	{
		tmpTransaction = currentTransactions.getTransaction(i);
		correlationFound = true;

		//accessing every number in Correlation
		for (int j = 0; currentCorrelation.getSize(); j++)
		{
			if (!tmpTransaction.checkIfExists(currentCorrelation.getItem(j)))
			{
				correlationFound = false;
			}
		}

		//update occurance accordingly
		if (correlationFound)
		{
			currentCorrelation.setOccurance(currentCorrelation.getOccurance() + 1);
		}
	}
}

//compares current item sets to relevant correlations to determine which transactions are relevant or not
void compare(TransactionBasket currentTransactions, CorrelationBasket currentCorrelations)
{
	for (int i = 0; i < currentTransactions.getSize(); i++)
	{
		updateRelevant(currentTransactions.getTransaction(i), currentCorrelations);
	}
}

void updateRelevant(Transaction currentTransaction, CorrelationBasket currentCorrelations)
{
	Correlation tmpCorr;
	bool isRelavent = false;
	int itemCheck;

	//loop accessing correlations in basket
	for (int i = 0; i < currentCorrelations.getSize(); i++)
	{
		tmpCorr = currentCorrelations.getCorrelation(i);

		bool itemsFound = true;
		//loop accessing numbers in correlation
		for (int j = 0; j < tmpCorr.getSize(); j++)
		{
			itemCheck = tmpCorr.getItem(j);

			//checks if item exists in transaction
			if (currentTransaction.checkIfExists(itemCheck))
			{
				itemsFound = false;
				break;
			}
		}

		//breaks loop if a correlation is found in a transaction
		if (itemsFound == true)
		{
			isRelavent = true;
			break;
		}
	}

	//updates relavence
	currentTransaction.setRelevant(isRelavent);
}