// Date_calculator_console_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
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
    int diffDay = 0, diffMonth = 0, diffYear = 0;
    int* diffDayPtr;
    int* diffMonthPtr;
    int* diffYearPtr;

    diffDayPtr = &diffDay;
    diffMonthPtr = &diffMonth;
    diffYearPtr = &diffYear;

    int sMonth = 0, sDay, sYear;
    int eMonth, eDay, eYear;
    string sDate, eDate;
    int durationTotalDays, durationYear, durationMonth, durationDay;
    bool fileOpen = false;
    int numPass = 0, numFail = 0;

    // open test data file
    ifstream infile;
    infile.open("date_test_data_04.txt");
    //if (!infile) cout << "file cannot be opened" << endl;
    if (infile.is_open()) {
        cout << "file does exists" << endl;
        fileOpen = true;
    }
    else {
        cout << "file does NOT exit" << endl;
        fileOpen = false;
    }

    // Run tests until data value 99 is read from test data file.
    while ((sMonth != 99) && (fileOpen)) {

        infile >> sMonth >> sDay >> sYear >> eMonth >> eDay >> eYear;
        infile >> sDate >> eDate >> durationTotalDays >> durationYear >> durationMonth >> durationDay;

        if (sMonth != 99) {

            //cout << "From\t" << sDate << "\tto\t" << eDate;

            // This is where I will put the program that tests the date calculator

            dc.dateCalculator(sMonth, sDay, sYear, eMonth, eDay, eYear, diffMonthPtr, diffDayPtr, diffYearPtr);
            //cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

            if ((*diffMonthPtr == durationMonth) && (*diffDayPtr == durationDay) && (*diffYearPtr == durationYear)) {
                numPass++;
                // cout << "PASS" << endl;
            }
            else {
                numFail++;
                cout << "From\t" << sDate << "\tto\t" << eDate << "\tNO PASS\tNO PASS\tNO PASS" << endl;
                cout << "File:\t\t" << durationYear << " year\t" << durationMonth << " month\t" << durationDay << " day" << endl;
                cout << "Calculated:\t" << *diffYearPtr << " year\t" << *diffMonthPtr << " month\t" << *diffDayPtr << " day" << endl << endl;
            }

            //cout << "File:\t\t" << durationYear << " year\t" << durationMonth << " month\t" << durationDay << " day" << endl;
            //cout << "Calculated:\t" << *diffYearPtr << " year\t" << *diffMonthPtr << " month\t" << *diffDayPtr << " day" << endl;

            //cout << endl;

        } // if

    } // end of outer while

    cout << endl;
    cout << "Number of tests passed:\t" << numPass << endl;
    cout << "Number of tests failed:\t" << numFail << endl;

    dc.dateCalculator(6, 15, 1984, 8, 10, 2003, diffMonthPtr, diffDayPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

    dc.dateCalculator(10, 15, 2006, 10, 12, 2023, diffMonthPtr, diffDayPtr, diffYearPtr);
    cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;


    infile.close();


}

