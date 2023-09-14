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

	//const int daysInMonthsNonLeap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// Sometimes you have to look at the number of days in the prior month. If the month is jan, then
	// going back one month is outside of the array. Add dec as the month in [0] and access the 
	// array by the month number to get the number of days for the month
	// dec, jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	const int daysInMonthsNonLeap[13] = {31,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	//const int daysInMonthsLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int daysInYearLeap = 366;
	const int daysInYearNonLeap = 365;
	const int monthsInYear = 12;

	int tmpa, tmpb, tmpc, tmpd;

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
	void dateCalculator(int startMonth, int startDay, int startYear, int endMonth, int endDay, int endYear, int* diffMonthPtr, int* diffDayPtr, int* diffYearPtr) {

		sMonth = startMonth;
		sDay = startDay;
		sYear = startYear;

		eMonth = endMonth;
		eDay = endDay;
		eYear = endYear;

		durationYear = 0;
		durationMonth = 0;
		durationDay = 0;

		tmpa = 0;
		tmpb = 0;
		tmpc = 0;
		tmpd = 0;

		// Put code here to detect when eDate is before sDate
		// LL: need to change code to account for when the last month falls in February of a Leap year.

		// cases: 0x000, 10, 12
		if ((sYear <= eYear) && (sMonth <= eMonth) && (sDay <= eDay)) {
			durationYear = eYear - sYear;
			durationMonth = eMonth - sMonth;
			durationDay = eDay - sDay;
		}

		// case 0x001
		//else if ((sYear <= eYear) && (sMonth < eMonth) && (sDay > eDay)) { // may need this
		//else if ((sYear <= eYear) && (sMonth <= eMonth) && (sDay > eDay)) {

		else if ((sYear <= eYear) && (sMonth < eMonth) && (sDay > eDay)) {
			durationYear = eYear - sYear;
			durationMonth = (eMonth - 1) - sMonth;
			durationDay = (daysInMonthsNonLeap[(eMonth - 1)] -sDay) + eDay;
		}

		// case 0x010
		else if ((sYear < eYear) && (sMonth > eMonth) && (sDay <= eDay)) {
			durationYear = (eYear - 1) - sYear;
			durationMonth = (monthsInYear - sMonth) + eMonth;
			durationDay = eDay - sDay;
		}

		// case 0x011
		else if ((sYear < eYear) && (sMonth > eMonth) && (sDay > eDay)) {
			durationYear = (eYear - 1) - sYear;
			durationMonth = (monthsInYear - sMonth) + (eMonth - 1);
			//durationDay = (daysInMonthsNonLeap[(eMonth - 1)] - sDay) + (eDay - 1);
			durationDay = (daysInMonthsNonLeap[(eMonth - 1)] - sDay) + eDay;
		}

		// case 11
		// case 0x11 can be change to cover case 11: make month >=
		else if ((sYear < eYear) && (sMonth == eMonth) && (sDay > eDay)) {
			durationYear = (eYear - 1) - sYear;
			durationMonth = (monthsInYear - sMonth) + (eMonth - 1);
			durationDay = (daysInMonthsNonLeap[(eMonth - 1)] - sDay) + eDay;
		}

		// unknown case
		else {
			cout << "Unknown Case" << endl;
		}

		*diffYearPtr = durationYear;
		*diffMonthPtr = durationMonth;
		*diffDayPtr = durationDay;
	}


};

