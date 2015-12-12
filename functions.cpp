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
void printCorrelations(Correlation currentBasket[], int size, ofstream &output)
{
	int correlationNum = 1;

	for (int i = 0; i < size; i++)
	{
		if (currentBasket[i].getRelevant() == true)
		{
			output << correlationNum << " [";
			for (int j = 0; j < currentBasket[i].getSize(); j++)
			{
				output << " " << currentBasket[i].getItem(j);
			}
			output << " ] Occurances: ";
			output << currentBasket[i].getOccurance() << "  ";
			output << endl;

			correlationNum++;
		}
	}

	output << endl << endl;
}

void printTime(double time, int minOccurance, ofstream &output)
{
	output << "Minimum Occurance: " << minOccurance << endl;
	output << "Time Taken to Mine: " << time << " Seconds";
}

//makes new array of correlations
int createCorrelations(Correlation currentCore[], int coreArraySize, int comboLength)
{
	int tmpSize = 0;
	int newArraySize = 0;
	Correlation* tmpList = new Correlation[coreArraySize];

	//make array of relevant correlations
	for (int i = 0; i < coreArraySize; i++)
	{
		if (currentCore[i].getRelevant() == true)
		{
			tmpList[tmpSize] = currentCore[i];
			tmpSize++;
		}
	}

	//clear current correlation array
	for (int i = 0; i < coreArraySize; i++)
	{
		currentCore[i].clear();
	}

	if (comboLength == 2) //if combonation length is 2
	{
		for (int i = 0; i < tmpSize - 1; i++)
		{
			int n = 1;
			while (i + n != tmpSize - 1)
			{
				int firstNum = tmpList[i].getItem(0);
				int secondNum = tmpList[i + n].getItem(0);
				currentCore[newArraySize].addItem(firstNum);
				currentCore[newArraySize].addItem(secondNum);

				newArraySize++;
				n++;
			}
		}
	}
	else //if combonation length is bigger than 2
	{
		//make new array, logic is hard
		for (int i = 0; i < tmpSize - 1; i++)
		{
			bool check = true;//flag for staying in loop
			int n = 1;//variable that determines how far to go in the array

			while (check)
			{
				for (int k = 0; k < comboLength - 2; k++)
				{
					if (tmpList[i].getItem(k) != tmpList[i + n].getItem(k))
						check = false;
				}
				if (check != false)
				{
					//add all items except last one
					for (int j = 0; j < comboLength - 1; j++)
					{
						currentCore[newArraySize].addItem(tmpList[i].getItem(j));
					}
					//add last one
					currentCore[newArraySize].addItem(tmpList[i + n].getItem(comboLength - 2));
					n++;//increment check range
					newArraySize++; //increment new array size

					if (n + i == tmpSize) //break out of loop if out of bounds
						check = false;
				}
			}
		}
	}

	return newArraySize;
}

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
		if (tmpSize != transNum)
		{
			tmpSize++;
		}
	}

	data.close();

	return tmpSize;
}

//makes initial list of possible correlations
int populateInitCorrelations(Correlation correlations[], int maxSize)
{
	for (int i = 0; i < maxSize; i++)
	{
		correlations[i].add(i, 0);
		correlations[i].setSize(1);
	}

	return maxSize;
}

//populates a new basket with the relevant transactions from the previous basket
int populateNewTransactions(Transaction newBasket[], int transactionSize)
{
	Transaction *tmpList = new Transaction[transactionSize]; //tmp list to copy relevant transactions
	int tmpSize = 0; //keeps track of new transactions to determine new size

	//fill temp list
	for (int i = 0; i < transactionSize; i++)
	{
		if (newBasket[i].getRelevant() == true)
		{
			tmpList[tmpSize] = newBasket[i];
			tmpSize++;
		}
	}

	//populate actual list
	for (int j = 0; j < tmpSize; j++)
	{
		newBasket[j] = tmpList[j];
	}

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
void checkOccurance(Correlation &currentCorrelation, Transaction currentTransactions[], int transactionSize)
{
	bool check = false;
	int correlNum;
	int transNum;

	for (int i = 0; i < transactionSize; i++)
	{
		for (int j = 0; j < currentCorrelation.getSize(); j++)
		{
			correlNum = currentCorrelation.getItem(j);

			for (int k = 0; k < currentTransactions[i].getSize(); k++)
			{
				transNum = currentTransactions[i].getItem(k);

				if (correlNum == transNum)
				{
					check = true;
					break;
				}
			}

			if (check == true && j == currentCorrelation.getSize() - 1)
			{
				currentCorrelation.setOccurance(currentCorrelation.getOccurance() + 1);
				check = false;
			}
			else if (check == false)
			{
				break;
			}
			else
			{
				check = false;
			}
		}
	}

}

//compares current item sets to relevant correlations to determine which transactions are relevant or not
void transactionRelevance(Transaction currentTransactions[], int transactionSize, Correlation currentCorrelations[], int correlationSize)
{
	for (int i = 0; i < transactionSize; i++)
	{
		updateRelevant(currentTransactions[i], currentCorrelations, correlationSize);
	}
}

void updateRelevant(Transaction &currentTransaction, Correlation currentCorrelations[], int correlationSize)
{
	bool isRelevant;
	int correlNum;
	int transNum;

	//loop accessing correlations in basket
	for (int i = 0; i < correlationSize; i++)
	{
		isRelevant = false;
		for (int j = 0; j < currentCorrelations[i].getSize(); j++)
		{
			correlNum = currentCorrelations[i].getItem(j);
			for (int k = 0; k < currentTransaction.getSize(); k++)
			{
				transNum = currentTransaction.getItem(k);

				if (correlNum == transNum)
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
			else
			{
				isRelevant = false;
			}
		}

		if (isRelevant == true)
		{
			break;
		}
	}
}

//goes through all correlations and updates their relevance by Gabe
bool correlationRelevance(Correlation currentCorrelations[], int correlationSize, int minOccurance)
{
	int count = 0;

	for (int i = 0; i < correlationSize; i++)
	{
		if (currentCorrelations[i].getOccurance() < minOccurance)
		{
			currentCorrelations[i].setRelevant(false);
		}
		else
		{
			count++;
		}		
	}

	if (count <= 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

