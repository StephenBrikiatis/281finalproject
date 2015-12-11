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
	cout << "Pause for dramatic effect.";
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

	return newBasket;
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
	int itemCheck = 0;
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
	int itemCheck = 0;

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

//simple list of possible files
string listOfFiles(int input)
{
	switch (input)
	{
	case 1:
		return database[0];
		break;
	case 2:
		return database[1];
		break;
	case 3:
		return database[2];
		break;
	case 4:
		return database[3];
		break;
	case 5:
		return database[4];
		break;
	case 6:
		return database[5];
		break;
	case 7:
		return database[6];
		break;
	case 8:
		return database[7];
		break;
	case 9:
		return database[8];
		break;
	case 10:
		return database[9];
		break;
	case 11:
		return database[10];
		break;
	case 12:
		return database[11];
		break;
	case 13:
		return database[12];
		break;
	case 14:
		return database[13];
		break;
	case 15:
		return database[14];
		break;
	case 16:
		return database[15];
		break;
	case 17:
		return database[16];
		break;
	case 18:
		return database[17];
		break;
	case 19:
		return database[18];
		break;
	case 20:
		return database[19];
		break;
	case 21:
		return database[20];
		break;
	case 22:
		return database[21];
		break;
	case 23:
		return database[22];
		break;
	case 24:
		return database[23];
		break;
	case 25:
		return database[24];
		break;
	case 26:
		return database[25];
		break;
	case 27:
		return database[26];
		break;
	default:
		cout << "Not an input.";

	}

}