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
#include "common.h"

/*  Author: Stephen Brikiatis
*	   Pre:  None
*     Post:  Console screen is cleared
*  Purpose:  To clear the screen
*************************************************************************/
void clearScreen()
{
  system("cls");
}

/*  Author: Stephen Brikiatis
*	   Pre:  None
*     Post:  System Pause is Called
*  Purpose:  To pause the console
*************************************************************************/
void pause()
{
  system("pause");
}
