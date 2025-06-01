#include <iostream>
using namespace std;

bool IsMatrixIdentityDiagonalRow(int Matrix[3][3],int Rows, int Colms)
{
	int Counter = 0;
	for (int i = 0; i < Rows; i=i+1)
	{
			if (Matrix[Counter][i] != 1)
			{
				return false;
			}
			Counter++;
	}
	return true;
}
int SumOfMatrix(int Matrix[3][3], int Rows, int Colms)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			Sum += Matrix[j][i];
		}
	}
	return Sum;
}
bool IsMtrixIdentityZerosValuesv(int Matrix[3][3], int Rows, int Colms)
{
	if (SumOfMatrix(Matrix, Rows, Colms) != 3)
	{
		return false;
	}
	else
		return true;
}

void PrintIdentityMatrixOrNot(bool DiagonalRow, bool ZerosValues)
{
	if (DiagonalRow && ZerosValues)
	{
		cout << "\nYes : it's Identity Matrix.\n";
	}
	else
		cout << "\nNo : it's Not Identity Matrix.\n";
}

void PrintMatrix(int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			cout << Matrix[j][i] << "      ";
		}
		cout << endl;
	}
}
int main()
{

	int Matrix[3][3] = { {1,0,0}, {0,1,0},{0,0,1} };
	cout << "Matrix 1 : \n\n";
	PrintMatrix(Matrix, 3, 3);

	bool DiagonalRow = IsMatrixIdentityDiagonalRow(Matrix, 3, 3);
	bool ZerosValues = IsMtrixIdentityZerosValuesv(Matrix, 3, 3);

	PrintIdentityMatrixOrNot(DiagonalRow, ZerosValues);

	system("pause>0");
	return 0;
}


