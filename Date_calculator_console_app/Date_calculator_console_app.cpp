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

    std::cout << "Hello World!\n";

    // open test data file
    ifstream infile;
    infile.open("date_test_data_02.txt");
    //if (!infile) cout << "file cannot be opened" << endl;
    if (infile.is_open()) {
        cout << "file does exists" << endl;
        fileOpen = true;
    }
    else {
        cout << "file does NOT exit" << endl;
        fileOpen = false;
    }

    while ((sMonth != 99) && (fileOpen)) {

        infile >> sMonth >> sDay >> sYear >> eMonth >> eDay >> eYear;
        infile >> sDate >> eDate >> durationTotalDays >> durationYear >> durationMonth >> durationDay;
        //cout << "sMonth: " << sMonth << endl;
        //cout << "sDay: " << sDay << endl;
        //cout << "sYear: " << sYear << endl;
        //cout << "eMonth: " << eMonth << endl;
        //cout << "eDay: " << eDay << endl;
        //cout << "eYear: " << eYear << endl;
        //cout << "sDate: " << sDate << endl;
        //cout << "eDate: " << eDate << endl;
        //cout << "durationTotalDays: " << durationTotalDays << endl;
        //cout << "durationYear: " << durationYear << endl;
        //cout << "durationMonth: " << durationMonth << endl;
        //cout << "durationDay: " << durationDay << endl;

        if (sMonth != 99) {

            cout << "From\t" << sDate << "\tto\t" << eDate << endl;

            // This is where I will put the program that tests the date calculator

            dc.dateCalculator(sMonth, sDay, sYear, eMonth, eDay, eYear, diffMonthPtr, diffDayPtr, diffYearPtr);
            //cout << *diffYearPtr << " year " << *diffMonthPtr << " month " << *diffDayPtr << " day " << endl;

            if ((*diffMonthPtr == durationMonth) && (*diffDayPtr == durationDay) && (*diffYearPtr == durationYear)) {
                numPass++;
                cout << "PASS" << endl;
                cout << "File:\t\t" << durationYear << " year\t" << durationMonth << " month\t" << durationDay << " day" << endl;
                cout << "Calculated:\t" << *diffYearPtr << " year\t" << *diffMonthPtr << " month\t" << *diffDayPtr << " day" << endl;
            }
            else {
                numFail++;
                cout << "NO pass" << endl;
                cout << "NO pass" << endl;
                cout << "File:\t\t" << durationYear << " year\t" << durationMonth << " month\t" << durationDay << " day" << endl;
                cout << "Calculated:\t" << *diffYearPtr << " year\t" << *diffMonthPtr << " month\t" << *diffDayPtr << " day" << endl;
            }

            cout << endl;

        } // if

    } // end of outer while

    cout << endl;
    cout << "Number of tests passed:\t" << numPass << endl;
    cout << "Number of tests failed:\t" << numFail << endl;

    infile.close();


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
