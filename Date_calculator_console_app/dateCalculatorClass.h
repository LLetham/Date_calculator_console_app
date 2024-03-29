#pragma once

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

using namespace std;


class dateCalculatorClass
{
	// This date calculator calculates the total number of days between the startDate
	// and the endDate then converts the number of days into the no. of days, months and years
	// between the startDate and the endDate.
	// The no. of days between startDate and endDate is stored in diffDate which is passed to
	// the class.

private:
	int i = 0;
	int	sDay = 0, sMonth = 0, sYear = 0; // start year date
	int	eDay = 0, eMonth = 0, eYear = 0; // end year date
	int durationDay = 0, durationMonth = 0, durationYear = 0; //days, months, years between start date and end date
	bool leapYear = false;
	bool outputFlag = false;

	//const int daysInMonthsNonLeap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// Sometimes you have to look at the number of days in the prior month. If the month is jan, then
	// going back one month is outside of the array. Add dec as the month in [0] and access the 
	// array by the month number to get the number of days for the month
	// dec, jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	int daysInMonthsNonLeap[13] = {31,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int daysInMonthsLeap[13] = {31,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int *daysInMonthPtr;
	const int daysInYearLeap = 366;
	const int daysInYearNonLeap = 365;
	const int monthsInYear = 12;

	// determine if the year is a leap year.
	// return 1 if leap year.
	// return 0 if not leap year.
	// Used only in this class, so made private
	bool isLeapYear(int year) {
		if (
			(((year % 4) == 0) && ((year % 100) != 0)) ||
			(((year % 4) == 0) && ((year % 100) == 0) && ((year % 400) == 0)))
			leapYear = true;
		else leapYear = false;

		//if (leapYear) cout << year << "  Leap Year" << endl;

		return (leapYear);
	}

public:

	// function to calculate duration between between startDate and endDate.
	// calculation is done in Years, Months and Days. Days are not counted between
	// the start date sdate and the end date eDate.
	void dateCalculator(int startMonth, int startDay, int startYear, int endMonth, int endDay, int endYear, int* diffMonthPtr, int* diffDayPtr, int* diffYearPtr) {

		// Transfer dates passed to subroutine to local variables
		sMonth = startMonth;
		sDay = startDay;
		sYear = startYear;

		eMonth = endMonth;
		eDay = endDay;
		eYear = endYear;

		outputFlag = false;

		// check limits on days in months and number of months
		// Fix some of the possible errors in dates
		if (sYear < 0) {
			sYear = 0;
			outputFlag = true;
		}

		if (eYear < 0) {
			eYear = 0;
			outputFlag = true;
		}

		if (sMonth < 1) {
			sMonth = 1;
			outputFlag = true;
		}
		else if (sMonth > monthsInYear) {
			sMonth = 12;
			outputFlag = true;
		}
			
		if (eMonth < 1) {
			eMonth = 1;
			outputFlag = true;
		}
		else if (eMonth > monthsInYear) {
			eMonth = 12;
			outputFlag = true;
		}

		// If end date is before the start date, swap the dates and calculate
		// the years, months and days in between.
		if ((sYear > eYear) ||
			((sYear == eYear) && (sMonth > eMonth)) ||
			((sYear == eYear) && (sMonth == eMonth)) && (sDay > eDay)) {
			//cout << "End date occurs before Start date: switching dates" << endl;
			sMonth = endMonth;
			sDay = endDay;
			sYear = endYear;

			eMonth = startMonth;
			eDay = startDay;
			eYear = startYear;

			outputFlag = true;
		}

		if (outputFlag) {
			cout << "Date error found. Duration calculated from\t" << sMonth << "/" << sDay << "/" << sYear;
			cout << "\tto\t" << eMonth << "/" << eDay << "/" << eYear << endl;
		}

		// Note: 03/31/1987 to 05/05/1987 is counted as follows:
		// 03/31/1987 - 04/30/1987 = 1 month even though there are not 31 days in April because a month past.
		// 04/30/1987 - 05/05/1987 is counted as 5 days.
		// total: 0 years, 1 month 5 days.
		// 01/31/1987 to 03/05/1987 is counted as follows:
		// 01/31/1987 - 02/28/1987 = 1 month even though there are not 31 days in February because a month past.
		// 02/28/1987 - 03/05/1987 is counted as 5 days.
		// total: 0 years, 1 month 5 days.


		durationYear = 0;
		durationMonth = 0;
		durationDay = 0;

		/*****************************************************************/
		// Start counting years, months and days between sDate and eDate.

		// cases:0, 2, 6, 8, 9, 11, 15 and 17
		if (((eYear >= sYear) && (eMonth > sMonth) && (eDay > sDay)) ||		// cases 0, 9
			((eYear >= sYear) && (eMonth == sMonth) && (eDay > sDay)) ||	// cases 2, 11
			((eYear >= sYear) && (eMonth > sMonth) && (eDay == sDay)) ||	// cases 6, 15
			((eYear > sYear) && (eMonth == sMonth) && (eDay == sDay)) ||	// cases 8, 17
			((eYear == sYear) && (eMonth == sMonth) && (eDay == sDay))		// start date = end date
			)
		{
			durationYear = eYear - sYear;
			durationMonth = eMonth - sMonth;
			durationDay = eDay - sDay;
		}

		// cases: 1 and 7
		else if (((eYear > sYear) && (eMonth < sMonth) && (eDay > sDay)) ||		// case 1
				((eYear > sYear) && (eMonth < sMonth) && (eDay == sDay))		// case 7
			)
		{
			durationYear = (eYear - sYear) - 1;
			durationMonth = (monthsInYear - sMonth) + eMonth;
			durationDay = eDay - sDay;
		}

		// cases: 3 and 12
		else if (((eYear >= sYear) && (eMonth > sMonth) && (eDay < sDay))	// cases 3, 12
			)
		{
			durationYear = (eYear - sYear);
			durationMonth = (eMonth - sMonth) - 1;

			// Check for leap year
			if (isLeapYear(eYear) && ((eMonth - 1) == 2)) {
				daysInMonthPtr = daysInMonthsLeap;
			}
			else {
				daysInMonthPtr = daysInMonthsNonLeap;
			}

			// If sDay > daysInMonthPtr[eMonth - 1], then do not subtract sDay from daysInMonthPtr[eMonth - 1]
			// because all of the days of the eMonth - 1 month have been accounted for.
			if (sDay >= daysInMonthPtr[eMonth - 1]) {
				durationDay = eDay;
			}
			else {
				durationDay = (daysInMonthPtr[eMonth - 1] - sDay) + eDay;
			}
		}

		// cases: 4 and 5
		else if (((eYear > sYear) && (eMonth <= sMonth) && (eDay < sDay)) 		// cases 4, 5
			)
		{
			durationYear = (eYear - sYear) - 1;
			durationMonth = ((monthsInYear - sMonth) + eMonth) - 1;

			// Check for leap year
			if (isLeapYear(eYear) && ((eMonth - 1) == 2)) {
				daysInMonthPtr = daysInMonthsLeap;
			}
			else {
				daysInMonthPtr = daysInMonthsNonLeap;
			}

			// If sDay > daysInMonthPtr[eMonth - 1], then do not subtract sDay from daysInMonthPtr[eMonth - 1]
			// because all of the days of the eMonth - 1 month have been accounted for.
			if (sDay >= daysInMonthPtr[eMonth - 1]) {
				durationDay = eDay;
			}
			else {
				durationDay = (daysInMonthPtr[eMonth - 1] - sDay) + eDay;
			}
		}

		else {
			// date does not fall in any of the above classes
			cout << "ERROR: Date formulas not found" << endl;
		}

		*diffYearPtr = durationYear;
		*diffMonthPtr = durationMonth;
		*diffDayPtr = durationDay;
	}


};

