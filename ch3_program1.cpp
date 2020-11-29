//Author: Jenna Gottschalk
//Course : CSC160 - Summer 2020 - Dr.Bower
//Date: 6/21/2020
//Program : Chapter 3, Program 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//Declare file stream variables
	ifstream inFile;
	ofstream outFile;

	//Declare ticket variables
	double boxTicketPrice, sidelineTicketPrice, premiumTicketPrice,
		   generalTicketPrice, totalTicketSales;
	int numberOfBoxTicketsSold, numberOfSidelineTicketsSold,
		numberOfPremiumTicketsSold, numberOfGeneralTicketsSold,
		totalNumberOfTicketsSold;

	//Open the files
	inFile.open("Ch3_Ex5Data.txt");
	outFile.open("Ch3_Ex5Out.txt");

	//Format output 
	outFile << fixed << showpoint;
	outFile << setprecision(2);

	//Read the number of tickets sold and ticket prices
	inFile >> boxTicketPrice >> numberOfBoxTicketsSold >> sidelineTicketPrice
		   >> numberOfSidelineTicketsSold >> premiumTicketPrice
		   >> numberOfPremiumTicketsSold >> generalTicketPrice >> numberOfGeneralTicketsSold;

	//Calculate the total number of tickets sold
	totalNumberOfTicketsSold = numberOfBoxTicketsSold + numberOfSidelineTicketsSold 
							   + numberOfPremiumTicketsSold + numberOfGeneralTicketsSold;

	//Calculate the total ticket sales
	totalTicketSales = (boxTicketPrice * numberOfBoxTicketsSold) 
						+ (sidelineTicketPrice * numberOfSidelineTicketsSold) 
						+ (premiumTicketPrice * numberOfPremiumTicketsSold) 
						+ (generalTicketPrice * numberOfGeneralTicketsSold);

	//Print to console
	cout << "See output file: Ch3_Ex5Out.txt for the results.";
	
	//Output the total number of tickets sold and the total ticket sales
	outFile << "Number of tickets sold = " << totalNumberOfTicketsSold << endl;
	outFile << "Sale amount = $" << totalTicketSales << endl;

	//Close files
	inFile.close();
	outFile.close();

	//Close program
	return 0;
}