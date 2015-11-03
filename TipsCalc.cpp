//Kim Lien Chu
//COP2000.0M1
/*Gratuity Calculator
//This program will : Calculate the gratuity on a restaurant meal
//     
//     1.  Create class Tips
//     2.  Use user input for taxRate or default taxRate .065
//     3.  Validate user input of tax rate
//     4.  Use user input of total bill amount
//     5.  Validate user input of total bill amount
       6.  Has public function: computeTips
       7.  Calculate the tip base on cost of meal before tax
       8.  Calculate the cost of meal at different tip rates
       9.  Calculate the total cost of meal after tax
       10. Loop to calculate as many meals as the user want
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/*****************************************/
//      class Tips
/****************************************/
class Tips
{
	//member variable : taxRate
private:
	double taxRate;
public:
	Tips();                 //default constructor
	Tips(double);            //overloaded constructor
	
	//prototypes for member functions

	double computeTip(double, double);
	

};
Tips::Tips()                 //default constructor
{
	taxRate = .065;
}
Tips::Tips(double t)            //overloaded constructor
{
	taxRate = t;
}


// /***************Method definition****************************/
//   Calculate the tip from billTotal and tipRate
/************************************************************/

double Tips::computeTip(double billTotal, double tipRate)
{
	
	double mealTotal;
	double tipTotal;
	mealTotal = billTotal / (1 + taxRate);
	
	tipTotal = (tipRate / 100) * (mealTotal);
	return tipTotal;
}

/******************/
//prototypes
/******************/

double getTaxRate();
void   validateOption(char);
void   validateTaxRate(double&);
double getBillTotal();
void   validateBillTotal(double&);
void   displayHeaderTipTable();
void   displayTipTable(double, double, double);
/**************************************************
//Calculate the tip
     1.  Ask for the tax rate
	 2.  Validate tax Rate user input
	 3.  Ask for bill total
	 4.  Validate bill total
	 5.  Calculate the tip
	 6.  Display tip table
	 7.  Ask if user want to calculate tip again

*****************************************************/
int main()
{
	char yesCalc = 'y';
	char yOrN = 'y';
	double tipRate;
	double tipCalc;

	double billTotal;
	double tax;

	cout << "\n\n                 Welcome to the Gratuity Calculator \n";
	
		while (yesCalc == 'y' )
		{
			yOrN = 'y';
			tipRate = 0;
			tipCalc = 0;
			billTotal = 0;
			tax = 0;
					
			cin.sync();
			cin.clear();
			cout << "\n\n           Is the tax rate 6.5%: (enter y or n):  ";
			cin >> yOrN;
			//validate user input of valid option y or n
			validateOption(yOrN);
			
			Tips tipObj;
			if (yOrN == 'n')
			{
				tax = getTaxRate();
				tipObj = Tips(tax);
			}
			else 
			{
				tipObj = Tips();
			}

			//get total bill amount
			billTotal = getBillTotal();
			tipRate = 10.0;
			//Display tip table
			displayHeaderTipTable();
			do
			{	
				//Calculate tip using computeTip method from Tips class
				tipCalc = tipObj.computeTip(billTotal, tipRate);
				// display tip table : one line per tip%  
				displayTipTable(billTotal, tipRate, tipCalc);
				tipRate = tipRate + 5;
			} while (tipRate <= 25);
			//        end calculation
			yesCalc = 'n';
			cout << "\n\n            Gratuity Calculation Completed   \n\n"<<endl;
			//        ask user if he would like to end calculation
			cin.sync();
			cin.clear();
			cout << "\n\n Would you like to calculate the Gratuity again?(Enter y or n )  ";
		
			cin >> yesCalc;
			validateOption(yesCalc);

		} 
	return 0;
}


/**************************************************
  getTaxRate function:  get Tax rate from user
  1.  Prompt user for tax rate =taxInput
  2.  validate tax rate of user input  
  3.  calc tax rate to fraction rate  taxFraction = taxInput/ 100
  4.  return tax Fraction
*****************************************************/
double getTaxRate()
{
	double taxInput;
	double taxFraction;
	// get tax rate or default rate  
	cin.sync();
	cin.clear();
	cout << "\n\n           Enter the tax rate \n";
	cout << "    (enter a positive tax rate 5.5 % is entered as:  5.5 ):   ";
	cin >> taxInput;
	//  validate user input valid tax rate
	validateTaxRate(taxInput);
	// calculate tax rate for calculation
	taxFraction = taxInput / 100;
	// send tax rate back
	return taxFraction;
}
/**************************************************
validateOption function: Validate user input 
if user want option y or n
   a. if user did not input valid y or n reprompt till user enter valid input
*****************************************************/
void validateOption(char o)
{
	o = tolower(o);
	while (!cin ||( o != 'y' && o != 'n'))
	{
		cin.sync();
		cin.clear();
		cout << "\n           Invalid input, try again (enter y or n):  ";
		
		cin >> o;
	}
	
	
}
/****************************************
validateTaxRate function: validate tax rate input
1.  if user did not enter a positive tax Rate 
      a.  prompt user to enter a positive valid tax rate
*****************************************/
void validateTaxRate(double& t)
{
	while (!cin  || t < 0)
	{
		cin.sync();
		cin.clear();
		cout << "\n           Invalid input, try again "
			 << "\n    (a positive tax rate of 4.5% is entered as:  4.5 ):   ";
		cin >> t;
	}
}
/***********************************************
//getBillTotal function:  get billTotal from user input
     1.  prompt user for bill total
	 2.  validate the bill total user enter
	 3.  return bill total
********************************************/
double getBillTotal()
{
	double billTotal;
	//prompt user for bill total
	cin.sync();
	cin.clear();
	cout << "\n\n           Enter the bill total  \n";
	cout << "    (a positive bill cost of $54.5 is entered as: 54.5 ):  ";
	cin >> billTotal;
	//validate user input of valid option y or n
	validateBillTotal(billTotal);
	return billTotal;
}
/**************************************************
  validateBillTotal function:  validate bill total
       1.  bring in bil total = b 
       2.  if user did not enter a positive number
	          user is prompt until user entered a positive number
*****************************************************/

void validateBillTotal(double& b)
{
	while (!cin || b < 0)
	{
		cin.sync();
		cin.clear();
		cout << "\n           Invalid input, try again \n";
		cout << "    (a positive bill cost of $54.5 is entered as: 54.5):   ";
		cin >> b;
	}
}
/**************************************************
displayHeader function:
               TIP TABLE
     TIP (%)      TIP TOTAL ($)   MEAL TOTAL($)
	                           (meal cost + tax + tip)
*****************************************************/

void displayHeaderTipTable()
{
	cout << "\n\n                  TIP TABLE  \n\n";
	cout << "      TIP (%)       \t  TIP TOTAL($)   \t  \t   MEAL TOTAL($) \n";
	cout << "                                                     (meal cost + tax + tip) \n" << endl;
}
/**************************************************
displayTipTable function:
1. bring in tR = tip rate
            bT = bill total
            tC = tip amnout

calculate totalCost = total cost of meal  = tip amount + bill total
display the tip table with line for
     10%             tip amount       meal total
     15%             tip amount       meal total  
     20%             tip amount       meal total
     25%             tip amount       meal total
*****************************************************/

void displayTipTable(double bT, double tR, double tC)
{

	double totalCost;
	totalCost = tC + bT;
	cout << showpoint << setprecision(2) << fixed << "     " << tR << " % "
		<< "        \t  $\t" << tC
		<< "              \t  $\t " << totalCost << " \n";
	
}


