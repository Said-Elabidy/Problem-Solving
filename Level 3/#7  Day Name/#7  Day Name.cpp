#include <iostream>
using namespace std;
short ReadNum(string Ask)
{
	cout << Ask << endl;
	short Num = 0;
	cin >> Num;
	return Num;
}

short DayOrder(short Year, short Month, short Day)
{
	short A = (14 - Month) / 12;
	short Y = Year - A;
	short M = Month + (12 * A) - 2;

	short D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	//0:sunday , 1:Monday , 2:Tuesday etc...
	return D;
}

string DayName(short DayOrder)
{
	string Arra[7] = { "Sun","Mon","Tues","Wed","Thurs","Fri","Sat" };
	return Arra[DayOrder];
}
int main()
{
	short Year = ReadNum("Please enter the Year ?");
	short Month = ReadNum("Please enter the Month ?");
	short Day = ReadNum("Please enter the Day ?");
	short dayOrder = DayOrder(Year, Month, Day);
	printf("\n\nDate      :%d/%d/%d \n", Day, Month, Year);
	printf("Day Order :%d\n", dayOrder);
	cout << DayName(dayOrder);

	system("pause>0");
}

