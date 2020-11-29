/* Author: Jenna Gottschalk
   Course: CSC160 - Summer 2020 - Dr.Bower
   Date: 7/16/2020
   Program : Module 4, Chapter 7 

   Description: This program reads an input file with customer names, credit card numbers, 
   and credit card expiration dates separated by colons. The program outputs the data 
   in a different format. The cardhold name is ordered by first name, middle initial and last name. 
   The credit card number is replaced by Xs, except for the last four digits, and the credit card 
   expiration date is returned as the written month and four digit year. 
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Function prototypes. 
string formatName(string input);
string formatCardNum(string input);
string formatDate(string input);

int main()
{
	// Open an input file stream with the given file name.
	ifstream fin("data.txt");

	// Use a string variable to read each line of input. 
	string line;

	// Use string variables to store substrings parsed from each line of input. 
	string name, cardNum, date;

	// The while loop reads every line of input, and splits the input string on the colons.
	// The substrings are stored in the variables name, cardNum, and date. 
	while (getline(fin, line))
	{
		// Splits the input string on the first occurrence of a colon, and stores 
		// the substring in the variable name.
		int index = line.find(":", 0);
		string name = line.substr(0, index);
		index++;

		// Splits the input string on the second occurrence of a colon, and stores
		// the substring in the variable cardNam.
		int index2 = line.find(":", index);
		string cardNum = line.substr(index, index2 - index);

		// Stores the substring after the second occurrence of a colon in the variable date. 
		string date = line.substr(index2 + 1, line.length() - index2);

		// Calls the functions to format the substrings stored in name, cardNum, and date.
		name = formatName(name);
		cardNum = formatCardNum(cardNum);
		date = formatDate(date);

		// Outputs the formatted name, card number and expiration date. 
		cout << "Card Holder: " << name << endl;
		cout << "Card Number: " << cardNum << endl;
		cout << "Expire Date: " << date << endl;
		cout << "\n";
	}
	
	// Keeps program open until user presses a key.
	system("pause");

	// Terminates the program.
	return 0;
}

// The function splits the input string into first, middle, and last names; reorders 
// and returns the substrings as the first name, middle initial, and last name. 
string formatName(string input)
{
	// The function splits the input string on a comma and stores the substring before 
	// the comma as the last name.
	int comma = input.find(",", 0);
	string lName = input.substr(0, comma);
	comma = comma + 2;

	// The function splits the input string on the next space that occurs after the comma 
	// and space, and stores the substring between the comma and the next space as the first name.
	int space = input.find(" ", comma);
	string fName = input.substr(comma, space - comma);

	// The function stores the first character of the substring after the space as middle name.
	string mName = input.substr(space + 1, 1);

	// The function reorders the substrings and returns first name, middle initial and last name. 
	return fName + " " + mName + ". " + lName;
}

// The function splits the input string on the spaces, replaces the numbers of the substrings 
// with Xs, expect for the last four digits, and returns the new card number.
string formatCardNum(string input)
{
	int space = input.find(" ", 0);
	input.replace(0, space, "XXXX");
	space++;
	int space2 = input.find(" ", space);
	input.replace(space, space2 - space, "XXXX");
	space2++;
	int space3 = input.find(" ", space2);
	input.replace(space2, space3 - space2, "XXXX");
	return input;
}

// The function splits the input string into month and year. The numeric month is converted into 
// the written month. The last two digits of the year are converted to a four digit year. 
// The functions returns the written month and full year, separated by a comma.
string formatDate(string input)
{
	// Splits the input string on the slash, and stores the substring before the slash in the variable month. 
	int slash = input.find("/", 0);
	string month = input.substr(0, slash);
	slash++;
	// Stores the substring after the slash in the variable year. 
	string year = input.substr(slash, input.length() - slash);
	// Converts two digit year into four digit year. 
	year = year.insert(0, "20");

	// Converts numeric month into written month. 
	if (month == "01" || month == "1")
		month = "January";
	else if (month == "02" || month == "2")
		month = "February";
	else if (month == "03" || month == "3")
		month = "March";
	else if (month == "04" || month == "4")
		month = "April";
	else if (month == "05" || month == "5")
		month = "May";
	else if (month == "06" || month == "6")
		month = "June";
	else if (month == "07" || month == "7")
		month = "July";
	else if (month == "08" || month == "8")
		month = "August";
	else if (month == "09" || month == "9")
		month = "September";
	else if (month == "10")
		month = "October";
	else if (month == "11")
		month = "November";
	else if (month == "12")
		month = "December";

	// Returns written month and four digit year, separated by a comma. 
	return month + ", " + year;
}