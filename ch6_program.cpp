// Author: Jenna Gottschalk
// Course : CSC160 - Summer 2020 - Dr.Bower
// Date: 7/10/2020
// Program : Chapter 6, Program 1
// This program prompts the user to enter the temperature in 
// degrees Fahrenheit and the wind speed in miles per hour, 
// and then calculates and outputs the windchill factor. 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function prototypes to get wind speed and temperature input and to calculate windchill.
double getWindSpeed();
double getTemp();
double calcWindChill(double windSpeed, double temp);

int main()
{

// Calls functions to get wind speed and temperature input and stores them in variables.
	double w = getWindSpeed();
	double t = getTemp();

// Formats output to two decimal points with trailing zeros.
	cout << fixed << setprecision(2);

// Outputs the temperature input by the user and the wind chill calculated by the function calcWindChill().
	cout << "Current temperature: " << t << "F" << endl;
	cout << "Windchill factor: " << calcWindChill(w, t) << "F" << endl;
	
// Waits for key press to clear screen. 
	system("pause");

// Terminates the program.
	return 0;
}

// Prompts user to enter wind speed until the program receives valid input,
// and stores input.
double getWindSpeed()
{
	double windSpeed;
	do
	{
		cin.clear();
		cout << "Enter wind speed in miles per hour: ";
		cin >> windSpeed;
		cout << endl;
		if (!cin)
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter a valid wind speed: ";
			cin >> windSpeed;
			cout << endl;
		}
	} 
	while (!cin || windSpeed < 0 || windSpeed > 260);
	return windSpeed;
}

// Prompts user to enter temperature until the program receives valid input,
// and stores input.
double getTemp()
{
	double temp;
	do
	{
		cin.clear();
		cout << "Enter temperature in degrees Fahrenheit: ";
		cin >> temp;
		cout << endl;
		if (!cin)
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter a valid temperature: ";
			cin >> temp;
			cout << endl;
		}
	} while (!cin || temp < -460 || temp > 130);
	return temp;
}

// Calculates wind chill factor using wind speed and temperature.
double calcWindChill(double windSpeed, double temp)
{
	double windChill;
	windChill = 35.74 + 0.6215 * temp - 35.75 * pow(windSpeed, 0.16) + 0.4275 * temp * pow(windSpeed, 0.16);
	return windChill;
}