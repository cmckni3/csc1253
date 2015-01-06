#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const int MAX = 20;                  // Static number of records for arrays
const double LATE1 = .05;            // Fine rate for 30-60 days late
const double LATE2 = .07;            // Fine rate for 61-100 days late
const double LATE3 = .10;            // Fine rate for over 100 days late

class fines
{
  private:
  int ID,                      // Library account numbers
      days;                    // The number of days a book is late
  double balance;              // Late penalty balance due

  public:
  fines();
  fines(int cID, int cdays);

  void CalcBal(double &total);

  void HiLow(double &lowest, int &lowID,
  double &highest, int &highID, int count);

  int getID();

  int getdays();

  double getbal();

  double Avg(int count, double total);
};
