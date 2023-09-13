// Date_calculator_console_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <climits> // INT_MIN, INT_MAX
#include <ctime>
#include "dateCalculatorClass.h"

using namespace std;


int main()
{
    dateCalculatorClass dc;
    int diffDay, diffMonth, diffYear;
    int* diffDayPtr;
    int* diffMonthPtr;
    int* diffYearPtr;

    diffDayPtr = &diffDay;
    diffMonthPtr = &diffMonth;
    diffYearPtr = &diffYear;


    std::cout << "Hello World!\n";

    // This is where I will put the program that tests the date calculator

    // days 582
    // ans = 1 year, 7 month, 3 day
    dc.dateCalculator(14, 5, 2022, 17, 12, 2023, diffDayPtr, diffMonthPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

    // days 8664
    // ans = 23 year, 8 month, 20 day
    dc.dateCalculator(28, 3, 2000, 17, 12, 2023, diffDayPtr, diffMonthPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

    // days 79,959
    // ans = 218 year, 11 month, 1 day
    dc.dateCalculator(3, 2, 1804, 4, 1, 2023, diffDayPtr, diffMonthPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

    // days 119,393
    // ans = 326 year, 10 month, 21 day
    dc.dateCalculator(10, 7, 1660, 31, 5, 1987, diffDayPtr, diffMonthPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

    // days 2 months, 25 days
    dc.dateCalculator(20, 3, 2023, 14, 6, 2023, diffDayPtr, diffMonthPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

    // ans = 9 month, 22 day
    dc.dateCalculator(3, 2, 2023, 25, 11, 2023, diffDayPtr, diffMonthPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

    // ans = 19 day
    dc.dateCalculator(5, 10, 2023, 23, 10, 2023, diffDayPtr, diffMonthPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
