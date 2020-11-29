// Author: Jenna Gottschalk
// Date: 6/11/2020
// Course: CSC160 - Summer 2020 - Dr. Bower
// Program: Chapter 2, Program 2

#include <iostream>

using namespace std;

int main()
{
    // Number of gallons needed to fill fuel tank - entered by user.
    float fuelUsed;
    // Miles driven since last refill - entered by user.
    int miles;
    // Fuel economy - calculated by program;
    float fuelEconomy;

    // Prompt the user for tank capacity and read the value they enter.
    cout << "Please enter the number of gallons needed to fill the fuel tank: ";
    cin >> fuelUsed;
    // Prompt the user for the miles driven since the last fill and read the value entered.
    cout << "Please enter the number of miles driven since the last fill in whole numbers: ";
    cin >> miles;

    // Calculate the fuel economy.
    fuelEconomy = miles / fuelUsed;
    // Round the fuel economy to the nearest integer.
    int intFuelEconomy = (int)(fuelEconomy + 0.5);

    // Display the results.
    cout << "The fuel economy is " << intFuelEconomy << " miles per gallon." << endl;
    // End program
    return 0;
}
