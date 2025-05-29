#include <iostream>
using namespace std;

short ReadNum(string Ask)
{
	cout << Ask << endl;
	short Num = 0;
	cin >> Num;
	return Num;
}

bool CheckLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{

	if (Month < 1 || Month>12)
		return 0;

	int DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (CheckLeapYear(Year) ? 29 : 28) : DaysInMonth[Month - 1];
}

short NumberOfDaysFromTheBegeiningofYear(short Year, short Month, short Day)
{
	short Sum = 0;
	for (int i = 1; i < Month; i++)
	{
		Sum += NumberOfDaysInAMonth(i, Year);
	}
	Sum = Sum + Day;
	return Sum;
}

struct sDate
{
	short Year;
	short Month;
	short Day;
};


sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	sDate Date;
	Date.Year = Year;
	Date.Month = 1;  // Start from January

	// Loop to determine the month and day based on the day order
	while (true)
	{
		// Get the number of days in the current month
		short MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (DateOrderInYear > MonthDays)
		{
			// If the remaining days exceed the days in this month, move to the next month
			DateOrderInYear -= MonthDays;
			Date.Month++;
		}
		else
		{
			// If the remaining days are within this month, set the day and break out of the loop
			Date.Day = DateOrderInYear;
			break;
		}
	}

	return Date;
}

struct stNewDate
{
	short Year;
	short RemainDays;
};

stNewDate NewDateAfterAddingDays(short Year, short Month, short Day,short DaysAdded)
{
	stNewDate Date;
	short DaysInYear = 0;

	Date.Year = Year;

	Date.RemainDays = DaysAdded + NumberOfDaysFromTheBegeiningofYear(Year, Month, Day);

	while (true)
	{
		if (CheckLeapYear(Date.Year+1))
		{
			DaysInYear = 366;
		}
		else
		{
			DaysInYear = 365;
		}

		if (Date.RemainDays > DaysInYear)
		{
			Date.Year = Date.Year + 1;
			Date.RemainDays -= DaysInYear;
		}
		else
		{
			break;
		}
	}

	return Date;

}


int main()
{
	short Days = ReadNum("Please enter Number of Days?");
	short Month = ReadNum("Please enter Number of Months?");
	short Year = ReadNum("Please enter a Year?");
	short DaysAdded = ReadNum("Please enter Days To Add?");

	stNewDate NewDate = NewDateAfterAddingDays(Year, Month, Days, DaysAdded);

	sDate Date;

	Date = GetDateFromDayOrderInYear(NewDate.RemainDays, NewDate.Year);
	cout << "\n\nDate for [" << DaysAdded << "] is : ";
	printf("%d/%d/%d \n", Date.Day, Date.Month, Date.Year);


	system("pause>0");

}

