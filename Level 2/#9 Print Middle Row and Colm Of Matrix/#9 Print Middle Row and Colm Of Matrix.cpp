#include <iostream>
#include <iomanip>
using namespace std;

int RandomNum(int From, int To)
{
	int Num = 0;
	Num = rand() % (To - From + 1) + From;
	return Num;
}

void FillMatrixWithOrderNumber(int Matrix[3][3], int Rows, int Colms)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{

			Matrix[j][i] = RandomNum(1, 10);
		}
	}
}

void PrintMiddleRow(int Matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("%0*d    ",2, Matrix[1][i]);
	}
}
void PrintMiddleColm(int Matrix[3][3])
{
	for (int i = 0; i <3; i++)
	{
		printf("%0*d    ",2, Matrix[i][1]);
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			printf("%0*d     ", 2, Matrix[i][j]);
		}
		cout << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	int Arra[3];
	cout << "\n3x3 Matrix of Random Number:\n\n";
	FillMatrixWithOrderNumber(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << "\n\nMiddle Row:\n";
	PrintMiddleRow(Matrix);

	cout << "\n\nMiddle Colm:\n";
	PrintMiddleColm(Matrix);

	system("pause>0");
	return 0;
}

