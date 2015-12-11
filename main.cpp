#include "Header.h"

//int main()
//{
//	//initial variables
//	int minimumOccurance; //variable for setting the minimum occurance that will be checked for
//	bool exit = false;
//	string fileName;
//
//	Transaction* mainTransactions = new Transaction[LARGEST_SIZE];
//	int transactionSize;
//	Correlation* mainCorrelations = new Correlation[DATA_RANGE];
//	int correlationSize;
//
//	cout << "Welcome to New Horizon One's Apriori system. \n \n";
//
//	//menu loop
//	while (!exit)
//	{	
//		cout << "Please input the filename you wish to mine for, or enter -1 to leave. \n \n";
//		cout << "Input here: ";
//
//		cin >> fileName;
//
//		if (fileName == "-1")
//		{
//			cout << endl << endl << "Have a nice day!" << endl;
//			exit = true;
//		}
//		else if (checkUserInput(fileName))
//		{
//			//DO APRIORI STUFF HERE
//
//			transactionSize = populateWithFile(mainTransactions, "dataset/" + fileName + ".txt");
//			correlationSize = populateInitCorrelations(mainCorrelations, DATA_RANGE);
//
//			cout << "Size: " << transactionSize << endl;
//			cout << "Correlations 1-10: ";
//			for (int i = 0; i < 10; i++)
//			{
//				cout << mainCorrelations[i].getItem(0) << " ";
//			}
//
//			cout << endl;
//			////following two functions will load initial arrays
//			//mainTransactions.populateWithFile(string); DONE
//			//mainCorrelations.populateFromTrans(mainTransactions); DONE
//
//			////main apriori loop
//			//while (correlationSize > 0)
//			//{
//
//			//	//this function will check how many times each correlation occurs
//			//	updateOccurances(mainCorrelations, correlationsize, mainTransactions, transactionsize);
//
//			//	//PRUNE CORRELATIONS HERE, FUNCTION HAS YET TO BE DEFINED
//			//	createBasket / createListOfNums
//
//			//	//PRUNE TRANSACTIONS HERE
//			//	compare(mainTransactions)
//
//			//	//Output results and time!
//			//	printCorrelations()
//			//}
//
//			////REPEAT UNTIL NO MORE CORRELATIONS
//		}
//		else
//		{
//			cout << endl << "Sorry, the file you requested was not in our database. Please try again." << endl << endl;
//		}
//	}
//
//	system("pause");
//	return 0;
//}

int main()
{
	Correlation newArray[1000];
	int arraySize = 1000;

	populateInitCorrelations(newArray, 1000);

	createBasket(newArray, 1000, 2);

	cout << newArray[0].getItem(0) << endl << newArray[0].getItem(1);

	pause();
	return 0;
}