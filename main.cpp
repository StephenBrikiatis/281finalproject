#include "Header.h"

int main()
{
	//initial variables
	int minimumOccurance; //variable for setting the minimum occurance that will be checked for
	bool exit = false;
	string fileName;

	TransactionBasket mainTransactions;
	TransactionBasket otherBasket;

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
			mainTransactions.populateWithFile("dataset/"+ fileName + ".txt");

			int test;
			test = mainTransactions.getSize();
			cout << "test result: " << test << endl;

			cout << "Debugging survived!" << endl << endl;
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
//	CorrelationBasket testBasket;
//	Correlation testCorrelation, tmp;
//
//	testCorrelation.add(1);
//	testCorrelation.add(2);
//	testCorrelation.add(3);
//	tmp.add(1);
//
//	testBasket.setCorrelation(testCorrelation, 0);
//
//	tmp = testBasket.getCorrelation(0);
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << testBasket.getCorrelation(0).getItem(i);
//	}
//
//	cout << testBasket.getCorrelation(0).getItem(0);
//
//	cout << endl << endl;
//
//	Transaction testTrans, tmp;
//	TransactionBasket testBasket;
//
//	testTrans.addItem(9);
//	testTrans.addItem(8);
//	testTrans.addItem(7);
//
//	testBasket.setTransaction(testTrans, 0);
//
//	tmp = testBasket.getTransaction(0);
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << testBasket.getTransaction(0).getItem(i);
//	}
//
//	cout << endl << endl;
//
//	system("pause");
//	return 0;
//}