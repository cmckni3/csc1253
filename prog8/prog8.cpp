/*
Chris McKnight
Barbara Guillott
cs1253 Sec 1
cs125326

Description:
This program calculates the complexity measure O(n) for bubble sort, selection sort, insertion sort, and merge sort
by sorting a set of student data by ID in ascending order.

Input:
Input is batch from the file stu.data consisting of an ID, gender, weight, height, and age

Output:
Output is to the file stats.out.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 70;                 // Static allocation of array size

// Define the structure
typedef
struct student
{
  int ID,
      height,
      weight,
      age;
  char gender;
} student1;

// Function prototypes
void PrintHeader(ofstream &report, string title);

void PrintLine(ofstream &report);

char PrintMenu();

void BubbleSort(student1 person[], int n, int &bub);

void InsertSort(student1 person[], int n, int &ins);

void SelectSort(student1 person[], int n, int &sel);

void MergeSort(student1 person[], int first, int last, int &mer);

void Merge(student1 person[], int leftfirst, int leftlast, int rightfirst, int rightlast, int &mer);

int main()
{
  int mcount,                      // Number of students
      bub,                         // Counter for bubble sort
      ins,                         // Counter for insertion sort
      sel,                         // Counter for selection sort
      mer,                         // Counter for merge sort
      index;                       // 1st dimension array position
  char op;                         // User's option to run or not
  student1 uary[MAX],             // Unsorted array of data
       bary[MAX],                // Array sorted by bubblesort
       sary[MAX],                // Array sorted by selection sort
       iary[MAX],                // Array sorted by insertion sort
       mary[MAX];                // Array sorted by merge sort
  // Open file for reading
  ifstream input("stu.data");      // The input file ,stu.data
  // Open file for writing
  ofstream report("stats.out");   // The output file, stats.out
  // Load the data structure
  mcount = 0;
  input>>uary[mcount].ID;
  while(!input.eof())
  {
    input>>uary[mcount].gender;
    input>>uary[mcount].height;
    input>>uary[mcount].weight;
    input>>uary[mcount].age;
    mcount++;
    input>>uary[mcount].ID;
  }

  // Copy the unsorted array to other arrays that will be sorted by each sort
  for (index = 0; index < mcount; index++)
  {
    bary[index] = uary[index];
    sary[index] = uary[index];
    iary[index] = uary[index];
    mary[index] = uary[index];
  }

  // Prompt the user to run the system
  op = PrintMenu();
  while (op != 'n')
  {
    // Sort using bubble sort
    bub = 0;
    BubbleSort(bary, mcount, bub);
    PrintHeader(report, "Bubble Sort");
    for (index = 0; index < mcount; index++)
    {
      report<<bary[index].ID<<setw(7);
      report<<bary[index].gender<<setw(10);
      report<<bary[index].height<<setw(10);
      report<<bary[index].weight<<setw(10);
      report<<bary[index].age<<endl;
    }
    report<<endl<<"    Complexity Measure, O(n) = "<<bub<<endl<<endl;

    // Sort using insertion sort
    ins = 0;
    InsertSort(iary, mcount, ins);
    PrintHeader(report, "Insertion Sort");
    for (index = 0; index < mcount; index++)
    {
      report<<iary[index].ID<<setw(7);
      report<<iary[index].gender<<setw(10);
      report<<iary[index].height<<setw(10);
      report<<iary[index].weight<<setw(10);
      report<<iary[index].age<<endl;
    }
    report<<endl<<"    Complexity Measure, O(n) = "<<ins<<endl<<endl;

    // Sort using selection sort
    sel = 0;
    SelectSort(sary, mcount, sel);
    PrintHeader(report, "Selection Sort");
    for (index = 0; index < mcount; index++)
    {
      report<<sary[index].ID<<setw(7);
      report<<sary[index].gender<<setw(10);
      report<<sary[index].height<<setw(10);
      report<<sary[index].weight<<setw(10);
      report<<sary[index].age<<endl;
    }
    report<<endl<<"    Complexity Measure, O(n) = "<<sel<<endl<<endl;

    // Sort using merge sort
    mer = 0;
    MergeSort(mary, 0, mcount-1, mer);
    PrintHeader(report, "Merge Sort");
    for (index = 0; index < mcount; index++)
    {
      report<<mary[index].ID<<setw(7);
      report<<mary[index].gender<<setw(10);
      report<<mary[index].height<<setw(10);
      report<<mary[index].weight<<setw(10);
      report<<mary[index].age<<endl;
    }
    report<<endl<<"    Complexity Measure, O(n) = "<<mer<<endl<<endl;

    op = PrintMenu();
  }
  // Close the files
  input.close();
  report.close();
  return 0;
}

/*
Purpose: This function prints the dashes, report title, and column headings
Input: This function receives report from main
*/
void PrintHeader(ofstream &report, string title)
{
    PrintLine(report);
    report<<"                "<<title<<endl;
    report<<"ID";
    report<<setw(10)<<"Sex";
    report<<setw(10)<<"Height";
    report<<setw(10)<<"Weight";
    report<<setw(10)<<"Weight"<<endl;
    PrintLine(report);
}

/*
Purpose: This function prints dashes a new line
Input: This function receives report and title from main as a pass by reference
*/
void PrintLine(ofstream &report)
{
  report<<"---------------------------------------------------"<<endl;
}

/*
Purpose: This function prompts the user if they want to run the system
Input: This function receives no arguments (parameters)
Output: Returns the user's choice to main
*/
char PrintMenu()
{
  char option;
  cout<<"Would you like to run the system <y for yes, n for no>: ";
  cin>>option;
  return option;
}

/*
Purpose: This function sorts the array using the bubble sort and counts the sequential
and conditional statements
Input: This function receives person[], n, and bub from main
*/
void BubbleSort(student1 person[], int n, int &bub)
{
  int i,                               // 1st dimension array position
      j;                               // 2nd dimension array position
  student1 temp;                      // Temporary variable for record swap
  for (i = 1; i <= n-1; i++)
  {
    for (j = 0; j <= n-2; j++)
    {
      if (person[j].ID > person[j+1].ID)
      {
        temp = person[j];
        person[j] = person[j+1];
        person[j+1] = temp;
        bub = bub + 3;
      }
      bub++;
    }
  }
}

/*
Purpose: This function sorts the array using the insertion sort and counts the sequential
and conditional statements
Input: This function receives person[], n, and ins from main
*/
void InsertSort(student1 person[], int n, int &ins)
{
  int i,                             // 1st dimension array position
      j;                             // 2nd dimension array position
  student1 temp;                    // Temporary variable for record swap
  for (i = 1; i < n; i++)
  {
    temp = person[i];
    j = i;
    ins = ins + 2;
    while ((j > 0) && (temp.ID < person[j-1].ID))
    {
      person[j] = person[j-1];
      ins++;
      j--;
    }
    person[j] = temp;
    ins++;
  }
}

/*
Purpose: This function sorts the array using the selection sort and counts the sequential
and conditional statements
Input: This function receives person[], n, and sel from main
*/
void SelectSort(student1 person[], int n, int &sel)
{
  int i,                         // 1st dimension array position
      j,                         // 2nd dimension array position
      index;                     // 1st dimension array position
  student1 temp;                // Temporary variable for record swap
  for (i = 0; i < n-1; i++)
  {
    index = i;
    sel++;
    for (j = i + 1; j < n; j++)
    {
      if (person[j].ID < person[index].ID)
      {
        index = j;
        sel++;
      }
      sel++;
    }
    temp = person[index];
    person[index] = person[i];
    person[i] = temp;
    sel = sel + 3;
  }
}

/*
Purpose: This function sorts the array using the merge sort and counts the sequential
and conditional statements
Input: This function receives person[], first, last, and mer from main
*/
void MergeSort(student1 person[], int first, int last, int &mer)
{
  int mid;                            // Midpoint of array
  if (first < last)
  {
    mid = (first + last)/2;
    mer++;
    MergeSort(person, first, mid, mer);
    MergeSort(person, mid+1, last, mer);
    Merge(person, first, mid, mid+1, last, mer);
  }
}

/*
Purpose: This function sorts the array using the merge sort and counts the sequential
and conditional statements
Input: This function receives person[], leftfirst, leftlast, rightfirst, rightlast, and mer from MergeSort
*/
void Merge(student1 person[], int leftfirst, int leftlast, int rightfirst, int rightlast, int &mer)
{
  student1 temp[MAX];                        // Temporary variable for record swap
  int j = leftfirst;                          // 1st dimension array position
  int savefirst = leftfirst;                  // Saves starting point of array
  mer = mer + 2;
  while ((leftfirst <= leftlast) && (rightfirst <= rightlast))
  {
    if (person[leftfirst].ID < person[rightfirst].ID)
    {
      mer++;
      temp[j] = person[leftfirst];
      mer++;
      leftfirst++;
    }
    else
    {
      mer++;
      temp[j] = person[rightfirst];
      mer++;
      rightfirst++;
    }
    j++;
  }

  while(leftfirst <= leftlast)
  {
    temp[j] = person[leftfirst];
    mer++;
    leftfirst++;
    j++;
  }

  while(rightfirst <= rightlast)
  {
    temp[j] = person[rightfirst];
    mer++;
    rightfirst++;
    j++;
  }

  for (j = savefirst; j <= rightlast; j++)
  {
    person[j] = temp[j];
  }

}
