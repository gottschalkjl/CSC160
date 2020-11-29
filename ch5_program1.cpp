// Author: Jenna Gottschalk
// Course : CSC160 - Summer 2020 - Dr.Bower
// Date: 7/2/2020
// Program : Chapter 5, Program 1
// This program prompts the user to enter two integers 
// in consecutive order and outputs the following:
//   -all of the odd integers between the two integers
//   -the sum of the even integers between the two integers
//   -the numbers 1 through 10 and their values squared
//   -the sum of the square of all the odd integers between the two integers
//   -all the letters of the alphabet in uppercase.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	// Declare variables - entered by the user.
	int firstNum, secondNum;
	// Declare variables - calculated by the program.
	int evenSum, oddSquareSum;
	// Declare variable - loop control variable for numeric output.
	int i;
	// Declare variable - loop control variable for character output.
	char j; 

	// Prompt user to enter two integers in consecutive order.
	// If the input is valid, read the input. 
	// If firstNum > secondNum, prompt the user to enter input again.
	// If input stream is in a fail state, clear the input stream and prompt the user to enter input again. 
	do
	{
		cin.clear();
		cout << "Enter two numbers." << endl;
		cout << "First number must be less than the second number you enter." << endl;
		cout << "Enter numbers: ";
		cin >> firstNum >> secondNum;
		if (!cin)
		{
			cout << "Please enter two valid integers." << endl;
			cin.clear();
			cin.ignore(200, '\n');
		}
	}
	while (firstNum > secondNum || !cin);
	
	// Output all of the odd integers between firstNum and secondNum.
	cout << "Odd integers between " << firstNum << " and " << secondNum << " are:" << endl;
	for (i = firstNum; i <= secondNum; i++)
	{
		if (i % 2 == 1 || i % 2 == -1)
			cout << i << " ";
	}
	cout << endl;

	// Initialize evenSum to 0.
	evenSum = 0;
	// Calculate the sum of all the even integers between firstNum and secondNum.
	for (i = firstNum; i <= secondNum; i++)
	{
		if (i % 2 == 0)
			evenSum = evenSum + i;
	}
	// Output the sum of all the even integers between firstNum and secondNum.
	cout << "Sum of even integers between " << firstNum << " and " << secondNum
		 << " = " << evenSum << endl;

	// Output the column headers.
	cout << "Number" << setw(20) << "Square of Number" << endl;
	// Output the numbers 1-10 and their values squared in two columns.
	for (i = 1; i <= 10; i++)
	{
		cout << setw(4) << i << setw(18) << pow(i, 2) << endl;
	}
	cout << endl;

	// Initialize oddSquareSum to 0.
	oddSquareSum = 0;
	// Calculate the sum of the square of all odd integers between firstNum and secondNum.
	for (i = firstNum; i <= secondNum; i++)
	{
		if (i % 2 == 1 || i % 2 == -1)
			oddSquareSum = oddSquareSum + pow(i, 2);
	}
	// Output the sum of the square of all odd integers between firstNum and secondNum.
	cout << "Sum of the squares of odd integers between " << firstNum << " and " << secondNum
		 << " = " << oddSquareSum << endl;

	// For each letter in the alphabet, output the letter and a space. 
	cout << "Upper case letters are : ";
	for (j = 'A'; j <= 'Z'; j++)
	{
		cout << j << " ";
	}
	cout << endl; 

	return 0;
}