#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int Number = 0;
	Number = rand() % (To - From+1)+From;
	return Number;
}

void FillMatrix(int Matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int Matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << Matrix[i][j] << "	";
		}
		cout << endl;
	}

}
int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	cout << "The Following is 3x3 Random Matrix :\n\n";
	FillMatrix(Matrix);
	PrintMatrix(Matrix);

	system("pause>0");
	return 0;

}


