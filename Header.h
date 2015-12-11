#ifndef HEADER_H
#define HEADER_H

#include "transactionBasket.h"
#include "correlationBasket.h"

const int DATABASE_SIZE = 27, SMALL_FILE = 1000, MEDIUM_FILE = 10000, HIGH_FILE = 100000, DATA_RANGE = 10000;


//database library
const string database[DATABASE_SIZE] = { "T5.N0.1K.D1K", "T5.N0.1K.D10K", "T5.N0.1K.D100K", "T5.N0.5K.D1K", "T5.N0.5K.D10K", "T5.N0.5K.D100K", "T5.N1K.D1K", "T5.N1K.D10K", "T5.N1K.D100K",
							       "T20.N0.1K.D1K", "T20.N0.1K.D10K", "T20.N0.1K.D100K", "T20.N0.5K.D1K", "T20.N0.5K.D10K", "T20.N0.5K.D100K", "T20.N1K.D1K", "T20.N1K.D10K", "T20.N1K.D100K",
							       "T25.N0.1K.D1K", "T25.N0.1K.D10K", "T25.N0.1K.D100K", "T25.N0.5K.D1K", "T25.N0.5K.D10K", "T25.N0.5K.D100K", "T25.N1K.D1K", "T25.N1K.D10K", "T25.N1K.D100K" };


//general use functions
bool checkUserInput(string input);
void printCorrelations(Correlation currentBasket[], int size, ofstream output);
CorrelationBasket createBasket(CorrelationBasket currentBasket, int comboLength);
LinkedList<int> createListOfNums(CorrelationBasket currentBasket);

//functions that populate initial baskets
int populateWithFile(Transaction transactions[], string fileName);
int populateInitCorrelations(Correlation correlations[], int maxSize);

//functions that use both classes
void updateOccurances(Correlation currentCorrelations[], int correlationSize, Transaction currentTransactions[], int transactionSize);
void checkOccurance(Correlation currentCorrelation, Transaction currentTransactions[], int transactionSize);

void compare(Transaction currentTransactions[], int transactionSize, Correlation currentCorrelations[], int correlationSize);
void updateRelevant(Transaction currentTransaction, Correlation currentCorrelations[], int correlationSize);

string listOfFiles(int input);

#endif