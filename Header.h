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

#ifndef HEADER_H
#define HEADER_H

#include "transaction.h"
#include "correlation.h"
#include "timerSystem.h"

//constants
const int DATABASE_SIZE = 27, SMALL_FILE = 1000, MEDIUM_FILE = 10000, HIGH_FILE = 100000, DATA_RANGE = 1000, CORRELATION_DEFAULT = 1000000;


//database library
const string database[DATABASE_SIZE] = { "T5.N0.1K.D1K", "T5.N0.1K.D10K", "T5.N0.1K.D100K", "T5.N0.5K.D1K", "T5.N0.5K.D10K", "T5.N0.5K.D100K", "T5.N1K.D1K", "T5.N1K.D10K", "T5.N1K.D100K",
							       "T20.N0.1K.D1K", "T20.N0.1K.D10K", "T20.N0.1K.D100K", "T20.N0.5K.D1K", "T20.N0.5K.D10K", "T20.N0.5K.D100K", "T20.N1K.D1K", "T20.N1K.D10K", "T20.N1K.D100K",
							       "T25.N0.1K.D1K", "T25.N0.1K.D10K", "T25.N0.1K.D100K", "T25.N0.5K.D1K", "T25.N0.5K.D10K", "T25.N0.5K.D100K", "T25.N1K.D1K", "T25.N1K.D10K", "T25.N1K.D100K" };


//various functions
bool checkUserInput(string input);
bool correlationRelevance(Correlation currentCorrelations[], int correlationSize, int minOccurance);
int createCorrelations(Correlation currentCore[], int coreArraySize, int comboLength);

//init populates
int populateInitCorrelations(Correlation correlations[], int maxSize);
int populateNewTransactions(Transaction newBasket[], int transactionSize);
int populateWithFile(Transaction transactions[], string fileName);

//functions that print to file
void printCorrelations(Correlation currentBasket[], int size, ofstream &output);
void printTime(double time, int minOccurance, ofstream &output);

//functions that use both classes
void transactionRelevance(Transaction currentTransactions[], int transactionSize, Correlation currentCorrelations[], int correlationSize);
void updateRelevant(Transaction &currentTransaction, Correlation currentCorrelations[], int correlationSize);//linked to above function

void updateOccurances(Correlation currentCorrelations[], int correlationSize, Transaction currentTransactions[], int transactionSize);
void checkOccurance(Correlation &currentCorrelation, Transaction currentTransactions[], int transactionSize);//linked to above function


#endif