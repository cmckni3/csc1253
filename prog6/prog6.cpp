/*
Chris McKnight
Barbara Guillott
cs1253 Sec 1
cs125326

Specify the requirement:
Calculate weekly totals for sales, the highest sales of each week and allow printing of singular and summary reports

Data Analysis:
Name            Type     Scope               Content
Constants:
MAX             integer  global              Static number of elements in array
RECS            integer  global              Number of weeks
SALE            real     global              Sale price of 1 product, 175.95

Variables:
wolf            file     main                Input file wolfe.data
last            string   main                Last name of employee
first           string   main                First name of employee
name[]          string   main                Lastname, firstname of each employee
sales[][]       integer  main                Amount of products sold by week
mcount          integer  main                Number of employees
weeksales[][]   real     main                Amount of money made from selling products by week
totals[]        real     main                Employees' total sales for all 4 weeks
highest[]       real     main                Highest weekly product sales total
op              integer  main                Operation user wants to perform
count           integer  PrintReport         Number of employees
                         PrintSummary
                         CalcSales
                         Highest
                         BinSearch
key             string   BinSearch           Name to search for in records
n               integer  SelectionSort       Number of employees
                         SelectionSortName
index           integer  PrintReport         1st dimension array position
                         PrintSummary
                         Highest
                         SelectionSort
                         SelectionSortName
index2          integer  PrintSummary        2nd dimension array position
                         CalcSales
			 Highest
                         SelectionSort
			 SelectionSortName
option          integer  PrintMenu           Operation user wants to perform

Problem Analysis:
open file wolf for reading
read first, last, sales data while not eof
prompt for report to print while not told to exit
	calculate sales
	sort according to report
	print header for report
	print report
close file wolf


Algorithm:
function main
begin
	open file wolf for reading
	mcount = 0
	read first
	while not eof
	begin
		read last
		name[mcount] = last + ", " + first
		for (index = 0 to RECS)
		begin
			read sales[mcount][index]
		end
		mcount = mcount + 1
		read first
	end
	CalcSales(mcount, sales, weeksales, totals)
	Highest(mcount, highest, weeksales)
	while (op <> 3)
	end
		op = PrintMenu()
		switch(op)
		begin
			case 1:
			PrintHeader()
			SelectionSort(totals, mcount, name, sales, weeksales)
			PrintSummary(mcount, weeksales, name, totals, highest)
			case 2:
			SelectionSortName(name, mcount, totals, sales, 
			weeksales)
			PrintReport(name, weeksales, totals, mcount)
			case 3:
			default:
			print "Invalid selection. Please try again."
			op = PrintMenu()
		end
	end
	return 0
	close file wolf
end

function PrintHeader()
begin
	PrintAsterisks()
	print "Wolfe Manufacturing Company"
	print "Weekly Sales Report"
	print "Nov 6, 2008"
	PrintAsterisks()
end

function PrintAsterisks()
begin
	print "***********************************************************************"
end

void PrintLine()
begin
	print "-----------------------------------------------------------------------"
end

function PrintMenu()
begin
	print "1. Print Report"
	print "2. Find Record"
	print "3. Exit"
	print "Enter selection: "
	read option
	return option
end

function PrintReport(string name[], real weeksales[][RECS],
real totals[], integer count)
begin
	print "Please, enter a name to search for in the 
	format firstname lastname: "
	read first
	read last
	PrintHeader()
	PrintLine()
	index = BinSearch(name, last + ", " + first, count)
	if (index = -1)
	begin
		print "Employee not found"
	end
	else
	begin
		print "Name"
		print "Week 1"
		print "Week 2"
		print "Week 3"
		print "Week 4"
		print "Total"
		print name[index]
		for (index2 = 0 to RECS)
		{
			print weeksales[index][index2]
		end
		print totals[index]
	end
	PrintLine()
end

function PrintSummary(integer count, real weeksales[][RECS], string name[],
real totals[], real highest[])
begin
	print "Name"
	print "Week 1"
	print "Week 2"
	print "Week 3"
	print "Week 4"
	print "Total"
	PrintLine()
	for (index = 0 to count)
	begin
		print name[index]
		for (index2 = 0 to RECS)
		begin
			print weeksales[index][index2]
		end
		print totals[index]
	end
	PrintLine()
	for (index = 0 to RECS)
	begin
		print "The highest sales was ", highest[index]"
		print " for week ", index+1
	end
	PrintLine()
end

function CalcSales(integer count, integer sales[][RECS],
real weeksales[][RECS], real totals[])
begin
	for (index = 0 to count)
	begin
		totals[index] = 0
		for (index2 = 0 to RECS)
		begin
			weeksales[index][index2] = sales[index][index2]*SALE
			totals[index] = totals[index] 
			+ weeksales[index][index2]
		end
	end
end

function Highest(integer count, real highest[], real weeksales[][RECS])
begin
	for (index = 0 to RECS)
	begin
		highest[index] = 0
		for (index2 = 0 to count)
		begin
			if (weeksales[index2][index] > highest[index])
			begin
				highest[index] = weeksales[index2][index]
			end
		end
	end
end

function SelectionSort(real totals[], integer n, string name[],
integer sales[][RECS], real weeksales[][RECS], real highest[])
begin
	for (i = 0 to n-1)
	begin
		index = i
		for (j = i + 1 to n)
		begin
			if (totals[j] < totals[index])
			begin
				index = j
			end
		end
		temp = totals[index]
		totals[index] = totals[i]
		totals[i] = temp
		sztemp = name[index]
		name[index] = name[i]
		name[i] = sztemp
		for (index2 = 0 to RECS)
		begin
			dtemp = sales[index][index2]
			sales[index][index2] = sales[i][index2]
			sales[i][index2] = dtemp
		end
		for (index2 = 0 to RECS)
		begin
			weektemp = weeksales[index][index2]
			weeksales[index][index2] = weeksales[i][index2]
			weeksales[i][index2] = weektemp
		end
	end
end

function SelectionSortName(string name[], integer n, real totals[],
integer sales[][RECS], real weeksales[][RECS], real highest[])
begin
	for (i = 0 to n-1)
	begin
		index = i
		for (j = i + 1 to n)
		begin
			if (name[j] < name[index])
			begin
				index = j
			end
		end
		temp = name[index];
		name[index] = name[i]
		name[i] = temp
		ftemp = totals[index]
		totals[index] = totals[i]
		totals[i] = ftemp
		for (index2 = 0 to RECS)
		begin
			dtemp = sales[index][index2]
			sales[index][index2] = sales[i][index2]
			sales[i][index2] = dtemp
		end
		for (index2 = 0 to RECS)
		begin
			weektemp = weeksales[index][index2]
			weeksales[index][index2] = weeksales[i][index2]
			weeksales[i][index2] = weektemp
		end
	end
end

function BinSearch(string name[], string key, integer count)
begin
	last = count
	first = 0
	while (first <= last)
	begin
		mid = (first + last)/2
		if (key = name[mid])
		begin
			return mid
		end
		else
		if (key > name[mid])
		begin
			first = mid + 1
		end
		else
		begin
			last = mid - 1
		end
	end
	return -1;
end
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 20;                          // Static number of elements in array
const int RECS = 4;                          // Number of weeks
const double SALE = 175.95;                  // Sale price of 1 product, 175.95

void PrintHeader();

void PrintAsterisks();

void PrintLine();

int PrintMenu();

void PrintReport(string name[], double weeksales[][RECS],
double totals[], int count);

void PrintSummary(int count, double weeksales[][RECS], string name[],
double totals[], double highest[]);

void CalcSales(int count, int sales[][RECS], double weeksales[][RECS],
double totals[]);

void Highest(int count, double highest[], double weeksales[][RECS]);

void SelectionSort(double totals[], int n, string name[],
int sales[][RECS], double weeksales[][RECS]);

void SelectionSortName(string name[], int n, double totals[],
int sales[][RECS], double weeksales[][RECS]);

int BinSearch(string name[], string key, int count);

int main()
{
	string last,                               // Last name of employee
	       first,                              // First name of employee
	       name[MAX];                          // Lastname, firstname of employee
	int sales[MAX][RECS],                      // Amount of products sold by week
	    mcount,                                // Number of employees
	    op;                                    // Operation user wants to perform
	double weeksales[MAX][RECS],               // Amount of money made from selling products by week
	       totals[MAX],                        // Employees' total sales for all 4 weeks
	       highest[MAX];                       // Highest weekly product sales total
	ifstream wolf("wolf.data");                // File wolfe.data
	cout<<fixed<<showpoint<<setprecision(2);
	mcount = 0;
	wolf>>first;
	while (!wolf.eof())
	{
		wolf>>last;
		name[mcount] = last + ", " + first;
		int index;
		for (index = 0; index < RECS; index++)
		{
			wolf>>sales[mcount][index];
		}
		mcount++;
		wolf>>first;
	}
	CalcSales(mcount, sales, weeksales, totals);
	Highest(mcount, highest, weeksales);
	op = 0;
	while (op != 3)
	{
		op = PrintMenu();
		switch(op)
		{
			case 1:
			PrintHeader();
			SelectionSort(totals, mcount, name, sales, weeksales);
			PrintSummary(mcount, weeksales, name, totals, highest);
			break;
			case 2:
			SelectionSortName(name, mcount, totals, sales,
			weeksales);
			PrintReport(name, weeksales, totals, mcount);
			break;
			case 3:
			break;
			default:
			cout<<"Invalid selection. Please try again."<<endl;
			op = PrintMenu();
			break;
		}
	}
	wolf.close();
	return 0;
}

/*
Purpose: This function prints the header of the report
Input: This function takes no arguments
*/
void PrintHeader()
{
	PrintAsterisks();
	cout<<"                     Wolfe Manufacturing Company"<<endl;
	cout<<"                        Weekly Sales Report"<<endl;
	cout<<"                           Nov 6, 2008"<<endl;
	PrintAsterisks();
}

/*
Purpose: This functions prints the asterisk line and a new line
Input: This function takes no arguments
*/
void PrintAsterisks()
{
	cout<<"***********************************************************************"<<endl;
}

/*
Purpose: This function prints dashes and a new line
Input: This function takes no arguments
*/
void PrintLine()
{
	cout<<"-----------------------------------------------------------------------"<<endl;
}

/*
Purpose: This function prints the menu and prompts the user
Input: This function takes no arguments
Output: This function returns the user's input to main
*/
int PrintMenu()
{
	int option;                         // Operation user wants to perform
	cout<<"1. Print Report"<<endl;
	cout<<"2. Find Record"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"Enter selection: ";
	cin>>option;
	return option;
}

/*
Purpose: This function prints the singular report by prompting the user 
for a name and finding the name and record
Input: This function receives name, weeksales, totals, and count from main
*/
void PrintReport(string name[], double weeksales[][RECS],
double totals[], int count)
{
	string first,
	       last;
	int index,                            // 1st dimension array position
	    index2;                           // 2nd dimension array position
	cout<<"Please, enter a name to search for ";
	cout<<"in the format firstname lastname: "<<endl;
	cin>>first>>last;
	PrintHeader();
	PrintLine();
	index = BinSearch(name, last + ", " + first, count);
	if (index == -1)
	{
		cout<<"Employee not found"<<endl;
	}
	else
	{
		cout<<setw(9)<<"Name"<<setw(18);
		cout<<"Week 1"<<setw(10);
		cout<<"Week 2"<<setw(10);
		cout<<"Week 3"<<setw(10);
		cout<<"Week 4"<<setw(10);
		cout<<"Total"<<setw(10)<<endl;
		cout<<left<<setw(18)<<name[index];
		for (index2 = 0; index2 < RECS; index2++)
		{
			cout<<right<<setw(10)<<weeksales[index][index2];
		}
		cout<<right<<setw(10)<<totals[index]<<endl;
	}
	PrintLine();
}

/*
Purpose: This function prints an overall summary of the employees with 
each weeks' totals and their overal total and the highest of each week
Input: This function receives count, weeksales, name, totals, and highest 
from main
*/
void PrintSummary(int count, double weeksales[][RECS], string name[],
double totals[], double highest[])
{
	int index,                       // 1st dimension array position
	    index2;                      // 2nd dimension array position
	cout<<setw(9)<<"Name"<<setw(18);
	cout<<"Week 1"<<setw(10);
	cout<<"Week 2"<<setw(10);
	cout<<"Week 3"<<setw(10);
	cout<<"Week 4"<<setw(10);
	cout<<"Total"<<setw(10)<<endl;
	PrintLine();
	for (index = 0; index < count; index++)
	{
		cout<<left<<setw(18)<<name[index];
		for (index2 = 0; index2 < RECS; index2++)
		{
			cout<<right<<setw(10)<<weeksales[index][index2];
		}
		cout<<right<<setw(10)<<totals[index]<<endl;
	}
	PrintLine();
	for (index = 0; index < 4; index++)
	{
		cout<<"The highest sales was "<<highest[index];
		cout<<" for week "<<index+1<<endl;
	}
	PrintLine();
}

/*
Purpose: This function calculates the sales for each week and the total 
sales for each employee
Input: This function receives count, sales, weeksales, totals, and highest 
from main
Output: Total for each employee and sales total by week
*/
void CalcSales(int count, int sales[][RECS], double weeksales[][RECS],
double totals[])
{
	int index,                               // 1st dimension array position
	    index2;                              // 2nd dimension array position
	for (index = 0; index < count; index++)
	{
		totals[index] = 0;
		for (index2 = 0; index2 < RECS; index2++)
		{
			weeksales[index][index2] = sales[index][index2]*SALE;
			totals[index] = totals[index] +
			weeksales[index][index2];
		}
	}
}

/*
Purpose: This function calculates the highest sale total for each week
Input: This function receives count, highest, and weeksales from main
Ouput: Highest sale total for each week
*/
void Highest(int count, double highest[], double weeksales[][RECS])
{
	int index,                              // 1st dimension array position
	    index2;                             // 2nd dimension array position
	for (index = 0; index < RECS; index++)
	{
		highest[index] = 0;
		for (index2 = 0; index2 < count; index2++)
		{
			if (weeksales[index2][index] > highest[index])
			{
				highest[index] = weeksales[index2][index];
			}
		}
	}
}

/*
Purpose: This function sorts the records by total
Input: This function receives totals, n, name, sales, and weeksales from 
main
Ouput: Array are modified and are sorted by total after function runs
*/
void SelectionSort(double totals[], int n, string name[],
int sales[][RECS], double weeksales[][RECS])
{
	int i,                             // 1st dimension array position
	    j,                             // 2nd dimension array position
	    index,                         // 1st dimension array position
	    index2;                        // Array position
	double temp;                       // Temp var for totals
	string sztemp;                     // Temp var for name
	double weektemp;                   // Temp var for week product sales
	int dtemp;                         // Temp var for sales by week
	for (i = 0; i < n-1; i++)
	{
		index = i;
		for (j = i + 1; j < n; j++)
		{
			if (totals[j] < totals[index])
			{
				index = j;
			}
		}
		temp = totals[index];
		totals[index] = totals[i];
		totals[i] = temp;
		sztemp = name[index];
		name[index] = name[i];
		name[i] = sztemp;
		for (index2 = 0; index2 < RECS; index2++)
		{
			dtemp = sales[index][index2];
			sales[index][index2] = sales[i][index2];
			sales[i][index2] = dtemp;
		}
		for (index2 = 0; index2 < RECS; index2++)
		{
			weektemp = weeksales[index][index2];
			weeksales[index][index2] = weeksales[i][index2];
			weeksales[i][index2] = weektemp;
		}
	}
}

/*
Purpose: This function sorts records by name
Input: This function receives name, n (count), totals, sales, and 
weeksales from main
Ouput: Arrays are modified and sorted by name after function is run
*/
void SelectionSortName(string name[], int n, double totals[],
int sales[][RECS], double weeksales[][RECS])
{
	int i,                            // 1st dimension array position
	    j,                            // 2nd dimension array position
	    index,                        // 1st dimension array position
	    index2;                       // Array position
	string temp;                      // Temp var for name
	double ftemp,                     // Temp var for totals
	       weektemp;                  // Temp var for week product sales
	int dtemp;                        // Temp var for sales by week
	for (i = 0; i < n-1; i++)
	{
		index = i;
		for (j = i + 1; j < n; j++)
		{
			if (name[j] < name[index])
			{
				index = j;
			}
		}
		temp = name[index];
		name[index] = name[i];
		name[i] = temp;
		ftemp = totals[index];
		totals[index] = totals[i];
		totals[i] = ftemp;
		for (index2 = 0; index2 < RECS; index2++)
		{
			dtemp = sales[index][index2];
			sales[index][index2] = sales[i][index2];
			sales[i][index2] = dtemp;
		}
		for (index2 = 0; index2 < RECS; index2++)
		{
			weektemp = weeksales[index][index2];
			weeksales[index][index2] = weeksales[i][index2];
			weeksales[i][index2] = weektemp;
		}
	}
}

/*
Purpose: This function searches for a record using the name as the key
Input: This function receives name and count from main and key from 
PrintReport
Output: Returns the location of the record if matches or -1 otherwise
*/
int BinSearch(string name[], string key, int count)
{
	int first,                  // Starting Point
	    mid,                    // Midpoint
	    last;                   // Endpoint
	last = count;
	first = 0;
	while (first <= last)
	{
		mid = (first + last)/2;
		if (key == name[mid])
		{
			return mid;
		}
		else
		if (key > name[mid])
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
