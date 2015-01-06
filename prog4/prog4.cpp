/*
Chris McKnight
Barbara Guillot
cs1253 Sec 1
cs125326

Specify the Requirement:
Calculate wait times for Rouge Bank 24-hour drive up

Data Analysis:
Constants:
Name        Type       Scope         Content
MAX         integer    global        Static number of records for arrays
MINUTES     integer    global        Time constant for minutes per hour, 60
SECONDS     integer    global        Time constant for second per minute, 60

Variables:
input       file       main          The input file time.data
out         file       main          The output file out.data
count       integer    main          Number of people served
                       PrintTable
                       PrintSummary
                       CalcWait
                       Avg
                       Highest
                       Lowest
                       CalcDev
ID[]        integer    main          ID numbers of tellers
                       PrintTable
arrih[]     array      main          Arrival time hour
                       CalcWait
arrim[]     array      main          Arrival time minutes
                       CalcWait
arris[]     array      main          Arrival time seconds
                       CalcWait
servh[]     array      main          Served time hour
                       CalcWait
servm[]     array      main          Served time minutes
                       CalcWait
servs[]     array      main          Served time seconds
                       CalcWait
arri[]      array      main          Arrival times in seconds
                       CalcWait
serv[]      array      main          Served times in seconds
                       CalcWait
wait[]      array      main          Wait times in seconds
                       PrintTable
                       CalcWait
                       Avg
                       Highest
                       Lowest
                       CalcDev
total       integer    main          Total of the wait times
                       CalcWait
                       Avg
sum         real       CalcDev       The sum of wait times squared
avg         real       main          Average of the wait times
                       PrintSummary
                       Avg
                       CalcDev
range       integer    main          The range of the wait times
                       PrintSummary
                       CalcRange
shortest    integer    main          The shortest wait time
                       Lowest
                       CalcRange
longest     integer    main          The longest wait time
                       Highest
                       CalcRange
stdev       real       main          The standard deviation of the wait times
                       PrintSummary
                       CalcDev
index       integer    PrintTable    The index of the arrays
                       calcWait
                       Highest
                       Lowest
                       CalcDev

Problem Analysis:
Print table headings
Read data into arrays while not eof
Calculate the wait times in seconds
Print the table of arrival, service, and wait times
Calculate the average wait time
Calculate the longest wait time
Calculate the shortest wait time
Calculate the range
Calculate the standard deviation
Print the summary

Algorithm:
function main
begin
  open file input for reading
  open file out for writing
  PrintHeader(out)
  count = 0
  total = 0
  shortest = 100000000
  longest = -100000000
  read ID[count] from file input
    while not EOF
    begin
      read arrih[count], arrim[count] from file input
      read  arris[count] from file input
      read servh[count], servm[count] from file input
      read servs[count] from file input
      count = count + 1
      read ID[count] from file input
    end
  CalcWait(count, arrih, arrim, arris, servh, servm, servs,
  arri, serv, wait, total)
  PrintTable(out, ID, count, wait, arri, serv);
  avg = Avg(count, total)
  Highest(count, wait, longest)
  Lowest(count, wait, shortest)
  range = CalcRange(longest, shortest)
  stdev = CalcDev(count, avg, wait)
  PrintSummary(out, count, avg, range, stdev)
  close the file input
  close the file out
end

function PrintHeader(file *out)
begin
  PrintAsterisks(out) to file out
  print "Rouge Bank" to file out
  print "Wait Times Report" to file out
  print "10-21-2008" to file out
  PrintLine(out)
  print "ID" to file out
  print "Arrival" to file out
  print "Service" to file out
  print "Wait Time" to file out
end

function PrintAsterisks(file *out)
begin
  print "*****************" to file out
end

function PrintLine(file *out)
begin
  print "---------------------" to file out
end

function PrintTable(file *out, integer ID[], integer count, integer wait[],
integer arri[], integer serv[])
begin
  for index = 0 to count
  begin
    print ID[index] to file out
    print arri[index] to file out
    print serv[index] to file out
    print wait[index] to file out
  end
end

function PrintSummary(file *out, integer count, real avg, integer range,
real stdev)
begin
  PrintLine(out)
  print "The total number of records: ", count to file out
  print "The average wait time is ", avg to file out
  print"The range of wait times is ", range to file out
  print "The standard deviation is ", stdev to file out
end

function CalcWait(integer count, integer arrih[], integer arrim[],
integer arris[], integer servh[],integer servm[], integer servs[],
integer arri[], integer serv[], integer wait[], integer *total)
begin
  for index = 0 to count
  begin
    arri[index] = (arrih[index]*MINUTES*SECONDS) +
    (arrim[index]*SECONDS) + arris[index];
    serv[index] = (servh[index]*MINUTES*SECONDS) +
    (servm[index]*SECONDS) + servs[index];
    wait[index] = serv[index]-arri[index];
    total = total + wait[index];
  end
end

function Avg(integer count, integer total)
begin
  avg = total/count;
end

function Highest(integer count, integer wait[], integer *longest)
begin
  for index = 0 to count
  begin
    if (wait[index] > longest)
    then longest = wait[index]

  end
end

function Lowest(integer count, integer wait[], integer *shortest)
begin
  for index = 0 to count
  begin
    if (wait[index] < shortest)
    then shortest = wait[index]
  end
end

function CalcRange(integer longest, integer shortest)
begin
  range = longest-shortest
end

function CalcDev(integer count, real avg, integer wait[])
begin
  sum = 0
  for index = 0 to count
  begin
    sum = sum + (wait[index]-avg))^2
  end
  stdev = sqrt(sum/(count-1))
end
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

const int MAX = 20;                 // Static number of records for arrays
const int MINUTES = 60;             // Time constant for minutes per hour, 60
const int SECONDS = 60;             // Time constant for second per minute, 60

void PrintHeader(ofstream &out);

void PrintAsterisks(ofstream &out);

void PrintLine(ofstream &out);

void PrintTable(ofstream &out, int ID[], int count, int wait[],
int arri[], int serv[]);

void PrintSummary(ofstream &out, int count, double avg, int range,
double stdev);

void CalcWait(int count, int arrih[], int arrim[],
int arris[], int servh[], int servm[], int servs[], int arri[],
int serv[], int wait[], int &total);

double Avg(int count, int total);

void Highest(int count, int wait[], int &longest);

void Lowest(int count, int wait[], int &shortest);

int CalcRange(int longest, int shortest);

double CalcDev(int count, double avg, int wait[]);

int main()
{
  int ID[MAX],                    // ID numbers of tellers
      arrih[MAX],                 // Arrival time hour
            arrim[MAX],                 // Arrival time minutes
            arris[MAX],                 // Arrival time seconds
            servh[MAX],                 // Served time hour
            servm[MAX],                 // Served time minutes
            servs[MAX],                 // Served time seconds
      arri[MAX],                  // Arrival times in seconds
      serv[MAX],                  // Served times in seconds
      wait[MAX],                  // Wait times in seconds
      count,                      // Number of people served
      shortest,                   // The shortest wait time
      longest,                    // The longest wait time
      total,                      // Total of the wait times
      range;                      // Range of the wait times
  double avg,                     // Average of the wait times
         stdev;                   // Standard deviation of wait times
  ifstream input("time.data");
  ofstream out("out.data");
  out<<fixed<<setprecision(2);
  PrintHeader(out);
  shortest = 10000000;
  longest = -10000000;
  count = 0;
  total = 0;
  input>>ID[count];
  while(!input.eof())
  {
    input>>arrih[count]>>arrim[count]>>arris[count];
    input>>servh[count]>>servm[count]>>servs[count];
    count = count + 1;
    input>>ID[count];
  }
  CalcWait(count, arrih, arrim, arris, servh, servm, servs,
  arri, serv, wait, total);
  PrintTable(out, ID, count, wait, arri, serv);
  avg = Avg(count, total);
  Highest(count, wait, longest);
  Lowest(count, wait, shortest);
  range = CalcRange(longest, shortest);
  stdev = CalcDev(count, avg, wait);
  PrintSummary(out, count, avg, range, stdev);
  input.close();
  out.close();
  return 0;
}

/*
Purpose: Prints the table headings
Input: This function receives out from main
*/
void PrintHeader(ofstream &out)
{
  PrintAsterisks(out);
  out<<"               Rouge Bank"<<endl;
  out<<"            Wait Times Report"<<endl;
  out<<"               10-21-2008"<<endl;
  PrintAsterisks(out);
  out<<"ID"<<setw(10);
  out<<"Arrival"<<setw(10);
  out<<"Service"<<setw(14);
  out<<"Wait Time"<<endl;
  PrintLine(out);
}

/*
Purpose: Prints the asterisk line to the file out.data
Input: This function receives out from main
*/
void PrintAsterisks(ofstream &out)
{
  out<<"*****************************************"<<endl;
}

/*
Purpose: Prints dashes to separate areas of the table to file out.data
Input: This function receives out from main
*/
void PrintLine(ofstream &out)
{
  out<<"-----------------------------------------"<<endl;
}

/*
Purpose: Prints the data in the form of a table
Input: This function receives out, ID[], count, wait[], arri[],
and serv[] from main
*/
void PrintTable(ofstream &out, int ID[], int count, int wait[],
int arri[], int serv[])
{
  int index;                                  // The index of the arrays
  for (index = 0; index < count; index++)
  {
    out<<ID[index]<<"    ";
    out<<arri[index]<<setw(10);
    out<<serv[index]<<setw(10);
    out<<wait[index]<<endl;
  }
}

/*
Purpose: Prints the summary to the file out.data
Input: This function receives out, count, avg, range, and stdev from main
*/
void PrintSummary(ofstream &out, int count, double avg, int range,
double stdev)
{
  PrintLine(out);
  out<<"The total number of records: "<<count<<endl;
  out<<"The average wait time is "<<avg<<" seconds"<<endl;
  out<<"The range of wait times is "<<range<<" seconds"<<endl;
  out<<"The standard deviation is "<<stdev<<endl;
}

/*
Purpose: Calculates the wait times, arrival times, and served times in
seconds and returns them to main
Input: This function receives count, arrih[], arrim[], arris[],
servh[], servm[], servs[], arri[], serv[], wait[], and
a reference to total from main
Output: Returns the calculated wait times, wait[], arrival times converted
to seconds, arri[], and converted served times, serv[], to main
*/
void CalcWait(int count, int arrih[], int arrim[], int arris[],
int servh[],int servm[], int servs[], int arri[], int serv[],
int wait[], int &total)
{
  int index;                                // The index of the arrays
  for (index = 0; index < count; index++)
  {
    arri[index] = (arrih[index]*MINUTES*SECONDS) +
    (arrim[index]*SECONDS) + arris[index];
    serv[index] = (servh[index]*MINUTES*SECONDS) +
    (servm[index]*SECONDS) + servs[index];
    wait[index] = serv[index]-arri[index];
    total = total + wait[index];
  }
}

/*
Purpose: Calculates the average wait time
Input: This function receives count and total from main
Output: Returns avg, which is the average, to main
*/
double Avg(int count, int total)
{
  double avg;                  // Average of the wait times
  avg = total/count;
  return avg;
}

/*
Purpose: Finds the highest wait time and returns it to main
Input: This function receives count and wait[] from main
Output: This function returns the highest wait time to main
*/
void Highest(int count, int wait[], int &longest)
{
  int index;                               // The index of the arrays
  for (index = 0; index < count; index++)
  {
    if (wait[index] > longest)
    {
      longest = wait[index];
    }
  }
}

/*
Purpose: Finds he lowest wait time and returns it to main
Input: This function receives count and wait[] from main
Output: Returns the lowest wait time to main
*/
void Lowest(int count, int wait[], int &shortest)
{
  int index;                               // The index of the arrays
  for (index = 0; index < count; index++)
  {
    if (wait[index] < shortest)
    {
      shortest = wait[index];
    }
  }
}

/*
Purpose: Calculates the range of the wait time
Input: This function receives longest and shortest from main
Output: Returns the range to main
*/
int CalcRange(int longest, int shortest)
{
  int range;                     // Range of the wait times
  range = longest-shortest;
  return range;
}

/*
Purpose: Calculates the standard deviation of the wait times
Input: This function receives count, avg, and wait[] from main
Output: Returns the standard deviation to main
*/
double CalcDev(int count, double avg, int wait[])
{
  int index;                  // The index of the arrays
  double sum,                 // The sum of wait times squared
         stdev;               // Standard deviation of wait times
  sum = 0;
  for (index = 0; index < count; index++)
  {
    sum = sum + pow((wait[index]-avg),2);
  }
  stdev = sqrt(sum/(count-1));
  return stdev;
}
