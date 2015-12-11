#include "Header.h"

int main()
{
	//initial variables
	int minimumOccurance; //variable for setting the minimum occurance that will be checked for
	bool exit = false;
	string fileName;

	Transaction* mainTransactions = new Transaction[LARGEST_SIZE];
	int transactionSize;
	Correlation* mainCorrelations = new Correlation[DATA_RANGE];
	int correlationSize;

	cout << "Welcome to New Horizon One's Apriori system. \n \n";

	//menu loop
	while (!exit)
	{	
		cout << "Please input the filename you wish to mine for, or enter -1 to leave. \n \n";
		cout << "Input here: ";

		cin >> fileName;

		if (fileName == "-1")
		{
			cout << endl << endl << "Have a nice day!" << endl;
			exit = true;
		}
		else if (checkUserInput(fileName))
		{
			//DO APRIORI STUFF HERE

			transactionSize = populateWithFile(mainTransactions, "dataset/" + fileName + ".txt");
			correlationSize = populateInitCorrelations(mainCorrelations, DATA_RANGE);

			cout << "Size: " << transactionSize << endl;
			cout << "Correlations 1-10: ";
			for (int i = 0; i < 10; i++)
			{
				cout << mainCorrelations[i].getItem(0) << " ";
			}

			cout << endl;
			////following two functions will load initial arrays
			//mainTransactions.populateWithFile(string); DONE
			//mainCorrelations.populateFromTrans(mainTransactions); DONE

			////main apriori loop
			//while (correlationSize > 0)
			//{

			//	//this function will check how many times each correlation occurs
			//	updateOccurances(mainCorrelations, correlationsize, mainTransactions, transactionsize);

			//	//PRUNE CORRELATIONS HERE, FUNCTION HAS YET TO BE DEFINED
			//	createBasket / createListOfNums

			//	//PRUNE TRANSACTIONS HERE
			//	compare(mainTransactions)

			//	//Output results and time!
			//	printCorrelations()
			//}

			////REPEAT UNTIL NO MORE CORRELATIONS
		}
		else
		{
			cout << endl << "Sorry, the file you requested was not in our database. Please try again." << endl << endl;
		}
	}

	system("pause");
	return 0;
}

//int main()
//{
//	/*CorrelationBasket oldBasket, newBasket;
//	Correlation insert;
//
//	for (int i = 0; i < 20; i++)
//	{
//		insert.add(i);
//
//		if (i % 2 == 0)
//		{
//			insert.setRelevant(true);
//		}
//
//		oldBasket.setCorrelation(insert, i);
//		insert.clear();
//	}
//
//	cout << oldBasket.getCorrelation(3).getItem(0);
//
//	newBasket = createBasket(oldBasket, 2);
//
//	cout << oldBasket.getCorrelation(3).getItem(0);
//
//	for (int i = 0; i < newBasket.getSize(); i++)
//	{
//		insert = newBasket.getCorrelation(i);
//		cout << insert.getItem(0);
//	}
//	*/
//
//
//	
//
//	/*Correlation *newArray = new Correlation[1000];
//
//	newArray[0].add(1);
//
//	cout << newArray[0].getItem(0);
//
//
//	pause();
//	return 0;*/
//}

//int main() //yet another main!!!
//{
//	Correlation cHolder;
//	Transaction tHolder;
//	int input;
//	string userInput;
//	
//	do
//	{
//		cout << "Enter file name: ";
//		cin >> userInput;
//
//	} while (userInput != "exit");
//
//}