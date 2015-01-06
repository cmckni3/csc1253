/*
Chris McKnight
Barbara Guillott
cs1253 Sec 1
cs125326

Specify the requirement:
Calculate average and highest sales amount for each employee and
each quarter, print a report of all employees, a singular report,
and a report of all employees with their highest and
average sales amount for Wonderful World of Widgets Company.

Data Analysis:
Name        Type       Scope              Content
Constants:
MAX         integer    global             Static allocation of array, 20
RECS        integer    global             Number of sales records, 4

Variables:
input       file       main               Input file amts.data
index       integer    main               1st dimension array position
index2      integer    PrintReport        2nd dimension array position
i           integer    SelectionSortName  1st dimension array position
j           integer    SelectionSortName  2nd dimension array position
mcount      integer    main               Number of employees
count       integer    PrintReport        Number of employees
op          integer    main               Operation the user wants to perform
person      employee1  main               Struct array for records
person2     employee1  main               Copy of struct array of records
ID          integer    employee1          ID of employee
name        string     employee1          Name of employee Last, first
first       string     employee1          First name of employee
                       PrintReport
last        string     employee1          Last name of employee
                       PrintReport
sales[]     real       employee1          Employee's sales for each quarter
average     real       employee1          Employee's average sales
highest     real       employee1          Employee's highest sales
option      integer    PrintMenu          The option that the user chose
average[]   real       PrintRecord        Average sales amount for each quarter
highest[]   real       PrintRecord        Highest sales amount for each quarter
total       real       Average            Total sales for each employee
qtotal      real       QAverage           Total sales for each quarter
temp        employee1  BinSearch          Temporary variable for record swap
first       integer    BinSearch          Starting point for Binary Search
mid         integer    BinSearch          Midpoint for binary search
last        integer    BinSearch          Endpoint for binary search

Problem Analysis:
open file amts.data for reading
  while not eof
    read data from file amts.data into struct
Calculate Averages sales amount for each employee
Find Highest sales amount for each employee
Prompt user for report they want and print report of their choosing
  Singular Report
    Find person's record
    Print person's record if found
  Complete Report
    Calculate highest and average sales for each quarter
    Print sales amount of each quarter for all employees
    Print summary output of highest and averages sales
    for each quarter
  Record Report
    Print all employee's and their average and highest sales amount

Algorithm:
function main
begin
  mcount = 0
  read person[mcount].ID
  while not eof
  begin
    read person[mcount].first
    read person[mcount].last
    person[mcount].name = person[mcount].last + ", " +
    person[mcount].first
    for (index = 0 to RECS)
    begin
      read person[mcount].sales[index]
    end
    mcount = mcount + 1
    read person[mcount].ID
  end
  Average(mcount, person)
  Highest(mcount, person)
  for (index = 0 to mcount)
  begin
    person2[index] = person[index]
  end
  op = 0
  while (op <> 4)
  begin
    op = PrintMenu()
    if (op = 1)
    then
      PrintReport(mcount, person2)
    else
    if (op = 2)
    then
      PrintSummary(mcount, person)
    else
    if (op = 3)
    then
      PrintRecord(mcount, person)
    else
    if (op = 4)
    then
    else
    then
      print "Invalid selection. Please try again."
  end
end

function PrintHeader()
begin
  PrintAsterisks()
  print "Wonderful World of Widgets Company"
  print "Quarterly Sales Report"
  print "Dec 4, 2008"
  PrintAsterisks()
  PrintLine()
end

function PrintAsterisks()
begin
  print "******************************************"
end

function PrintLine()
begin
  print "------------------------------------------"
end

function PrintMenu()
begin
  print "1. Print Singular Report"
  print "2. Print Complete Report"
  print "3. Print Record"
  print "4. Exit"
  print "Enter selection: "
  read option
end

function PrintReport(integer count, employee1 person[])
begin
  print "Enter a name in the format Firstname Lastname: "
  read first
  read last
  PrintHeader()
  SelectionSortName(person, count)
  index = BinSearch(person, last + ", " + first, count)
  if (index == -1)
  begin
    print first, last, "not found"
  end
  else
  begin
    print "ID"
    print "Name"
    print "Average"
    print "Highest"

    print person[index].ID
    print person[index].name
    print person[index].average
    print person[index].highest
  end
  PrintLine()
end

function PrintSummary(integer count, employee1 person[])
begin
  PrintHeader()
  print "ID"
  print "Name"
  print "Quarter 1"
  print "Quarter 2"
  print "Quarter 3"
  print "Quarter 4"
  PrintLine()
  for (index = 0 to count)
  begin
    print person[index].ID
    print person[index].name
    for (index2 = 0 to RECS)
    begin
      print person[index].sales[index2]
    end
  end
  QHighest(count, person, highest)
  QAverage(count, person, average)
  for (index = 0 to RECS)
  begin
    print "The average sales amount for quarter ",index+1
    print " is ",average[index]
    print "The highest sales amount for quarter ",index+1
    print " is ",highest[index]
  end
  PrintLine()
end

function PrintRecord(integer count, employee1 person[])
begin
  PrintHeader()
  print "ID"
  print "Name"
  print "Average"
  print "Highest"
  for (index = 0 to count)
  begin
    print person[index].ID
    print person[index].name
    print person[index].average
    print person[index].highest
  end
  PrintLine()
end

function Average(integer count, employee1 person[])
begin
  for (index = 0 to count)
  begin
    total = 0
    for (index2 = 0 to RECS)
    begin
      total = total + person[index].sales[index2]
    end
    person[index].average = total/RECS
  end
end

function QAverage(integer count, employee1 person[], real average[])
begin
  for (index = 0 to RECS)
  begin
    qtotal = 0
    for (index2 = 0 to count)
    begin
      qtotal = qtotal + person[index2].sales[index]
    end
    average[index] = qtotal/count
  end
end

function Highest(integer count, employee1 person[])
begin
  for (index = 0 to count)
  begin
    person[index].highest = 0
    for (index2 = 0 to RECS)
    begin
      if (person[index].sales[index2] > person[index].highest)
      begin
        person[index].highest = person[index].sales[index2]
      end
    end
  end
end

function QHighest(integer count, employee1 person[], real highest[])
begin
  int index
      index2
  for (index = 0 to RECS)
  begin
    highest[index] = 0
    for (index2 = 0 to count)
    begin
      if (person[index2].sales[index] > highest[index])
      begin
        highest[index] = person[index2].sales[index]
      end
    end
  end
end

function SelectionSortName(employee1 person[], integer n)
begin
  for (i = 0 to n-1)
  begin
    index = i
    for (j = i + 1 to n)
    begin
      if (person[j].name < person[index].name)
      begin
        index = j
      end
    end
    temp = person[index]
    person[index] = person[i]
    person[i] = temp
  end
end

function BinSearch(employee1 person[], string key, integer count)
begin
  last = count
  first = 0
  while (first <= last)
  begin
    mid = (first + last)/2
    if (key == person[mid].name)
    begin
      return mid
    end
    else
    if (key > person[mid].name)
    begin
      first = mid + 1
    end
    else
    begin
      last = mid - 1
    end
  end
  return -1
end
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 20;
const int RECS = 4;

typedef
struct employee
{
  int ID;
  string name,
         first,
         last;
  double sales[RECS],
         average,
         highest;
} employee1;

void PrintHeader();

void PrintAsterisks();

void PrintLine();

int PrintMenu();

void PrintReport(int count, employee1 person[]);

void PrintSummary(int count, employee1 person[]);

void PrintRecord(int count, employee1 person[]);

void Average(int count, employee1 person[]);

void QAverage(int count, employee1 person[], double average[]);

void Highest(int count, employee1 person[]);

void QHighest(int count, employee1 person[], double highest[]);

void SelectionSortName(employee1 person[], int n);

int BinSearch(employee1 person[], string key, int count);

int main()
{
  int mcount,                        // Number of employees
      index,                         // 1st dimension array position
      op;                            // Operation user wants to perform
  employee1 person[MAX],             // Input data structure
            person2[MAX];            // Copy of the input data struct
  ifstream input("amts.data");       // The input file amts.data
  cout<<fixed<<showpoint<<setprecision(2);
  mcount = 0;
  input>>person[mcount].ID;
  while (!input.eof())
  {
    input>>person[mcount].first;
    input>>person[mcount].last;
    person[mcount].name = person[mcount].last + ", " +
    person[mcount].first;
    for (index = 0; index < RECS; index++)
    {
      input>>person[mcount].sales[index];
    }
    mcount++;
    input>>person[mcount].ID;
  }
  Average(mcount, person);
  Highest(mcount, person);
  for (index = 0; index < mcount; index++)
  {
    person2[index] = person[index];
  }
  op = 0;
  while (op != 4)
  {
    op = PrintMenu();
    switch(op)
    {
      case 1:
      PrintReport(mcount, person2);
      break;
      case 2:
      PrintSummary(mcount, person);
      break;
      case 3:
      PrintRecord(mcount, person);
      break;
      case 4:
      break;
      default:
      cout<<"Invalid selection. Please try again."<<endl;
      op = PrintMenu();
      break;
    }
  }
  return 0;
}

/*
Purpose: This function prints the header
*/
void PrintHeader()
{
  PrintAsterisks();
  cout<<"                  Wonderful World of Widgets Company"<<endl;
  cout<<"                           Quarterly Sales Report"<<endl;
  cout<<"                               Dec 4, 2008"<<endl;
  PrintAsterisks();
  PrintLine();
}

/*
Purpose: This function prints asterisks and a new line
*/
void PrintAsterisks()
{
  cout<<"*****************************************************************"<<endl;
}

/*
Purpose: This function prints a line
*/
void PrintLine()
{
  cout<<"-----------------------------------------------------------------"<<endl;
}

/*
Purpose: This function prints a menu and prompts the user to make a selection
Output: Returns inputed option to main
*/
int PrintMenu()
{
  int option;
  cout<<"1. Print Singular Report"<<endl;
  cout<<"2. Print Complete Report"<<endl;
  cout<<"3. Print Record"<<endl;
  cout<<"4. Exit"<<endl;
  cout<<"Enter selection: ";
  cin>>option;
  return option;
}

/*
Purpose: This function prints single employee's report by prompting for a name and searching for that name
Input: This function receives count and person from main
*/
void PrintReport(int count, employee1 person[])
{
  string last,                      // Person's last name
         first;                     // Person's first name
  int index,                        // 1st dimension array position
      index2;                       // 2nd dimension array position
  cout<<"Enter a name in the format Firstname Lastname: ";
  cin>>first>>last;
  PrintHeader();
  SelectionSortName(person, count);
  index = BinSearch(person, last + ", " + first, count);
  if (index == -1)
  {
    cout<<first + " " + last + " not found"<<endl;
  }
  else
  {
    cout<<"ID";
    cout<<setw(14)<<"Name";
    cout<<setw(18)<<"Average";
    cout<<setw(10)<<"Highest"<<endl;

    cout<<person[index].ID<<"   ";
    cout<<left<<setw(16)<<person[index].name;
    cout<<right<<setw(11)<<person[index].average;
    cout<<setw(10)<<person[index].highest<<endl;
  }
  PrintLine();
}

/*
Purpose: This function prints a summary of all employees and the highest and averages sales of
each quarter
Input: This function receives count and person from main
*/
void PrintSummary(int count, employee1 person[])
{
  int index,                       // 1st dimension array position
      index2;                      // 2nd dimension array position
  double average[RECS],            // Average sales of each quarter
         highest[RECS];            // Highest sales of each quarter
  PrintHeader();
  cout<<"ID"<<setw(14)<<"Name"<<setw(18);
  cout<<"Quarter 1"<<setw(10)<<"Quarter 2"<<setw(10);
  cout<<"Quarter 3"<<setw(10)<<"Quarter 4"<<endl;
  PrintLine();
  for (index = 0; index < count; index++)
  {
    cout<<person[index].ID<<"   ";
    cout<<left<<setw(16)<<person[index].name;
    for (index2 = 0; index2 < RECS; index2++)
    {
      cout<<right<<setw(10)<<person[index].sales[index2];
    }
    cout<<endl;
  }
  QHighest(count, person, highest);
  QAverage(count, person, average);
  for (index = 0; index < RECS; index++)
  {
    cout<<"The average sales amount for quarter "<<index+1;
    cout<<" is "<<average[index]<<endl;
    cout<<"The highest sales amount for quarter "<<index+1;
    cout<<" is "<<highest[index]<<endl;
  }
  PrintLine();
}

/*
Purpose: This function prints prints all employees with their average
and highest sales
Input: This function receives count and person from main
*/
void PrintRecord(int count, employee1 person[])
{
  int index,                         // 1st dimension array position
      index2;                        // 2nd dimension array position
  PrintHeader();
  cout<<"ID";
  cout<<setw(14)<<"Name";
  cout<<setw(18)<<"Average";
  cout<<setw(10)<<"Highest"<<endl;
  for (index = 0; index < count; index++)
  {
    cout<<person[index].ID<<"   ";
    cout<<left<<setw(16)<<person[index].name;
    cout<<right<<setw(11)<<person[index].average;
    cout<<setw(10)<<person[index].highest<<endl;
  }
  PrintLine();
}

/*
Purpose: This function does the average for each sales person
Input: This function receives count and person from main
Output: Returns the average the struct array
*/
void Average(int count, employee1 person[])
{
  double total;                        // Employee's total
  int index,                           // 1st dimension array position
      index2;                          // 2nd dimension array position
  for (index = 0; index < count; index++)
  {
    total = 0;
    for (index2 = 0; index2 < RECS; index2++)
    {
      total = total + person[index].sales[index2];
    }
    person[index].average = total/RECS;
  }
}

/*
Purpose: This function calculates the quarterly average
Input: This function receives count, person, and average from main
Output: Returns the average to main
*/
void QAverage(int count, employee1 person[], double average[])
{
  double qtotal;                       // Quarterly total
  int index,                           // 1st dimension array position
      index2;                          // 2nd dimension array position
  for (index = 0; index < RECS; index++)
  {
    qtotal = 0;
    for (index2 = 0; index2 < count; index2++)
    {
      qtotal = qtotal + person[index2].sales[index];
    }
    average[index] = qtotal/count;
  }
}

/*
Purpose: This function calculates the highest sale total for each employee
Input: This function receives count and person struct array from main
Ouput: Highest sale total for each employee
*/
void Highest(int count, employee1 person[])
{
  int index,                           // 1st dimension array position
      index2;                          // 2nd dimension array position
  for (index = 0; index < count; index++)
  {
    person[index].highest = 0;
    for (index2 = 0; index2 < RECS; index2++)
    {
      if (person[index].sales[index2] > person[index].highest)
      {
        person[index].highest = person[index].sales[index2];
      }
    }
  }
}

/*
Purpose: This function calculates the highest sale total for each quarter
Input: This function receives count, person struct array, and highest from main
Ouput: Highest sale total for each quarter
*/
void QHighest(int count, employee1 person[], double highest[])
{
  int index,                           // 1st dimension array position
      index2;                          // 2nd dimension array position
  for (index = 0; index < RECS; index++)
  {
    highest[index] = 0;
    for (index2 = 0; index2 < count; index2++)
    {
      if (person[index2].sales[index] > highest[index])
      {
        highest[index] = person[index2].sales[index];
      }
    }
  }
}

/*
Purpose: This function sorts records by name
Input: This function receives n (count), and person struct array from main
Ouput: Array of structs are modified and sorted by name after function is run
*/
void SelectionSortName(employee1 person[], int n)
{
  int i,                         // 1st dimension array position
      j,                         // 2nd dimension array position
      index;                     // 1st dimension array position
  employee1 temp;                // Temporary variable for record swap
  for (i = 0; i < n-1; i++)
  {
    index = i;
    for (j = i + 1; j < n; j++)
    {
      if (person[j].name < person[index].name)
      {
        index = j;
      }
    }
    temp = person[index];
    person[index] = person[i];
    person[i] = temp;
  }
}

/*
Purpose: This function searches for a record using the name as the key
Input: This function receives name and count from main and key from
PrintReport
Output: Returns the location of the record if matches or -1 otherwise
*/
int BinSearch(employee1 person[], string key, int count)
{
  int first,                  // Starting Point
      mid,                    // Midpoint
      last;                   // Endpoint
  last = count;
  first = 0;
  while (first <= last)
  {
    mid = (first + last)/2;
    if (key == person[mid].name)
    {
      return mid;
    }
    else
    if (key > person[mid].name)
    {
      first = mid + 1;
    }
    else
    {
      last = mid - 1;
    }
  }
  return -1;
}
