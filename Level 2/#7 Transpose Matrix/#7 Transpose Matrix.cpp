#include <iostream>
#include <iomanip>
using namespace std;

void FillArrayWithOrderNumbers(int Matrix[3][3], int Rows, int Colms)
{
	int Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			Counter++;
			Matrix[j][i] = Counter;
		}
	}
}

void TransPoseMatrix(int NewMatrix[3][3], int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			NewMatrix[j][i] = Matrix[i][j];
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Colms)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colms; j++)
		{
			cout << setw(3) << Matrix[j][i] << "    ";
		}
		cout << endl;
	}
}
int main()
{
	int Matrix[3][3];
	int NewMatrix[3][3];
	cout << "\n3x3 Matrix of Order Numbers:\n\n";

	FillArrayWithOrderNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << "\n3x3 Transpose Matrix of Order Numbers:\n\n";
	TransPoseMatrix(NewMatrix, Matrix, 3, 3);
	PrintMatrix(NewMatrix, 3, 3);

	system("pause>0");
	return 0;
}

