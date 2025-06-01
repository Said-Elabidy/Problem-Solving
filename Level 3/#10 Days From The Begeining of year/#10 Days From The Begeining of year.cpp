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

int main()
{
	short Days = ReadNum("Please enter Number of Days?");
	short Month = ReadNum("Please enter Number of Months?");
	short Year = ReadNum("Please enter a Year?");

	short NumOfDaysFromBegin = NumberOfDaysFromTheBegeiningofYear(Year, Month, Days);

	printf("\nNumber of the Day from the begining of the year is : %d", NumOfDaysFromBegin);

	system("pause>0");

}

