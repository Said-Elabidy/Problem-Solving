#include <iostream>
using namespace std;

struct sDate
{
	short Year;
	short Month;
	short Day;
};

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

bool IsDate1BeforDate2(sDate Date1, sDate Date2)
{
	if (Date1.Year == Date2.Year)
	{
		short date1 = NumberOfDaysFromTheBegeiningofYear(Date1.Year, Date1.Month, Date1.Day);
		short date2 = NumberOfDaysFromTheBegeiningofYear(Date2.Year, Date2.Month, Date2.Day);

		if (date1 < date2)
			return true;
		else
			return false;
	}
	else if (Date1.Year > Date2.Year)
		return false;
	else
		return true;
}
int DiffrenceBetweenTwoDates(sDate Date1, sDate Date2, bool EndDay = false)
{
	int DiffrenceDays = 0;

	if (IsDate1BeforDate2(Date1, Date2))
	{
		DiffrenceDays = NumberOfDaysFromTheBegeiningofYear(Date2.Year, Date2.Month, Date2.Day) - NumberOfDaysFromTheBegeiningofYear(Date1.Year, Date1.Month, Date1.Day);
		while (Date1.Year != Date2.Year)
		{
			Date2.Year = Date2.Year - 1;
			if (CheckLeapYear(Date2.Year))
			{
				DiffrenceDays = DiffrenceDays + 366;
			}
			else
				DiffrenceDays = DiffrenceDays + 365;

		}
	}
	else
	{
		DiffrenceDays =   NumberOfDaysFromTheBegeiningofYear(Date1.Year, Date1.Month, Date1.Day) - NumberOfDaysFromTheBegeiningofYear(Date2.Year, Date2.Month, Date2.Day);
		while (Date1.Year != Date2.Year)
		{
			Date1.Year = Date1.Year - 1;
			if (CheckLeapYear(Date1.Year))
			{
				DiffrenceDays = DiffrenceDays + 366;
			}
			else
				DiffrenceDays = DiffrenceDays + 365;

		}
		DiffrenceDays *= -1;
		return EndDay == false ? DiffrenceDays : DiffrenceDays - 1;

	}
	return EndDay == false ? DiffrenceDays : DiffrenceDays + 1;
}
short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "\nPlease enter a Year? ";
	cin >> Year;
	return Year;
}
sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}



int main()
{
	cout << "	Date 1 \n";
	sDate Date1 = ReadFullDate();
	cout << "\n	Date 2 \n";
	sDate Date2 = ReadFullDate();

	cout << "\nDiffrence Between Two Dates is : " << DiffrenceBetweenTwoDates(Date1, Date2) << endl;
	cout << "\nDiffrence Between Two Dates (Include End Day) is : " << DiffrenceBetweenTwoDates(Date1, Date2, true) << endl;

	system("pause>0");
	return 0;
}

