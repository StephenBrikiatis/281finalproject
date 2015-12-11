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
void printCorrelations(Correlation currentBasket[], int size, ofstream output)
{
	int correlationNum = 1;

	for (int i = 0; i < size; i++)
	{
		output << correlationNum << " [";
		for (int j = 0; j < currentBasket[i].getSize(); j++)
		{
			output << " " << currentBasket[i].getItem(j);
		}
		output << "] Occurance: ";
		output << currentBasket[i].getOccurance() << "  ";
	}

	output << endl << endl;
}

//CorrelationBasket createBasket(CorrelationBasket currentBasket, int comboLength)
//{
//	LinkedList<int> numbers;
//	CorrelationBasket newBasket;
//	Correlation holder, resetHolder;
//	int numbersLength, r = 0, index = 0, coreCount = 0;
//
//	numbers = createListOfNums(currentBasket);
//	cout << "Pause for dramatic effect.";
//	numbersLength = numbers.getCount();
//
//	if(comboLength > numbersLength)
//	{
//		cout << "Can't make a combination with that few numbers" << endl;
//		return newBasket;
//	}
//
//	while(r >= 0)
//	{
//		if(index <= (numbersLength +(r -comboLength)))
//		{
//			holder.add(numbers.getData(index));
//
//			if(r == comboLength-1)
//			{
//				newBasket.setCorrelation(holder, coreCount);
//				holder = resetHolder;
//				coreCount++;
//				index++;
//			}
//			else
//			{
//				index = (holder.getItem(r) + 1);
//			}
//		}
//		else
//		{
//			r--;
//			if(r > 0)
//			{
//				index = (holder.getItem(r) +1);
//			}
//			else
//			{
//				index = (holder.getItem(0) +1);
//			}
//		}
//	}
//
//	return newBasket;
//}
//
//LinkedList<int> createListOfNums(CorrelationBasket currentBasket)
//{
//	LinkedList<int> listOfNums;
//	int basketSize = 0, correSize = 0, compare;
//	Correlation tmp;
//	bool exists = false;
//
//	basketSize = currentBasket.getSize();
//	tmp = currentBasket.getCorrelation(0);
//	correSize = tmp.getSize();
//
//	for(int i = 0; i < basketSize; i++)
//	{
//		tmp = currentBasket.getCorrelation(i);
//		if(tmp.getRelevant())
//		{
//			for(int j = 0; j < correSize; j++)
//			{
//				compare = tmp.getItem(j);
//				for(int k = 0; k < listOfNums.getCount(); k++)
//				{
//					listOfNums.getData(k);
//				}
//				listOfNums.insert(compare);
//			}
//		}
//	}
//
//	return listOfNums;
//}

//opens file and populates initial transactions
int populateWithFile(Transaction transactions[], string fileName)
{
	//tmp variables for storing the data
	int transNum;
	int tmpItem;
	int tmpSize = 0; //size of array

	ifstream data;
	data.open(fileName);

	while (!data.eof())
	{
		data >> transNum;
		data >> tmpItem;

		transactions[transNum - 1].addItem(tmpItem); //-1 cause array positioning
		transactions[transNum - 1].setSize(transactions[transNum - 1].getSize() + 1); //add to transaction's size
			
		if (tmpSize != transNum)
		{
			tmpSize++;
		}
	}

	data.close();

	return tmpSize;
}

//function that begins counting all occurances of correlations
void updateOccurances(Correlation currentCorrelations[], int correlationSize, Transaction currentTransactions[], int transactionSize)
{
	for (int i = 0; i < correlationSize; i++)
	{
		checkOccurance(currentCorrelations[i], currentTransactions, transactionSize);
	}
}

//goes through all transactions to see how many times a correlation occurs, by Gabe
void checkOccurance(Correlation currentCorrelation, Transaction currentTransactions[], int transactionSize)
{
	bool check = false;

	for (int i = 0; i < transactionSize; i++)
	{
		for (int j = 0; j < currentCorrelation.getSize(); j++)
		{
			for (int k = 0; k < currentTransactions[i].getSize(); k++)
			{
				if (currentCorrelation.getItem(j) == currentTransactions[i].getItem(k))
				{
					check = true;
					break;
				}
			}

			if (check == true && j == currentCorrelation.getSize() - 1)
			{
				//if item was found, and is last item in correlation, add to occurance
				currentCorrelation.setOccurance(currentCorrelation.getOccurance() + 1);
			}
			else if (check == false)
			{
				//leave transaction, move to next one
				break;
			}
		}
	}
}

//compares current item sets to relevant correlations to determine which transactions are relevant or not
void compare(Transaction currentTransactions[], int transactionSize, Correlation currentCorrelations[], int correlationSize)
{
	for (int i = 0; i < transactionSize; i++)
	{
		updateRelevant(currentTransactions[i], currentCorrelations, correlationSize);
	}
}

void updateRelevant(Transaction currentTransaction, Correlation currentCorrelations[], int correlationSize)
{
	bool isRelevant;

	//loop accessing correlations in basket
	for (int i = 0; i < correlationSize; i++)
	{
		isRelevant = false;
		for (int j = 0; j < currentCorrelations[i].getSize(); j++)
		{
			for (int k = 0; k < currentTransaction.getSize(); k++)
			{
				if (currentCorrelations[i].getItem(j) == currentTransaction.getItem(k))
				{
					isRelevant = true;
					break;
				}
			}

			if (isRelevant == true && j == currentCorrelations[i].getSize() - 1)
			{
				//if item was found, and is last item in correlation, set relevance
				currentTransaction.setRelevant(true);
			}
			else if (isRelevant == false)
			{
				//leave correlation, move to next one
				break;
			}
		}

		if (isRelevant == true)
		{
			break;
		}
	}
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
