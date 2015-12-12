#include "Header.h"

int main()
{
	//initial variables
	int minimumOccurance; //variable for setting the minimum occurance that will be checked for
	int correlationLength;
	bool exit = false; //flag for exiting menu
	bool correlationsLeft; //flag for exiting correlation loop
	string fileName; //file to open
	string outputFileName; //file to write to

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
			ofstream output; //file stream for writing output data

			//DO APRIORI STUFF HERE
			cout << "What is the occurance limit you want to set for the correlations? "; //set minimum occurance
			cin >> minimumOccurance;
			cout << "What would you like to name your output file? "; //set output file
			cin >> outputFileName;
			output.open(outputFileName + ".txt");

			cout << endl << endl << "Please Wait... " << endl << endl;

			//VARIABLE INIT
			Transaction* mainTransactions = new Transaction[LARGEST_SIZE];
			int transactionSize;
			Correlation* mainCorrelations = new Correlation[CORRELATION_DEFAULT];
			int correlationSize;

			correlationLength = 2;
			correlationsLeft = true;

			//INITIAL POPULATIONS
			transactionSize = populateWithFile(mainTransactions, "dataset/" + fileName + ".txt");
			correlationSize = populateInitCorrelations(mainCorrelations, DATA_RANGE);

			//LOOP WOULD BEGIN HERE
			while (correlationsLeft)
			{
				//UPDATE CURRENT OCCURANCES
				updateOccurances(mainCorrelations, correlationSize, mainTransactions, transactionSize);

				//UPDATE CORRELATION RELEVANCE
				correlationsLeft = correlationRelevance(mainCorrelations, correlationSize, minimumOccurance);

				//PRINT OUT RESULTS
				printCorrelations(mainCorrelations, correlationSize, output);

				//MAKE NEW CORRELATIONS
				correlationSize = createCorrelations(mainCorrelations, correlationSize, correlationLength);//FIX THIS FOR THE LOVE OF GOD

				//UPDATE TRANSACTION RELEVANCE
				transactionRelevance(mainTransactions, transactionSize, mainCorrelations, correlationSize);

				//MAKE NEW TRANSACTIONS
				transactionSize = populateNewTransactions(mainTransactions, transactionSize);

				correlationLength++;
			}
			//END LOOP
			output.close();

			cout << "Your data has been mined." << endl << endl;
		}
		else
		{
			cout << endl << "Sorry, the file you requested was not in our database. Please try again." << endl << endl;
		}
	}

	system("pause");
	return 0;
}