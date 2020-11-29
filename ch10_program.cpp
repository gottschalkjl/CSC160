/*
Author: Dr. Bower

Course: CSC160 - Summer 2020

Program: Module 5, Chapter 10.

Description: This program simulates a very simple bookstore to
  test the Book class written in files Book.h and Book.cpp.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "Book.h"

using namespace std;

const int MAX_BOOKS = 128;

// Function prototypes.
int getMenuOption();
int getSubMenuOption();
void showTitles(Book[], int);
void showDetails(Book[], int);
void searchInventory(Book[], int);
int addToInventory(Book[], int);
int readInventory(Book[]);
void saveInventory(Book[], int);
string trim(string);

int main()
{
    // Create the array of Book objects and read the inventory file.
    Book books[MAX_BOOKS];
    int bookCount = readInventory(books);

    // Loop until the user selects 0 to exit.
    int option = getMenuOption();
    while (option != 0)
    {
        switch (option)
        {
        case 1: showTitles(books, bookCount);
            break;
        case 2: showDetails(books, bookCount);
            break;
        case 3: searchInventory(books, bookCount);
            break;
        case 4: bookCount = addToInventory(books, bookCount);
            break;
        case 5: saveInventory(books, bookCount);
            break;
        default: cout << "Invalid option." << endl;
            break;
        }

        option = getMenuOption();
    }

    cout << "Have a nice day." << endl;

    // Finish and tell the operating system all is well.
    return 0;
}

// Reads and returns a user option from the main menu.
int getMenuOption()
{
    cout << endl
        << "Main Menu" << endl << endl
        << "1. Show book titles." << endl
        << "2. Show book details." << endl
        << "3. Search book inventory." << endl
        << "4. Add book to inventory." << endl
        << "5. Save inventory to disk." << endl << endl
        << "0. Exit" << endl << endl
        << "Enter option: ";

    // Use getline to read everything the user types, including the newline.
    string line;
    getline(cin, line);
    line = trim(line);
    cout << endl;

    // Convert to int if all input was numeric; return -1 if not.
    return line.find_first_not_of("0123456789") == string::npos ? stoi(line) : -1;
}

// Reads and returns a user option from the search menu.
int getSubMenuOption()
{
    cout << endl
        << "Search Menu" << endl << endl
        << "1. Search by title." << endl
        << "2. Search by author." << endl
        << "3. Search by date." << endl
        << "4. Search by quantity." << endl
        << "5. Search by price." << endl
        << "0. Exit" << endl << endl
        << "Enter option: ";

    // Use getline to read everything the user types, including the newline.
    string line;
    getline(cin, line);
    line = trim(line);
    cout << endl;

    // Convert to int if all input was numeric; return -1 if not.
    return line.find_first_not_of("0123456789") == string::npos ? stoi(line) : -1;
}

// Show book titles in the console window.
void showTitles(Book books[], int n)
{
    for (int index = 0; index < n; index++)
    {
        // The getTitle method gets a Book's title.
        cout << books[index].getTitle() << endl;
    }
    cout << endl;
}

// Show all book details in the console window.
void showDetails(Book books[], int n)
{
    for (int index = 0; index < n; index++)
    {
        // The getAttributes method gets a nicely formatted
        // string containing all of a Book's attributes.
        cout << books[index].getAttributes() << endl;
    }
    cout << endl;
}

// Use the sub menu to search inventory.
void searchInventory(Book books[], int n)
{
    // Search values that will be entered by the user.
    string searchTarget;
    int searchQuantity;
    double searchPrice;

    // Loop until user selects 0 to exit search menu.
    int option = getSubMenuOption();
    while (option != 0)
    {
        switch (option)
        {
        case 1: // Fall through to next case.
        case 2: // Fall through to next case.
        case 3: // Search string attributes (title, author, date).
            cout << "Enter search words: ";
            getline(cin, searchTarget);
            cout << endl;

            // Show all books that match the search target.
            for (int index = 0; index < n; index++)
            {
                // Search in title, author, or date based on user option.
                string searchSource = option == 1 ? books[index].getTitle() :
                    option == 2 ? books[index].getAuthor() :
                    books[index].getDate();
                if (searchSource.find(trim(searchTarget)) != string::npos)
                {
                    // The getAttributes method gets a nicely formatted
                    // string containing all of a Book's attributes.
                    cout << books[index].getAttributes() << endl;
                }
            }

            break;

        case 4: // Search inventory for books with a given quantity.
            cout << "Enter search quantity: ";
            getline(cin, searchTarget);
            cout << endl;

            // Convert to int if all input was numeric; use -1 if not.
            searchQuantity = searchTarget.find_first_not_of("0123456789") == string::npos ? stoi(trim(searchTarget)) : -1;
            for (int index = 0; index < n; index++)
            {
                if (books[index].getQuantity() == searchQuantity)
                {
                    // The getAttributes method gets a nicely formatted
                    // string containing all of a Book's attributes.
                    cout << books[index].getAttributes() << endl;
                }
            }
            break;

        case 5: // Search inventory for books with a given price (within one dollar.)
            cout << "Enter search price: ";
            getline(cin, searchTarget);
            cout << endl;

            // Convert to double if all input was numeric; use -1.0 if not.
            searchPrice = searchTarget.find_first_not_of(".0123456789") == string::npos ? stod(trim(searchTarget)) : -1.0;
            for (int index = 0; index < n; index++)
            {
                if (fabs(books[index].getPrice() - searchPrice) <= 1.0)
                {
                    // The getAttributes method gets a nicely formatted
                    // string containing all of a Book's attributes.
                    cout << books[index].getAttributes() << endl;
                }
            }
            break;

        default: cout << "Invalid option." << endl;
            break;
        }

        option = getSubMenuOption();
    }
}

// Obtain input from user and add a new book to inventory.
int addToInventory(Book books[], int n)
{
    string line;

    // Use getline to read all data typed, including newline.
    cout << "Enter title: ";
    getline(cin, line);
    string title = trim(line);

    // User must enter a title to add a book.
    if (title.length() == 0)
    {
        // Return current value for n since no book is being added.
        return n;
    }

    // Author is "Unknown" if user pressed Enter without typing anything.
    cout << "Enter author: ";
    getline(cin, line);
    string author = trim(line).length() > 0 ? trim(line) : "Unknown";

    // Date is "Unknown" if user presses Enter without typing anything.
    cout << "Enter date: ";
    getline(cin, line);
    string date = trim(line).length() > 0 ? trim(line) : "Unknown";

    // Quantity is zero if user presses Enter without typing anything.
    cout << "Enter quantity: ";
    getline(cin, line);
    // Convert input to int if all input is numeric; use zero otherwise.
    int quantity = line.length() > 0 && line.find_first_not_of("0123456789") == string::npos ? stoi(line) : 0;

    // Price is zero if user presses Enter without typing anything.
    cout << "Enter price: ";
    getline(cin, line);
    // Convert input to double if all input is numeric or decimal point; use zero otherwise.
    double price = line.length() > 0 && line.find_first_not_of(".0123456789") == string::npos ? stod(line) : 0.0;

    // Set the attributes of the next unused book in the array.
    books[n].setAttributes(title, author, date, quantity, price);

    // Return n + 1 to increase total number of books.
    return n + 1;
}

// Read book inventory from Inventory.txt data file.
int readInventory(Book books[])
{
    // Open inventory file and make sure it is valid.
    ifstream fin("Inventory.txt");
    if (!fin.is_open())
    {
        cout << "ERROR: Could not open data file: Inventory.txt." << endl;
        return 0;
    }

    // Use getline to read all data, avoiding issues with newline characters.
    string line;
    getline(fin, line);

    // The first line in the data file is the total number of books.
    int n = stoi(trim(line));

    // Read the data for each book.
    for (int index = 0; index < n; index++)
    {
        // Use each individual set method to set the book attributes.
        getline(fin, line);
        books[index].setTitle(trim(line));
        getline(fin, line);
        books[index].setAuthor(trim(line));
        getline(fin, line);
        books[index].setDate(trim(line));
        getline(fin, line);
        books[index].setQuantity(stoi(trim(line)));
        getline(fin, line);
        books[index].setPrice(stod(trim(line)));
    }

    // Close the data file.
    fin.close();

    // Return the total number of books read.
    return n;
}

// Save book inventory to Inventory.txt data file.
void saveInventory(Book books[], int n)
{
    // Open inventory file and make sure it is valid.
    ofstream fout("Inventory.txt");
    if (!fout.is_open())
    {
        cout << "ERROR: Could not open data file: Inventory.txt." << endl;
        return;
    }

    // The first line of data in the inventory file is the number of books.
    fout << n << endl;

    // Write the data for each book.
    for (int index = 0; index < n; index++)
    {
        // Use each individual get method to get the book attributes.
        fout << books[index].getTitle() << endl;
        fout << books[index].getAuthor() << endl;
        fout << books[index].getDate() << endl;
        fout << books[index].getQuantity() << endl;
        fout << books[index].getPrice() << endl;
    }

    // Close the data file.
    fout.close();

    // Show the user how many books are currently in inventory.
    cout << n << " books saved to Inventory.txt." << endl;
}

// Utility function to trim leading and trailing whitespace from a string.
// Used to trim the newline characters read by getline.
string trim(string s)
{
    const string WHITESPACE = " \n\r\f\t\v";
    s.erase(0, s.find_first_not_of(WHITESPACE));
    s.erase(s.find_last_not_of(WHITESPACE) + 1);
    return s;
}