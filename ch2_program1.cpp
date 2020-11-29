//Author: Jenna Gottschalk
//Course : CSC160 - Summer 2020 - Dr.Bower
//Date: 6/10/2020
//Program : Chapter 2, Program 1


#include <iostream>

using namespace std;

int main()
{
	//Declares variables.
	int num1, num2, num3, average;

	//This block assigns the variables a value and computes the average of three integers. 
	num1 = 115;
	num2 = 29;
	num3 = -15;
	average = (num1 + num2 + num3) / 3;

	//This block outputs the values of the integers and their average. 
	cout << "Number 1 = " << num1 << endl;
	cout << "Number 2 = " << num2 << endl;
	cout << "Number 3 = " << num3 << endl;
	cout << "Average of Numbers 1,2,3 = " << average << endl;

	return 0;
}
