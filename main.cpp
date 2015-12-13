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
			TimerSystem timer;
			double timeSpent = 0;

			//DO APRIORI STUFF HERE
			cout << "What is the occurance limit you want to set for the correlations? "; //set minimum occurance
			cin >> minimumOccurance;
			cout << "What would you like to name your output file? "; //set output file
			cin >> outputFileName;
			output.open(outputFileName + ".txt");

			cout << endl << endl << "Please Wait... " << endl << endl;
			timer.startClock();

			//VARIABLE INIT
			Transaction* mainTransactions = new Transaction[HIGH_FILE];
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
			timeSpent += timer.getTime();

			printTime(timeSpent, minimumOccurance, output);
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