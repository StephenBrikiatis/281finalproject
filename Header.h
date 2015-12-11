#ifndef HEADER_H
#define HEADER_H

#include "transactionBasket.h"
#include "correlationBasket.h"

const int DATABASE_SIZE = 27;

//database library
const string database[DATABASE_SIZE] = { "T5.N0.1K.D1K", "T5.N0.1K.D10K", "T5.N0.1K.D100K", "T5.N0.5K.D1K", "T5.N0.5K.D10K", "T5.N0.5K.D100K", "T5.N1K.D1K", "T5.N1K.D10K", "T5.N1K.D100K",
							       "T20.N0.1K.D1K", "T20.N0.1K.D10K", "T20.N0.1K.D100K", "T20.N0.5K.D1K", "T20.N0.5K.D10K", "T20.N0.5K.D100K", "T20.N1K.D1K", "T20.N1K.D10K", "T20.N1K.D100K",
							       "T25.N0.1K.D1K", "T25.N0.1K.D10K", "T25.N0.1K.D100K", "T25.N0.5K.D1K", "T25.N0.5K.D10K", "T25.N0.5K.D100K", "T25.N1K.D1K", "T25.N1K.D10K", "T25.N1K.D100K" };

void checkOccurance(Correlation currentCorrelation, TransactionBasket currentTransactions);
bool checkUserInput(string input);
void compare(TransactionBasket currentTransactions, CorrelationBasket currentCorrelations);
CorrelationBasket createBasket(CorrelationBasket currentBasket, int comboLength);
LinkedList<int> createListOfNums(CorrelationBasket currentBasket);
string listOfFiles(int input);
void printCorrelations(CorrelationBasket currentBasket, ofstream output);
void updateRelevant(Transaction currentTransaction, CorrelationBasket currentCorrelations);
//functions that use both classes
void updateOccurances(CorrelationBasket currentCorrelations, TransactionBasket currentTransactions);

#endif