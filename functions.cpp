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

	if (comboLength == 2) //if combonation length is 2
	{
		for (int i = 0; i < tmpSize - 1; i++)
		{
			int n = 1;
			while (i + n != tmpSize - 1)
			{
				currentCore[newArraySize].addItem(tmpList[i].getItem(0));
				currentCore[newArraySize].addItem(tmpList[i + n].getItem(0));

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
				if (tmpList[i].getItem(0) == tmpList[i + n].getItem(0))
				{
					//add all items except last one
					for (int j = 0; j < comboLength - 1; j++)
					{
						currentCore[newArraySize].addItem(tmpList[i].getItem(j));
					}
					//add last one
					currentCore[newArraySize].addItem(tmpList[i + n].getItem(comboLength - 1));
					n++;//increment check range
					newArraySize++; //increment new array size

					if (n + i == tmpSize) //break out of loop if out of bounds
						check = false;
				}
				else
				{
					check = false;
				}
			}
		}
	}

	return newArraySize;
}

int createBasket(Correlation currentCore[], int coreArraySize, int comboLength)
{
	int numbers[1000];
	Correlation resetHolder; //= new Correlation[comboLength];
	int numbersLength, r = 0, index = 0, coreCount = 0, holder[50];

	for (int i = 0; i < 50; i++)
	{
		holder[i] = 0;
		resetHolder.add(0, i);
		resetHolder.setSize(0);
	}

	numbersLength = createListOfNums(numbers, currentCore, coreArraySize);
	cout << "Pause for dramatic effect." << endl;

	if(comboLength > numbersLength)
	{
		cout << "Can't make a combination with that few numbers" << endl;
	}


	for (int i = 0; i <= coreArraySize - comboLength; i++)
	{
		holder[0] = numbers[i];
		basketHelper(numbers, coreArraySize, comboLength, holder, i + 1, 1, currentCore, coreCount);
	}

	return coreCount;
}

void basketHelper(int numbers[], int coreArraySize, int comboLength, int holder[], int prevI, int j, Correlation currentCore[], int &coreCount)
{
	if (j == comboLength)
	{
		for (int w = 0; w < comboLength; w++)
		{
			currentCore[coreCount].add(holder[w], w);
		}
		coreCount++;
		return;
	}
	for (int k = prevI; k <= coreArraySize - comboLength + j; k++)
	{
		holder[j] = numbers[k];
		basketHelper(numbers, coreArraySize, comboLength, holder, k + 1, j + 1, currentCore, coreCount);
	}
}

int createListOfNums(int listOfNums[], Correlation listOfCores[], int size)
{
	int correSize = 0, compare, listSize = 0;
	Correlation tmp;
	bool exists = false;

	correSize = listOfCores[0].getSize();

	for(int i = 0; i < size; i++)
	{
		if(listOfCores[i].getRelevant())
		{
			for(int j = 0; j < correSize; j++)
			{
				compare = listOfCores[i].getItem(j);
				for(int k = 0; k < listSize; k++)
				{
					listOfNums[k];
				}
				listOfNums[listSize] = compare;
				listSize++;
			}
		}
	}

	return listSize;
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
		correlations[i].add(i+1, 0); // this is i+1 for testing perposes only
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

