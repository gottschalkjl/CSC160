/* Author: Jenna Gottschalk
   Course: CSC160 - Summer 2020 - Dr.Bower
   Date: 7/24/2020
   Program : Module 4, Chapter 8

   Description: This program prompts the user to enter a file name and opens the specified file. 
   The program reads the numbers of votes and the names from the input file, and the program calculates 
   the total number of votes and the percentage of the votes that each individual received. 
   Then, the program outputs the names, votes, and percentage of votes into a table, and the program 
   prints the total number of votes and the winner who received the most votes.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// Declare variables to open and read the input file. 
	ifstream infile;
	string fileName, inputFile;

	// Declare variable to set the maximum number of lines the program will process.
	const int MAX = 200;

	// Declare arrays to store the number of votes, the names and the percentage of votes. 
	int votes[MAX] = {0};
	string names[MAX] = {};
	float percent[MAX] = {0.0};

	// Prompt user to enter the base name of the data file, add file extension to the file name, and open file.
	cout << "Enter base name of data file: ";
	cin >> fileName;
	cout << "\n\n";

	inputFile = fileName;
	inputFile.append(".txt");
	infile.open(inputFile.c_str());

	// If file does not open correctly, terminate the program.
	if (!infile)
	{
		cout << "Cannot open the input file." << endl;
		return 1;
	}
	
	// Read the number of lines that the file contains. If the input file contains more lines
	// than the limit, terminate the program. 
	int noOfLines;
	infile >> noOfLines;
	if (noOfLines > MAX)
	{
		cout << "There are too many lines in this file. The limit is 200 lines." << endl;
		return 1;
	}

	// Read a line of the input file for as many lines as the file contains. 
	int i = 0;
	infile >> votes[i] >> names[i];
	while (infile && i < noOfLines)
	{
		i++;
		infile >> votes[i] >> names[i];
	}

	// Compute the total amount of votes.
	int total = 0;
	for (i = 0; i < noOfLines; i++)
		total = total + votes[i];

	// Compute the percentage of votes that each individual received.
	for (i = 0; i < noOfLines; i++)
		percent[i] = static_cast<float>(votes[i]) * 100 / total;

	// Determine size of the first column by comparing the longest name to the file name to determine which is longest. 
	int maxIndex = 0;
	for (int index = 1; index < noOfLines; index++)
		if (names[maxIndex] < names[index])
			maxIndex = index;
	int columnWidth;
	int fileLength = fileName.length();
	int nameLength = names[maxIndex].length();
	if (fileLength > nameLength) 
		columnWidth = fileLength;
	else
		columnWidth = nameLength;
	

	// Print the header of the table that contains the column names. 
	cout << left << setw(columnWidth + 5) << fileName << "Votes   Percent" << "\n";
	cout << right << setfill('=') << setw(columnWidth + 5) << "     " << setw(8) << "   " << setw(8) << "\n";

	// Format the output of the floating-point numbers.
	cout << fixed << showpoint << setprecision(1);

	// Print the name, number of votes and percentage of votes for each line of the input file. 
	for (int row = 0; row < noOfLines; row++)
	{
		cout << setfill(' ') << left << setw(columnWidth + 5) << names[row] 
			<< right << setw(5) << votes[row] << setw(9) << percent[row] << "%" << "\n";
	}

	// Print the total number of votes and the footer of the table. 
	cout << setfill('-') << setw(columnWidth + 5) << "     " << setw(6) << "\n";
	cout << setfill(' ') << left << setw(columnWidth + 5) << "Total" 
		<< right << setw(5) << total << "\n\n";

	// Determine the winner who has the most votes. 
	int mostVotes = 0;
	
	for (int index = 1; index < noOfLines; index++)
		if (votes[mostVotes] < votes[index])
			mostVotes = index;
	// Output the winner.		
	cout << "The winner is " << names[mostVotes] << "!" << "\n\n";

	// Keep program open until user presses a key.
	system("pause");

	// Terminate the program.
	return 0;
}