// SurfShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//The purpose of this code is to allow a user to purchase surfboards in different sizes and see the number of surfboards and total amount due by size as well as the total due for the entire purchase.

void ShowUsage() {
    //This function shows the user how to use the program.

    cout << "To show program usage \'S\'" << endl;
    cout << "To purchase a surfboard press \'P\'" << endl;
    cout << "To display current purchases press \'C\'" << endl;
    cout << "To display total amount due press \'T\'" << endl;
    cout << "To quit the program press \'Q\'" << endl;
    cout << endl;

}

void MakePurchase(int&iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    //This function allows the user to select the size surfboard they'd like to purchase as well as the number of boards in that size.
    int quantity = 0;
    char type = '0';
    cout << "Please enter quantity and type (X=xxxsmall, S=small, M=medium, L=large) of surfboard you would like to purchase:";
    cin >> quantity >> type;

    //switch statement that continuously tallies up the number of surfboards in each size as the user continues with the program.
    switch (toupper(type)) {
    case('X'):
        iTotalXXXSmall = iTotalXXXSmall + quantity;
        break;
    case('S'):
        iTotalSmall = iTotalSmall + quantity;
        break;
    case('M'):
        iTotalMedium = iTotalMedium + quantity;
        break;
    case('L'):
        iTotalLarge = iTotalLarge + quantity;
    }
}

void DisplayPurchase(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {

    //This function shows up the sum of all surfboards purchased by the user by size.
    if (iTotalXXXSmall > 0) {
        cout << "The total number of xxx-small surfboards is " << iTotalXXXSmall << "." << endl;
    }
    if (iTotalSmall > 0) {
        cout << "The total number of small surfboards is " << iTotalSmall << "." << endl;
    }
    if (iTotalMedium > 0) {
        cout << "The total number of medium surfboards is " << iTotalMedium << "." << endl;
    }
    if (iTotalLarge > 0) {
        cout << "The total number of large surfboards is " << iTotalLarge << "." << endl;
    }
    //If no purchases were made, this message will print. No data can be presented if the user did not opt to buy any surfboards.
    else if (iTotalXXXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
        cout << "No purchases made yet." << endl;

}

void DisplayTotal(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {

    //This function will calculate and display the total quantity of surfboards purchased by size as well as the total price of the boards by size and the cost for the entire purchase.

    //Variables initialized and declared.
    const double xxxsPrice = 15.00, smallPrice = 175.00, medPrice = 190.00, largePrice = 200.00;
    double xxxsTotal = 0.00, smallTotal = 0.00, medTotal = 0.00, largeTotal = 0.00, sTotal = 0;

    if (iTotalXXXSmall > 0) {
        xxxsTotal = xxxsPrice * iTotalXXXSmall;
        cout << "The total number of xxx-small surfboards is " << iTotalXXXSmall << " at a total of $" << xxxsTotal << "." << endl;
    }
    if (iTotalSmall > 0) {
        smallTotal = smallPrice * iTotalSmall;
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << smallTotal << "." << endl;
    }
    if (iTotalMedium > 0) {
        medTotal = medPrice * iTotalMedium;
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << medTotal << "." << endl;
    }
    if (iTotalLarge > 0) {
        largeTotal = largePrice * iTotalLarge;
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << largeTotal << "." << endl;
    }
    //If no purchases were made, this message will print. No data can be presented if the user did not opt to buy any surfboards.
    else if (iTotalXXXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
        cout << "No purchases made yet." << endl;

    //Calculate sum of entire purchase and print out sum.
    sTotal = xxxsTotal + smallTotal + medTotal + largeTotal;

    cout << "Amount due: $" << sTotal << endl;
}

int main()
{
    //Declare and initialize variables.
    char selection;
    int iTotalXXXSmall = 0, iTotalSmall = 0, iTotalMedium = 0, iTotalLarge = 0;

    //Title goes at the top.
    cout << setw(58) << setfill('*') << "" << endl;
    cout << setw(5) << "" << "Welcome to my Johnny Utah's PointBreak Surf Shop" << setw(5) << "" << endl;
    cout << setw(58) << setfill('*') << "" << endl;

    //Function to show user how to work program immediately runs.
    ShowUsage();

    //User input to run while loop.
    cout << endl;
    cout << "Please enter selection: ";
    cin >> selection;

    //While loop to run until user quits program.
    while (selection != toupper('Q'))
    {
        //Switch statement to decide which function to run depending on user input.
        switch (toupper(selection))
        {
        case('S'):
            main();
            break;
        case('P'):
            MakePurchase(iTotalXXXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            break;
        case('C'):
            DisplayPurchase(iTotalXXXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            break;
        case('T'):
            DisplayTotal(iTotalXXXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            break;
        case('Q'):
            //If user quits.
            cout << "Thank you" << endl;
            return 0;
        }
        //To continue the while loop.
        cout << endl;
        cout << "Please enter selection: ";
        cin >> selection;
    }

}
