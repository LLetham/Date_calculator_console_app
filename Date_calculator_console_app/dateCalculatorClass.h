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
	int diffDay = 0, diffMonth = 0, diffYear = 0; //days, months, years between start date and end date
	double numDay = 0; // number of days between start date and end date
	int numMonth = 0;  // number of months as part of years, months, days from start date to end date
	double numYear = 0, intPart_numYear = 0, factPart_numYear = 0; // number of years as calculated from numDays
	int daysStartYear = 0;
	int daysEndYear = 0;
	int daysDiff = 0;
	int totalDays = 0;
	bool leapYear = false;
	int currentYear; // NOT USED

	const int daysInMonthsNonLeap[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const int daysInMonthsLeap[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const int daysInYearLeap = 366;
	const int daysInYearNonLeap = 365;
	const int monthsInYear = 12;
	double daysPerYear = 365.242199;

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

	// function to calculate the difference in days between startDate and endDate.
	void dateCalculator(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear, int* diffDayPtr, int* diffMonthPtr, int* diffYearPtr) {

		sDay = startDay;
		sMonth = startMonth;
		sYear = startYear;

		eDay = endDay;
		eMonth = endMonth;
		eYear = endYear;

		// if the endYear is not the same as the startYear, then:
		// 1. count the days in the startYear to the end of the startYear.
		// 2. count the days from the start of the endYear to the date in the endYear.
		// 3. count the days in the years between startYear and endYear.

		/////////////////////
		// Calculate days from start date to end of startYear.
		// If the sYear is a leap year, use daysInMonthLeap to count the days, otherwise use daysInMonthNonLeap.
		daysStartYear = 0;
		if (isLeapYear(sYear)) {
			// get days in first month, which might be a partial month
			daysStartYear = daysInMonthsLeap[sMonth - 1] - sDay;
			sMonth++; // move to the next month in startYear;

			// sum up the days in the whole months of the year
			for (sMonth; sMonth <= monthsInYear; sMonth++) {
				daysStartYear += daysInMonthsLeap[sMonth - 1];
			}
		}
		else {
			// get days in first month, which might be a partial month
			daysStartYear = daysInMonthsNonLeap[sMonth - 1] - sDay;
			sMonth++; // move to the next month in startYear;

			// sum up the days in the whole months of the year
			for (sMonth; sMonth <= monthsInYear; sMonth++) {
				daysStartYear += daysInMonthsNonLeap[sMonth - 1];
			}
		}


		// Calculate days from start of endYear to the date in endYear if
		// endYear is not the same as startYear.
		i = 1;
		daysEndYear = 0;
		if (isLeapYear(eYear)) {
			// sum the days in the complete months
			for (i; i < eMonth; i++) {
				daysEndYear += daysInMonthsLeap[i - 1];
			}

			// add the days from the last month, which might be a partial month
			daysEndYear += sDay;

		}
		else {
			// sum the days in the complete months
			for (i; i < eMonth; i++) {
				daysEndYear += daysInMonthsNonLeap[i - 1];
			}

			// add the days from the last month, which might be a partial month
			daysEndYear += eDay;
		}


		// Count the days of the years between startYear and endYear excluding startYear and endYear
		sYear++;
		totalDays = 0;
		totalDays = daysStartYear + daysEndYear;

		for (sYear; sYear < (eYear); sYear++) {
			if (isLeapYear(sYear)) {
				totalDays += 366;
			}
			else {
				totalDays += 365;
			}
		}

		cout << "Days between startDate and endDate: " << totalDays << endl << endl;

		// Convert days to years, months and days
		numYear = 0;
		numYear = totalDays / daysPerYear;
		factPart_numYear = modf(numYear, &intPart_numYear); // split float into interger and decimal portion

		diffYear = (int)intPart_numYear; // get years, cast into integer

		numDay = 0;
		// get month
		if (isLeapYear(eYear)) {
			numDay = factPart_numYear * daysInYearLeap;
		}
		else {
			numDay = factPart_numYear * daysInYearNonLeap;
		}

		i = 0;
		numMonth = 0;
		if (isLeapYear(eYear)) {
			while (numDay > daysInMonthsLeap[i]) {
				numDay = numDay - daysInMonthsLeap[i];
				numMonth++; // enough days for a whole month
				i++; // move to next month
			}
		}
		else {
			while (numDay > daysInMonthsNonLeap[i]) {
				numDay = numDay - daysInMonthsNonLeap[i];
				numMonth++; // enough days for a whole month
				i++; // move to next month
			}
		}

		diffDay = (int)numDay;
		diffMonth = numMonth;

		*diffDayPtr = diffDay;
		*diffMonthPtr = diffMonth;
		*diffYearPtr = diffYear;
	}


};

