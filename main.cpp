#include "Header.h"

int main()
{
	//initial variables
	int minimumOccurance; //variable for setting the minimum occurance that will be checked for
	string fileName;

	cout << "Welcome to New Horizon One's Apriori system. \n \n";

	//menu loop
	while (true)
	{	
		cout << "Please input the filename you wish to mine for, or enter -1 to leave. \n \n";
		cout << "Input here: ";

		cin >> fileName;

		if (fileName == "-1")
		{
			cout << endl << endl << "Have a nice day!" << endl;
			break;
		}
		else if (checkUserInput(fileName))
		{
			//DO APRIORI STUFF HERE
		}
		else
		{
			cout << endl << "Sorry, the file you requested was not in our database. Please try again." << endl << endl;
		}

	}

	system("pause");
	return 0;
}