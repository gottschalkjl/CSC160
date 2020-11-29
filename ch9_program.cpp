/* Author: Jenna Gottschalk
   Course: CSC160 - Summer 2020 - Dr.Bower
   Date: 8/1/2020
   Program : Module 4, Chapter 9

   Description: This program reads a data file containing student records,
   computes each student's average score and letter grade, and outputs a summary
   of each student's score and letter grade, as well as the students who 
   received a score within 5 points of the highest grade. 
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Declare named constants used to specify the size of arrays.
const int MAX_STUDENTS = 50;
const int NUM_SCORES = 5;

// Define struct type that stores student name and average score. 
struct studentType
{
	string firstName;
	string lastName;
	char middleName;
	double averageScore;
};

// Define a struct type that stores all of the students' scores. 
struct scoreType
{
	int scores[NUM_SCORES];
};
 
char letterGrade(int averageScore);

int main()
{
	// Declare input stream variable and variable to read the number of lines in the file.
	ifstream infile;
	int noOfLines;

	// Declare struct type variables.
	studentType student[MAX_STUDENTS];
	scoreType allScores[MAX_STUDENTS];

	// Declare variables to format the student names, to store the average score and to store the highest score.
	string formattedName[MAX_STUDENTS];
	char grade;
	int highestScore;

	// Declare counter variables for the for and while loops.
	int i, j, index, maxIndex;

	
	// Open the file.
	infile.open("Scores_A.txt");

	// If file does not open correctly, terminate the program.
	if (!infile)
	{
		cout << "Cannot open the input file." << endl;
		return 1;
	}

	// Read the number of lines that the file contains. If the input file contains more lines
	// than the limit, terminate the program. 
	infile >> noOfLines;
	if (noOfLines > MAX_STUDENTS)
	{
		cout << "There are too many lines in this file. The limit is 50 students." << endl;
		return 1;
	}

	// Read a line of the input file.
	i = 0;
	infile >> student[i].firstName >> student[i].middleName;
	// Since only the middle initial is read, discard the remaining characters of the middle name.
	infile.ignore(30, ' ');
	infile >> student[i].lastName;
	for (j = 0; j < NUM_SCORES; j++)
		infile >> allScores[i].scores[j];
	// Continue reading lines for as many lines as the file contains. 
	while (infile && i < noOfLines - 1)
	{
		i++;
		infile >> student[i].firstName >> student[i].middleName;
		infile.ignore(30, ' ');
		infile >> student[i].lastName;
		for (j = 0; j < NUM_SCORES; j++)
			infile >> allScores[i].scores[j];
	}

	// Compute each student's average score.
	for (i = 0; i < noOfLines; i++)
	{
		int sum = 0;
		int average = 0;
		for (j = 0; j < NUM_SCORES; j++)
		{
			sum += allScores[i].scores[j];
			average = sum / NUM_SCORES;
			student[i].averageScore = average;
		}
	}

	// Find the highest score. 
	maxIndex = 0;
	for (index = 1; index < noOfLines; index++)
		if (student[maxIndex].averageScore < student[index].averageScore)
			maxIndex = index;
	highestScore = student[maxIndex].averageScore;

	// Format the students' names to Last, First M.
	for (i = 0; i < noOfLines; i++)
		formattedName[i] = student[i].lastName + ", " + student[i].firstName + " " + student[i].middleName + ".";

	// Determine size of the first column by comparing the longest name to the column header to determine which is longest. 
	maxIndex = 0;
	for (index = 1; index < noOfLines; index++)
		if (formattedName[maxIndex].length() < formattedName[index].length())
			maxIndex = index;
	string columnHeader = "Student";
	int columnWidth;
	int headerLength = columnHeader.length();
	int nameLength = formattedName[maxIndex].length();

	if (headerLength > nameLength)
		columnWidth = headerLength;
	else
		columnWidth = nameLength;

	// Print the header of the table that contains the column names. 
	cout << left << "\n" << setw(columnWidth + 2) << columnHeader << "Score  Grade" << "\n";
	cout << right << setfill('=') << setw(columnWidth + 2) << "  " << setw(7) << "  " << setw(6) << "\n";

	// Print the students' names, average scores and letter grades for each line of the input file. 
	for (int row = 0; row < noOfLines; row++)
	{
		// Call the function letterGrade to find each student's letter grade.
		grade = letterGrade(student[row].averageScore);
		cout << setfill(' ') << left << setw(columnWidth + 2) << formattedName[row]
			<< right << setw(4) << student[row].averageScore << setw(6) << grade << "\n";
	}
	
	// Print the highest score and a list of the students whose average score is within five points of the highest score. 
	cout << "\n" << "Students within 5 points of high score (" << highestScore << "): " << endl;

	for (i = 0; i < noOfLines; i++)
	{
		if (student[i].averageScore >= highestScore - 5 && student[i].averageScore <= highestScore + 5)
			cout << formattedName[i] << endl;
	}

	cout << "\n";

	// Close the input file.
	infile.close();

	// Keep program open until user presses a key.
	system("pause");

	// Terminate the program.
	return 0;
}

// Define a function that determines each student's letter grade. 
char letterGrade(int score)
{
	char grade;
	if (score >= 90)
		grade = 'A';
	else if (score >= 80)
		grade = 'B';
	else if (score >= 70)
		grade = 'C';
	else if (score >= 60)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}
