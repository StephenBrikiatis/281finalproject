#include "Header.h"

//int main()
//{
//	//initial variables
//	int minimumOccurance; //variable for setting the minimum occurance that will be checked for
//	bool exit = false;
//	string fileName;
//
//	TransactionBasket mainTransactions;
//	TransactionBasket otherBasket;
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
//			mainTransactions = TransactionBasket("dataset/"+ fileName + ".txt");
//
//			int test;
//			test = mainTransactions.getTransaction(0).getItem(0);
//			cout << "test result: " << test << endl;
//
//			cout << "Debugging survived!" << endl << endl;
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
	/*CorrelationBasket oldBasket, newBasket;
	Correlation insert;

	for (int i = 0; i < 20; i++)
	{
		insert.add(i);

		if (i % 2 == 0)
		{
			insert.setRelevant(true);
		}

		oldBasket.setCorrelation(insert, i);
		insert.clear();
	}

	cout << oldBasket.getCorrelation(3).getItem(0);

	newBasket = createBasket(oldBasket, 2);

	cout << oldBasket.getCorrelation(3).getItem(0);

	for (int i = 0; i < newBasket.getSize(); i++)
	{
		insert = newBasket.getCorrelation(i);
		cout << insert.getItem(0);
	}
	*/

	Correlation *newArray = new Correlation[1000];



	pause();
	return 0;
}