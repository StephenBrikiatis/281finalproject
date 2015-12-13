/*
Modified by:   Gabriel Pereyra and Stephen Brikiatis
Class:         CSI-281-03
Assignment:    Final Project
Date Assigned: 12/12/2015
Due Date:      11/16/2015
Description:
An implementaion for Apriori. Reads a file and finds correlations within the data
and then outputs that data to a text file. This system also times the data extraction
and is open to variable minimum thresholds.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/
#include "Header.h"

/*  Author:  Gabriel Pereyra
*	   Pre:  User inputs a string
*     Post:  True is returned if string matches file on database, false if not.
*  Purpose:  To validate user input for the filename
*************************************************************************/
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

/*  Author:  Gabriel Pereyra
*	   Pre:  An array of correlations is populated
*     Post:  Updates correlation relevance depending on the occurance number
*			 returns false if data mining is done (not enough correlations left)
*			 or true if there is still mining to be done.
*  Purpose:  To go through the correlation array and determine which 
			 correlations are relevant
*************************************************************************/
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

/*  Author:  Gabriel Pereyra
*	   Pre:  A correlation with updated relevance is passed in
*     Post:  Creates a new list of correlations from the previously relevant ones
*			 returns new size of array.
*  Purpose:  To create a new population of correlations of incrementing length
*************************************************************************/
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

/*  Author:  Gabriel Pereyra
*	   Pre:  Data mining loop has begun
*     Post:  Creates a new list of all possible single digit correlations
*			 returns new size of array.
*  Purpose:  To have a starting correlation list to work with
*************************************************************************/
int populateInitCorrelations(Correlation correlations[], int maxSize)
{
	for (int i = 0; i < maxSize; i++)
	{
		correlations[i].add(i, 0);
		correlations[i].setSize(1);
	}

	return maxSize;
}

/*  Author:  Gabriel Pereyra
*	   Pre:  A transaction array with updated relevance is passed in
*     Post:  Updates array to only include relevant transactions
*			 returns new size of array
*  Purpose:  To prune list of transactions for efficiency
*************************************************************************/
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

/*  Author:  Gabriel Pereyra
*	   Pre:  A data file is passed in
*     Post:  Populates transaction array with data from the file
*			 returns new size of array
*  Purpose:  To transfer data from file to be mined from 
*************************************************************************/
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

/*  Author:  Gabriel Pereyra
*	   Pre:  An updated correlation array is passed in
*     Post:  Prints relevant current correlations and their occurances
*			 on the output file
*  Purpose:  To print relevant correlation data to an outputfile
*************************************************************************/
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

/*  Author:  Gabriel Pereyra
*	   Pre:  A time double is passed in
*     Post:  Prints time taken to perform operation to the file
*  Purpose:  To print the time it takes to perform the mining to an output file
*************************************************************************/
void printTime(double time, int minOccurance, ofstream &output)
{
	output << "Minimum Occurance: " << minOccurance << endl;
	output << "Time Taken to Mine: " << time << " Seconds";
}

/*  Author:  Gabriel Pereyra
*	   Pre:  An updated correlation array and transaction array is passed in
*     Post:  Transaction array is pruned so that only relevant transactions remain
*  Purpose:  To compare current transactions to relevant correlations to shorten and prune
*			 the current transaction list
*************************************************************************/
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

/*  Author:  Gabriel Pereyra
*	   Pre:  An updated correlation array and transaction array is passed in
*     Post:  Occurance members of correlations in the correlation array are updated to reflect
*			 their occurance in the transaction array that is passed in
*  Purpose:  To compare correlations and transactions to determine the occurance of
*			 each correlation in array
*************************************************************************/
void updateOccurances(Correlation currentCorrelations[], int correlationSize, Transaction currentTransactions[], int transactionSize)
{
	for (int i = 0; i < correlationSize; i++)
	{
		checkOccurance(currentCorrelations[i], currentTransactions, transactionSize);
	}
}
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




