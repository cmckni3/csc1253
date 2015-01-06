/*
Chris McKnight
Barbara Guillot
cs1253 sec 1
cs125326

Specify the requirement:
Calculate  average running yardage for each player, team's average running 
yardage, highest average, and lowest average for County College.

Data Analysis:
Variables:
	Name		Type	Content
	count           integer counts number of running yardages
	playercount     integer counts the number of players
	min             real    lowest average running yardage
	max             real    highest average running yardage
	year            integer years in college
	number          integer player's number
	yard            real    running yardage
	sum             real    a player's total running yardage
	avg             real    a player's average running yardage
	totalsum        real    entire team's running yardage sum
	totalavg        real    entire team's running yardage average
	minID           integer player number with lowest average yardage
	maxID           integer player number with highest average yardage

Problem Analysis:
print header output
read number
Repeat while number <> -1
	print number
	read year
	check year and print appropriate classification
	Repeat for 5 averages
		read yard
		calculate sum of yardages
		count the number of yardages
	calculate player's average yardage
	print average
	calculate highest average and ID
	calculate lowest average and ID
	calculate totalsum
	count the number of players
	read number
calculate mean running average
print summary output

Algorithm:
min = 1000
max = -1.0
playercount = 0
totalsum = 0
print "County College"
print "Average Running Yardage"
print "Fall 2008"
print "------------------------------------"
print "Player Number"
print "Classification"
print "Average Yardage"
print "------------------------------------"
read number
while (number <> -1)
begin
	print number
	read year
	if (year = 1)
	then print "Freshman"
	else
	if (year = 2)
	then print "Sophomore"
	else
	if (year = 3)
	then print "Junior"
	else
	if (year = 4)
	then print "Senior"
	count = 0
	sum = 0
	while (count < 5)
	begin
		read yard
		sum = sum + yard
		count = count + 1
	end
	avg = sum/count
	print avg
	if (avg > max)
	then
		begin
			max = avg
			maxID = number
		end
	if (avg < min)
	then
		begin
			min = avg
			minID = number
		end
	totalsum = totalsum + avg
	playercount = playercount + 1
	read number
end
totalavg = totalsum/playercount
print "-------------------------"
print "The mean average running yardage is", totalavg
print "The minimum average running yardage is", min
print "for player", minID
print "The maximum average running yardage is", max
print "for player", maxID

Trace Table:
playercount	number	year	sum	avg	totalsum	totalavg 
0		25	3	16.9	3.38	3.38		3.38
1		10	2	20.7	4.14	7.52		3.76	

playercount	min	minID	max	maxID
0		1000		-1.0
1		3.38	25	3.38	25
2		3.38	25	4.14	10
3

playercount	count	number	yard	sum	avg	totalsum	
0		0	25	3.1	3.1				
		1		4.9	8.0				
		2		2.8	10.8				
		3		3.6	14.4				
		4		2.5	16.9	3.38	3.38		
		5						
						
1		0	10	4.5	4.5				
		1		3.5	8.0				
		2		3.7	11.7				
		3		4.1	15.8				
		4		4.9	20.7	4.14	7.52		
		5	
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double yard,		//running yardages
	       sum,		//a player's running yardages sum
	       avg,		//a player's average running yardage
	       totalsum,	//entire team's running yardage sum
	       totalavg,	//entire team's average running yardage
	       min,		//lowest average yardage
	       max;		//highest average yardage
	int playercount,	//number of players
	    count,		//number of running yardages
	    year,		//years in college
	    number,		//player's number
	    minID,		//player number with lowest average yardage
	    maxID;		//player number with highest average yardage
	min = 1000.0;
	max = -1.0;
	playercount = 0;
	totalsum = 0;
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"                   County College"<<endl;
	cout<<"                Average Running Yardage"<<endl;
	cout<<"                      Fall 2008"<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<"Player Number"<<setw(20);
	cout<<"Classification"<<setw(20);
	cout<<"Average Yardage"<<endl;
	cout<<"------------------------------------------------------";
	cin>>number;
	while (number != -1)
	{
		cout<<endl<<setw(6)<<number;
		cin>>year;
		if (year == 1)
		{
			cout<<setw(24)<<"Freshman ";
		}
		else
		if (year == 2)
		{
			cout<<setw(24)<<"Sophomore";
		}
		else
		if (year == 3)
		{
			cout<<setw(24)<<"Junior   ";
		}
		else
		if (year == 4)
		{
			cout<<setw(24)<<"Senior   ";
		}
		count = 0;
		sum = 0;
		while (count < 5)
		{
			cin>>yard;
			sum = sum + yard;
			count = count + 1;
		}
		avg = sum/count;
		cout<<setw(18)<<avg;
		if (avg > max)
		{
			max = avg;
			maxID = number;
		}
		if (avg < min)
		{
			min = avg;
			minID = number;
		}
		totalsum = totalsum + avg;
		playercount = playercount + 1;
		cin>>number;
	}
	totalavg = totalsum/playercount;
	cout<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<"The mean average running yardage is "<<totalavg<<endl;
	cout<<"The minimum average running yardage is "<<min;
	cout<<" for player "<<minID<<endl;
	cout<<"The maxiumum average running yardage is "<<max;
	cout<<" for player "<<maxID<<endl;
	return 0;
}
