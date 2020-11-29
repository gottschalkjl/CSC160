// Author: Jenna Gottschalk
// Course : CSC160 - Summer 2020 - Dr.Bower
// Date: 6/26/2020
// Program : Chapter 4, Program 1
// This program caculates and outputs the number of boxes and 
// containers needed to ship the total number of cookies entered 
// by the user, as well as any leftover cookies or boxes that do not fit. 

#include <iostream>

using namespace std;

int main()
{
	// Declare variables - entered by user.
	int cookies;
	// Declare variables - calculated by program.
	int boxes, containers, leftoverCookies, leftoverBoxes;

	// Prompt the user for total number of cookies and read the value they enter. 
	cout << "Please enter the total number of cookies: ";
	cin >> cookies;
	cout << endl; 

	// Check if input is valid. If it is in a fail state, 
	// clear the input stream and prompt the user to try again.
	if (!cin)
	{
		cout << "Input failure. Please enter a whole number." << endl;
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter the total number of cookies: ";
		cin >> cookies;
		cout << endl;
	}

	// Calculate the amount of boxes needed to hold the cookies.
	boxes = cookies / 24;

	// Calculate the amount of leftover cookies.
	leftoverCookies = cookies % 24;

	// Calculate the amount of containers needed to store the boxes.
	containers = boxes / 75;

	// Calculate the amount of leftoverBoxes.
	leftoverBoxes = boxes % 75;

	// Control logic for outputing the number of boxes 
	if (boxes > 0)
		cout << "The number of cookie boxes needed to hold the cookies : "
		<< boxes << endl;
	else
		cout << "There are not enough cookies to fill a box." << endl;

	// Control logic for outputing the number of leftover cookies
	if (leftoverCookies > 0)
		cout << "Leftover cookies: " << leftoverCookies << endl;

	// Control logic for outputing the number of containers
	if (containers > 0)
		cout << "The number of containers needed to store the cookie boxes: "
		<< containers << endl;
	else
		cout << "There are not enough boxes to fill a container." << endl;

	// Control logic for outputing the number of leftover boxes
	if (leftoverBoxes > 0)
		cout << "Leftover boxes: " << leftoverBoxes << endl;
	
	// Close program
	return 0;

}
