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
int SumOfMatrix(int Matrix[3][3], int Rows, int Colms)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			Sum+=Matrix[i][j] ;
		}
	}
	return Sum;
}
void PrintMatrix(int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			printf("%0*d     ",2,Matrix[i][j]);
		}
		cout << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	cout << "\nMatrix1:\n\n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << "\n\nSum of the Matrix: " << SumOfMatrix(Matrix, 3, 3) << endl;

	system("pause>0");
	return 0;

}

