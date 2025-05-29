#include <iostream>
#include <iomanip>
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

short DayOrder(short Year, short Month, short Day=1)
{
	short A = (14 - Month) / 12;
	short Y = Year - A;
	short M = Month + (12 * A) - 2;

	short D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	return D;
}
string MonthName(short Month)
{
	string MonthArra[12] = { "jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return MonthArra[Month - 1];
}
void PrintMonthCalender(short Month, short Year)
{
	short Counter = 1;
	string MonthShortName = MonthName(Month);
	short dayOrder = DayOrder(Year, Month);
	short DaysOfMonth = NumberOfDaysInAMonth(Month, Year);
	cout << "----------------" << MonthShortName << "----------------\n";

	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

	int i;
	for (i=0; i < dayOrder; i++)
	{
		cout << "     ";
	};

	for (int j = 1; j <= DaysOfMonth; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			cout << endl;
		}

	}
	cout << "\n-----------------------------------";

}
int main()
{
	short Year = ReadNum("Please enter a Year?");
	short Month = ReadNum("Please enter a Month?");

	PrintMonthCalender(Month,Year);

	system("pause>0");



}

