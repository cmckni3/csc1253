/*
Chris McKnight
Barbara Guillot
cs1253 Sec 1
cs125326

Specify the requirement:
Calculate Christmas bonuses, total of bonuses, average
of bonuses, highest and lowest bonuses for Beta Systems Development, Inc.

Data Analysis:
Name      Type        Scope           Content
Variables:
ID        integer     main            Employee ID
                      HighestBonus
                      LowestBonus
count     integer     main            Number of employees
                      AvgBonus
title     character   main            An employee's job title code
                      CalcBonus
salary    real        main            An employee's salary
                      PrintSummary
                      CalcBonus
month     integer     main            Month of the report
                      PrintHeader
day       integer     main            Day of the report
                      PrintHeader
year      integer     main            Year of the report
                      PrintHeader
lowest    real        main            Lowest bonus
                      PrintSummary
                      LowestBonus
lowID     integer     main            ID of employee with the lowest bonus
                      PrintSummary
                      LowestBonus
highest   real        main            Highest bonus
                      PrintSummary
                      HighestBonus
highID    integer     main            ID of employee with the highest bonus
                      PrintSummary
                      HighestBonus
bonusamt  real        main            Bonus an employee gets for Christmas
                      CalcBonus
                      HighestBonus
                      LowestBonus
total     real        main            Sum of all of the bonuses
                      PrintSummary
avg       real        main            Average of the bonuses
                      AvgBonus
secbonus  real        main            Secretaries' bonus
                      PrintHeader
                      CalcBonus
secmax    real        main            Secretaries' maximum bonus
                      PrintHeader
                      CalcBonus
probonus  real        main            Programmers' bonus
                      PrintHeader
                      CalcBonus
promax    real        main            Programmers' maximum bonus
                      PrintHeader
                      CalcBonus
manbonus  real        main            MIS Managers' bonus
                      PrintHeader
                      CalcBonus
manmax    real        main            MIS Managers' maximum bonus
                      PrintHeader
                      CalcBonus
engbonus  real        main            Engineers' bonus
                      PrintHeader
                      CalcBonus
engmax    real        main            Engineers' maximum bonus
                      PrintHeader
                      CalcBonus
empsal    file        main            Input file empsal.data
bonus     file        main            Input file bonus.data
report    file        main            Output file report.out
                      PrintHeader
                      PrintAsterisks
                      PrintLine
                      PrintSummary
                      CalcBonus

Problem Analysis:
Print company information
Print bonus column headings
Read bonus data from file
Print bonus data(title, bonus rate, maximum bonus)
Print table headings for employees
  Repeat for all employees in file
    Read data(title, salary, ID)
    Calculate bonus
    Find highest bonus and respective ID
    Find lowest bonus and respective ID
    Print data(ID, title, salary, bonus)
    Sum bonuses and employees
Calculate average of bonuses
Print summary output (total of bonuses, average of bonuses

Algorithm:
function main
begin
  open the file empsal for reading
  open the file bonus for reading
  open the file report for writing
  get month, day, year, secbonus, secmax, probonus, promax,
  manbonus, manmax, engbonus, engmax from file bonus
  PrintHeader(report, month, day, year, secbonus, secmax, probonus,
  promax, manbonus, manmax, engbonus, engmax)
  count = 0
  total = 0
  lowest = 100000000
  highest = -10000000
  get ID from file empsal
  while not EOF
  begin
    get title and salary from file empsal
    print ID to file report
    bonusamt = CalcBonus(report, salary, title, secbonus,
    secmax, probonus, promax, manbonus, manmax, engbonus,
    engmax)
    HighestBonus(bonusamt, ID, highest, highID)
    LowestBonus(bonusamt, ID, lowest, lowID)
    print "$", salary to file report
    print "$", bonusamt to file report
    total = total + bonusamt
    get ID from file empsal
    count = count + 1
  end
  avg = AvgBonus(total, count)
  PrintSummary(report, total, avg, highID, highest, lowID, lowest)
  close the file empsal, bonus, and report
end

function PrintHeader(file *report, integer month, integer day,
integer year, real secbonus, real secmax, real probonus,
real promax, real manbonus, real manmax, real engbonus, real engmax)
begin
  PrintAsterisks(report);
  print "Beta Systems Development, Inc." to file report
  print "Annual Christmas Bonus Report" to file report
  print month to file report
  print "-", day to file report
  print "-", year to file report
  PrintAsterisks(report)
  print "Bonus Factors" to file report
  PrintLine(report)
  print "Title" to file report
  print "Rate" to file report
  print "Max.Bonus" to file report
  print "Secretary", secbonus to file report
  print "$", secmax to file report
  print "Programmer", probonus to file report
  print "$", promax to file report
  print "MIS Manager", manbonus to file report
  print "$", manmax to file report
  print "Engineer", engbonus to file report
  print "$", engmax to file report
  PrintLine(report)
  print "Emp.No" to file report
  print "Title" to file report
  print "Salary" to file report
  print "Bonus" to file report
  PrintLine(report)
end

function PrintAsterisks(file *report)
begin
  print "******************" to file report
end

function PrintLine(file *report)
begin
  print "-----------------" to file report
end


function PrintSummary(file *report, real total, real avg, integer highID,
real highest, integer lowID, real lowest)
begin
  PrintLine(report)
  print "The amount of all bonuses is $", total to file report
  print "The average bonus is $", avg to file report
  print "Employee ", highID to file report
  print " had the highest bonus of $", highest to file report
  print "Employee ", lowID to file report
  print " had the lowest bonus of $", lowest to file report
end


function CalcBonus(file *report, real salary, character title,
real secbonus, real secmax, real probonus, real promax,
real manbonus, real manmax, real engbonus, real engmax)
begin
  if (title = S)
  then
    begin
      print "Secretary" to file report
      bonusamt = 40*secbonus*salary
      if (bonusamt > secmax)
      then bonusamt = secmax
    end
  else
  if (title = P)
  then
    begin
      print "Programmer" to file report
      bonusamt = probonus*(salary/52)
      if (bonusamt > promax)
      then bonusamt = promax
    end
  else
  if (title = M)
  then
    begin
      print "MIS Manager" to file report
      bonusamt = manbonus*(salary/52)
      if (bonusamt > manmax)
      then bonusamt = manmax
    end
  else
  if (title = E)
  then
    begin
      print "Engineer" to file report
      bonusamt = engbonus*(salary/52)
      if (bonusamt > engmax)
      then bonusamt = engmax
    end
end


function AvgBonus(real total, integer count)
begin
  avg = total/count
end

function HighestBonus(real bonusamt, integer ID, real *highest,
integer *highID)
begin
  if (bonusamt > highest)
  then
    begin
      highest = bonusamt
      highID = ID
    end
end

function LowestBonus(real bonusamt, integer ID, real *lowest,
integer *lowID)
begin
  if (bonusamt < lowest)
  then
    begin
      lowest = bonusamt
      lowID = ID
    end
end
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void PrintHeader(ofstream &report, int month, int day, int year,
double secbonus, double secmax, double probonus, double promax,
double manbonus, double manmax, double engbonus, double engmax);

void PrintAsterisks(ofstream &report);

void PrintLine(ofstream &report);

void PrintSummary(ofstream &report, double total, double avg,
int highID, double highest, int lowID, double lowest);

double CalcBonus(ofstream &report, double salary, char title,
double secbonus, double secmax, double probonus, double promax,
double manbonus, double manmax, double engbonus, double engmax);

double AvgBonus(double total, int count);

void HighestBonus(double bonusamt, int ID, double &highest, int &highID);

void LowestBonus(double bonusamt, int ID, double &lowest, int &lowID);

int main()
{
  int ID,            // Employee ID
            count,         // Numbers of employees
            month,         // Month of the report
            day,           // Day of the report
            year,          // Year of the report
            lowID,         // ID of employee with lowest bonus
            highID;        // ID of employee with highest bonus
  double salary,     // An employee's salary
               bonusamt,   // Bonus an employee gets for Christmas
               total,      // Total of all of the bonuses
               avg,        // Average of the bonuses
               lowest,     // Lowest bonus
               highest,    // Highest bonus
               secbonus,   // Secretaries' bonus
               secmax,     // Secretaries' maximum bonus
               probonus,   // Programmers' bonus
               promax,     // Programmers' maximum bonus
               manbonus,   // MIS Managers' bonus
               manmax,     // MIS Managers' maximum bonus
               engbonus,   // Engineers' bonus
               engmax;     // Engineers' maximum bonus
  char title;        // Employee's job title code
  ifstream empsal,   // File empsal.data
     bonus;    // File bonus.data
  ofstream report;   // File report.out

  empsal.open("empsal.data");
  bonus.open("bonus.data");
  report.open("report.out");

  bonus>>month>>day>>year;
  bonus>>secbonus>>secmax;
  bonus>>probonus>>promax;
  bonus>>manbonus>>manmax;
  bonus>>engbonus>>engmax;

  PrintHeader(report, month, day, year, secbonus, secmax,
  probonus, promax, manbonus, manmax, engbonus, engmax);

  count = 0;
  total = 0;
  lowest = 10000000;
  highest = -10000000;

  empsal>>ID;
  while(!empsal.eof())
  {
    empsal>>title>>salary;
    report<<ID<<setw(16);
    bonusamt = CalcBonus(report, salary, title, secbonus,
    secmax, probonus, promax, manbonus, manmax, engbonus, engmax);
    HighestBonus(bonusamt, ID, highest, highID);
    LowestBonus(bonusamt, ID, lowest, lowID);
    report<<"  $";
    report<<setw(8)<<salary;
    report<<"   $"<<setw(7)<<bonusamt<<endl;
    total = total + bonusamt;
    empsal>>ID;
    count++;
  }
  avg = AvgBonus(total, count);
  PrintSummary(report, total, avg, highID, highest, lowID, lowest);
  empsal.close();
  bonus.close();
  report.close();
  return 0;
}

/*
Purpose: Print the headings of the program
Input: This function receives report, month, day, year,
secbonus, secmax, probonus, promax, manbonus, manmax,
engbonus, and engmax from main
Output: Prints the company name, the type of report, the date, asterisks,
and starts the printing of bonus factors.
*/
void PrintHeader(ofstream &report, int month, int day, int year, double
secbonus, double secmax, double probonus, double promax, double manbonus,
double manmax, double engbonus, double engmax)
{
  report<<fixed<<showpoint<<setprecision(2);
  PrintAsterisks(report);
  report<<"        Beta Systems Development, Inc."<<endl;
  report<<"        Annual Christmas Bonus Report"<<endl;
  report<<"                 "<<month<<"-"<<day<<"-"<<year<<endl;
  PrintAsterisks(report);
  report<<"              Bonus Factors"<<endl;
  PrintLine(report);
  report<<"Title"<<setw(14)<<"Rate"<<setw(14)<<"Max.Bonus"<<endl;
  report<<"Secretary  "<<setw(8)<<secbonus<<"      $";
  report<<setw(7)<<secmax<<endl;
  report<<"Programmer "<<setw(8)<<probonus<<"      $";
  report<<setw(7)<<promax<<endl;
  report<<"MIS Manager"<<setw(8)<<manbonus<<"      $";
  report<<setw(7)<<manmax<<endl;
  report<<"Engineer   "<<setw(8)<<engbonus<<"      $";
  report<<setw(7)<<engmax<<endl;
  PrintLine(report);
  report<<"Emp.No."<<setw(8);
  report<<"Title"<<setw(17);
  report<<"Salary"<<setw(10);
  report<<"Bonus"<<endl;
  PrintLine(report);
}

/*
Purpose: Print asterisks used in header output to separate the section
Input: This function receives report from main
Output: Print asterisks and a new line
*/
void PrintAsterisks(ofstream &report)
{
  report<<"********************************************"<<endl;
}

/*
Purpose: Print the dashes to separate areas of the table
Input: This function receives report from main
Output: Prints dashes and a new line
*/
void PrintLine(ofstream &report)
{
  report<<"--------------------------------------------"<<endl;
}


/*
Purpose: Prints the report summary which contains the total of the
bonuses, average of the bonuses, highest bonus and respective employee ID,
and the lowest bonus and respective ID
Input: This function receives the report, total, avg, highID, highest,
lowID, and lowest from main
Output: Prints the summary to the file report
*/
void PrintSummary(ofstream &report, double total, double avg, int highID,
double highest, int lowID, double lowest)
{
  PrintLine(report);
  report<<"The amount of all bonuses is $"<<total<<endl;
  report<<"The average bonus is $"<<avg<<endl;
  report<<"Employee "<<highID;
  report<<" had the highest bonus of $"<<highest<<endl;
  report<<"Employee "<<lowID;
  report<<" had the lowest bonus of $"<<lowest<<endl;
}

/*
Purpose: Calculates each employee's bonus
Input: This function receives report, salary, title,
secbonus, secmax, probonus, promax, manbonus, manmax, engbonus,
and engmax from main
Output: Returns the calculated bonus to the variable in main which
is also named bonusamt
*/
double CalcBonus(ofstream &report, double salary, char title, double
secbonus, double secmax, double probonus, double promax, double manbonus,
double manmax, double engbonus, double engmax)
{
  double bonusamt;          // Bonus an employee gets for Christmas
  if (title == 'S')
  {
    report<<"Secretary  ";
    bonusamt = 40*secbonus*salary;
    if (bonusamt > secmax)
    {
      bonusamt = secmax;
    }
  }
  else
  if (title == 'P')
  {
    report<<"Programmer ";
    bonusamt = probonus*(salary/52);
    if (bonusamt > promax)
    {
      bonusamt = promax;
    }
  }
  else
  if (title == 'M')
  {
    report<<"MIS Manager";
    bonusamt = manbonus*(salary/52);
    if (bonusamt > manmax)
    {
      bonusamt = manmax;
    }
  }
  else
  if (title == 'E')
  {
    report<<"Engineer   ";
    bonusamt = engbonus*(salary/52);
    if (bonusamt > engmax)
    {
      bonusamt = engmax;
    }
  }
  return bonusamt;
}

/*
Purpose: Calculate the average of the bonuses
Input: This function receives total of all bonuses, count of the number
of employees
Output: Returns the average of all of the bonuses to the variable in main
which is also named avg
*/
double AvgBonus(double total, int count)
{
  double avg;          // Average of all bonuses
  avg = total/count;
  return avg;
}

/*
Purpose: Check the bonus against the current highest bonus and then
overwrite it if bonus is higher and put the employee's ID in highID
Input: This function receives bonusamt which is the employee's calculated
bonus, ID which is the employee's ID, reference to highest,
reference to highID from main
Output: Multiple returns of highest and highID where the values of highest
and highID are modified using pass by reference
*/
void HighestBonus(double bonusamt, int ID, double &highest, int &highID)
{
  if (bonusamt > highest)
  {
    highest = bonusamt;
    highID = ID;
  }
}

/*
Purpose: Check the bonus against the current lowest bonus and then
overwrite it if bonus is lower and put the employee's ID in lowID
Input: This function recievesbonusamt which is the employee's calculated
bonus, ID which is the employee's ID, reference to lowest, reference to
lowID from main
Output: Multiple returns of lowest and lowID where the values of lowest
and lowID are modified using pass by reference
*/
void LowestBonus(double bonusamt, int ID, double &lowest, int &lowID)
{
  if (bonusamt < lowest)
  {
    lowest = bonusamt;
    lowID = ID;
  }
}
