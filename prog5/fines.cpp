#include "fines.h"

/*
Purpose: Clears the class variables by assigning them a value
*/
fines::fines()
{
  ID = 0;
  days = 0;
  balance = 0.0;
}

/*
Purpose: Set the values of ID and days in the class so the values will be in the class
Input: This function receives an ID and days from the client (main)
*/
fines::fines(int cID, int cdays)
{
  ID = cID;
  days = cdays;
}

/*
Purpose: Calculates the balance due on late books and keeps a sum of them
Input: This function receives total from client (main) as pass by reference
*/
void fines::CalcBal(double &total)
{
  if ((days >= 30) && (days <= 60))
  {
    balance = LATE1*days;
  }
  else
  if ((days >= 61) && (days <= 100))
  {
    balance = LATE2*days;
  }
  else
  if (days > 100)
  {
    balance = LATE3*days;
  }
  total = total + balance;
}

/*
Purpose: Gives main the value of the ID variable in the class since it is private in the class
Input: none
Output: Returns the class variable ID to client (main)
*/
int fines::getID()
{
  return ID;
}

/*
Purpose: Gives main the value of the days variable in the class since it is private in the class
Input: none
Output: Returns the class variable days to client (main)
*/
int fines::getdays()
{
  return days;
}

/*
Purpose: Gives main the value of the balance variable in the class since it is private in the class
Input: none
Output: Returns the class variable balance to client (main)
*/
double fines::getbal()
{
  return balance;
}

/*
Purpose: Finds the highest and lowest balances and their respective IDs
Input: This function receives lowest, lowID, highest, highID, and count from client (main)
Output: Returns multiple values using pass by reference which are highest, lowest, lowID, and highID
*/
void fines::HiLow(double &lowest, int &lowID,
double &highest, int &highID, int count)
{
  if (balance < lowest)
  {
    lowest = balance;
    lowID = ID;
  }
  if (balance > highest)
  {
    highest = balance;
    highID = ID;
  }
}

/*
Purpose: calculate the average of the balances
Input: This function receives count and total from main
Output: Returns avg to main
*/
double fines::Avg(int count, double total)
{
  double avg;
  avg = total/count;
  return avg;
}
