#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int Num = 0;
	Num = rand() % (To - From + 1) + From;
	return Num;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Colms)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			Matrix[i][j] = RandomNumber(1, 10);
		}
	}
}

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			if (Matrix1[j][i] != Matrix2[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

void PrintResultOfComparing(bool Typical)
{
	if (Typical)
	{
		cout << "\n\nYes : Matrices Are Typical.\n\n";
	}
	else
		cout << "\n\nNo : Matrices Are Not Typical.\n\n";
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
	int Matrix1[3][3], Matrix2[3][3];

	cout << "\nMatrix 1:\n\n";
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix 2:\n\n";
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	PrintMatrix(Matrix2, 3, 3);

	PrintResultOfComparing(AreTypicalMatrices(Matrix1, Matrix2, 3, 3));

	system("pause>0");
	return 0;

}
