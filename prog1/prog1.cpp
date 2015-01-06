/*
Chris McKnight
Barbara Guillott
cs1253 sec 1
cs125326

Specification the Requirement:
Calculate the cost of gas at Clean & Gas Convenience Store, with or 
without a car wash, where a discount on a car wash is given for a purchase 
of $20 or more of gas.

Data analysis:
	Name		Type		Content
Constants:
	REGULAR		real		price per gallon of regular gas
	UNLEADED	real		price per gallon of unleaded gas
	SUPER		real		price per gallon of superunleaded gas
	DISCOUNTCARWASH	real		car wash fee with $20 gas purchase
	FULLCARWASH	real		car wash fee without $20 gas purchase	

Variables:
	count		integer		number of customers
	gallons		real		number of gallons of gas purchased
	gastype		character	type of gas purchased
	carwash		character	car wash desired or not
	gasprice	real		cost for gas only
	gallonprice	real		cost per gallon of gas
	washcost	real		cost for car wash only
	total		real		total cost for gas and car wash

Problem Analysis:

Repeat for 7 customers
	read data(gallons, gastype, carwash)
	calculate gas cost
	determine car wash price
	calculate total cost
	print sales receipt

Algorithm:
count = 0
while (count < 7)
begin
	print "Enter gallons of gas: "
	read gallons
	print "Enter the gas type: "
	print "R for regular: "
	print "U for unleaded: "
	print "S for superunleaded: "
	print "N for no gas: "
	read gastype
	print "Enter car wash option <Y for yes, N for no>: "
	read carwash
	if gastype = R
	then
	begin
		gallonprice = REGULAR
		gasprice = gallons*REGULAR
		if carwash = Y and gasprice >= 20
		then washcost = DISCOUNTCARWASH
		else
		if carwash = Y and gasprice < 20
		then washcost = FULLCARWASH
		else
		then washcost = 0
	end
	else
	if gastype = U
	then
	begin
		gallonprice = UNLEADED
		gasprice = gallons*UNLEADED
		if carwash = Y and gasprice >= 20
		then washcost = DISCOUNTCARWASH
		else 
		if carwash = Y and gasprice < 20
		then washcost = FULLCARWASH
		else
		then washcost = 0
	end
	else
	if gastype = S
	then
	begin
		gallonprice = SUPER
		gasprice = gallons*SUPER
		if carwash = Y and gasprice >= 20
		then washcost = DISCOUNTCARWASH
		else
		if carwash = Y and gasprice < 20
		then washcost = FULLCARWASH
		else
		then washcost = 0
	end
	else
	if gastype = N
	then
	begin
		gasprice = 0
		washcost = FULLCARWASH
	end
	total = gasprice + washcost
	print "********************************"
	print "Clean & Gas Convenience Store"
	print "Sept. 14, 2008"
	print "********************************"
	print "Amount of gas purchased: ", gallons
	print "Price per gallon", gallonprice
	print "Total gas cost", gasprice
	print "Car wash cost", washcost
	print "--------------------------------"
	print "Total due: ", total
	print "Thank you, please come again"
	print "Buckle up and drive safely"
	count = count + 1
end

Trace Table:
gallons		gastype 	carwash		gasprice	total
20.5		U		Y		77.70		80.70
45.8		S		N		182.74		182.74
*/


#include <iostream>
#include <iomanip>

using namespace std;

const double REGULAR = 3.49;		//regular price per gallon
const double UNLEADED = 3.79;		//unleaded price per gallon
const double SUPER = 3.99;		//superunleaded price per gallon
const double DISCOUNTCARWASH = 3.00;	//car wash price with gas >= $20
const double FULLCARWASH = 6.00;	//car wash price with gas < $20 

int main()
{
	int count;			//number of customers
	double gallons,			//number of gallons of gas purchased
	       gallonprice,		//cost of gas per gallon
	       gasprice,		//cost for gas only
	       washcost,		//cost for car wash only
	       total;			//cost for gas and car wash
	char gastype,			//type of gas purchased
	     carwash;			//car wash desired or not

	cout << fixed << showpoint << setprecision(2);

	count = 0;
	while (count < 7)
	{
		cout<<endl<<"Enter gallons of gas: ";
		cin>>gallons;
		cout<<endl<<"Enter the gas type: ";
		cout<<endl<<"R for regular: ";
		cout<<endl<<"U for unleaded: ";
		cout<<endl<<"S for superunleaded: ";
		cout<<endl<<"N for no gas: ";
		cin>>gastype;
		cout<<endl<<"Enter car wash option <Y for yes, N for no>: ";
		cin>>carwash;
		if (gastype == 'R')
		{
			gallonprice = REGULAR;
			gasprice = gallons * REGULAR;
			if ((carwash == 'Y') && (gasprice >= 20))
			{
				washcost = DISCOUNTCARWASH;
			}
			else
			if ((carwash == 'Y') && (gasprice < 20))
			{
				washcost = FULLCARWASH;
			}
			else
			{
				washcost = 0;
			}
		}
		else
		if (gastype == 'U')
		{
			gallonprice = UNLEADED;
			gasprice = gallons * UNLEADED;
			if ((carwash == 'Y') && (gasprice >= 20))
			{
				washcost = DISCOUNTCARWASH;
			}
			else
			if ((carwash == 'Y') && (gasprice < 20))
			{
				washcost = FULLCARWASH;
			}
			else
			{
				washcost = 0;
			}
		}
		else
		if (gastype == 'S')
		{
			gallonprice = SUPER;
			gasprice = gallons * SUPER;
			if ((carwash == 'Y') && (gasprice >= 20))
			{
				washcost = DISCOUNTCARWASH;
			}
			else
			if ((carwash == 'Y') && (gasprice < 20))
			{
				washcost = FULLCARWASH;
			}
			else
			{
				washcost = 0;
			}
		}
		else
		if (gastype == 'N')
		{
			gasprice = 0;
			washcost = FULLCARWASH;
		}
		total = gasprice + washcost;
		cout<<endl<<"*****************************************";
		cout<<endl<<"      Clean & Gas Convenience Store";
		cout<<endl<<"             Sept. 16, 2008";
		cout<<endl<<"*****************************************";
		cout<<endl<<"Amount of gas purchased: "<<setw(15)<<gallons;
		cout<<endl<<"Price per gallon: "<<setw(22)<<gallonprice;
		cout<<endl<<"Total gas cost: "<<setw(24)<<gasprice;
		cout<<endl<<"Car wash cost: "<<setw(25)<<washcost;
		cout<<endl<<"-----------------------------------------";
		cout<<endl<<"Total due: "<<setw(29)<<total<<endl;
		cout<<endl<<"      Thank you, please come again";
		cout<<endl<<"      Buckle up and drive safely"<<endl;
		count = count + 1;
	}
	return 0;
}
