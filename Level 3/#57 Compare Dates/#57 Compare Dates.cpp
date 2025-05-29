#include <iostream>
using namespace std;
struct sDate
{
	short Year;
	short Month;
	short Day;
};
enum eCompareResult { Befor = -1, Equal = 0, After = 1 };
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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ?
			(Date1.Month < Date2.Month ? true :
				(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
			: false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) ?
		((Date1.Month == Date2.Month) ?
			((Date1.Day == Date2.Day) ? true : false)
			: false)
		: false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

eCompareResult CompareResult(sDate Date1, sDate Date2)
{
	
	return (IsDate1EqualDate2(Date1, Date2) ? eCompareResult::Equal : (IsDate1AfterDate2(Date1, Date2) ? eCompareResult::After : eCompareResult::Befor));
}
int main()
{
	cout << "Date 1 :\n";
	sDate Date1 = ReadFullDate();

	cout << "Date 2 :\n";
	sDate Date2 = ReadFullDate();

	cout << "\nCompare Result = " << CompareResult(Date1, Date2) << endl;

	system("pause>0");

}

