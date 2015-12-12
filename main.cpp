#include "Header.h"

<<<<<<< HEAD
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
//			cout << "What is the occurance limit you want to set for the correlations? ";
//			cin >> minimumOccurance;
//			cout << endl << endl;
//
//			//INITIAL POPULATIONS
//			transactionSize = populateWithFile(mainTransactions, "dataset/" + fileName + ".txt");
//			correlationSize = populateInitCorrelations(mainCorrelations, DATA_RANGE);
//
//			//LOOP WOULD BEGIN HERE
//			//UPDATE CURRENT OCCURANCES
//			updateOccurances(mainCorrelations, correlationSize, mainTransactions, transactionSize);
//
//			cout << "Correlation Occurances: " << endl;
//			for (int i = 0; i < 150; i++)
//			{
//				cout << "Correlation " << i << ": " << mainCorrelations[i].getOccurance() << endl;
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

=======
>>>>>>> origin/arrayswereused
int main()
{
	//initial variables
	int minimumOccurance; //variable for setting the minimum occurance that will be checked for
	bool exit = false; //flag for exiting menu
	bool correlationsLeft = true; //flag for exiting correlation loop
	ofstream output; //file stream for writing output data
	string fileName; //file to open
	string outputFileName; //file to write to

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
			cout << "What is the occurance limit you want to set for the correlations? "; //set minimum occurance
			cin >> minimumOccurance;
			//cout << "What would you like to name your output file? "; //set output file
			//cin >> outputFileName;
			//output.open(outputFileName + ".txt");

			cout << endl << endl << "Please Wait... " << endl << endl;

			//INITIAL POPULATIONS
			transactionSize = populateWithFile(mainTransactions, "dataset/" + fileName + ".txt");
			correlationSize = populateInitCorrelations(mainCorrelations, DATA_RANGE);

			//LOOP WOULD BEGIN HERE
			//UPDATE CURRENT OCCURANCES
			updateOccurances(mainCorrelations, correlationSize, mainTransactions, transactionSize);

			//UPDATE CORRELATION RELEVANCE
			correlationsLeft = correlationRelevance(mainCorrelations, correlationSize, minimumOccurance);

			//MAKE NEW CORRELATIONS

			//UPDATE TRANSACTION RELEVANCE
			transactionRelevance(mainTransactions, transactionSize, mainCorrelations, correlationSize);

			//MAKE NEW TRANSACTIONS
			transactionSize = populateNewTransactions(mainTransactions, transactionSize);

			////PRINT OUT RESULTS
			//printCorrelations(mainCorrelations, correlationSize, output);

			////END LOOP
			//output.close();
		}
		else
		{
			cout << endl << "Sorry, the file you requested was not in our database. Please try again." << endl << endl;
		}
	}

	system("pause");
	return 0;
}
