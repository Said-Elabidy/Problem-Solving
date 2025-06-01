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
			
			Matrix[j][i] = RandomNum(1,10);
		}
	}
}

void MultiplyTwoMatrices(int MultiMatrix[3][3], int Matrix1[3][3], int Matrix2[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			MultiMatrix[j][i] = Matrix1[j][i] * Matrix2[j][i];
		}
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
	int MultipliedMatrix[3][3], Matrix1[3][3], Matrix2[3][3];

	cout << "\nMatrix 1 :\n\n";
	FillMatrixWithOrderNumber(Matrix1, 3, 3);
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrux 2:\n\n";
	FillMatrixWithOrderNumber(Matrix2, 3, 3);
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nResult:\n\n";
	MultiplyTwoMatrices(MultipliedMatrix, Matrix1, Matrix2, 3, 3);
	PrintMatrix(MultipliedMatrix, 3, 3);

	system("pause>0");
	return 0;
}

