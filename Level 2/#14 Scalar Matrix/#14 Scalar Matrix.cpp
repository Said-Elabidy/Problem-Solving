#include <iostream>
using namespace std;

bool IsMatrixScalar(int Matrix[3][3], int Rows, int Colms)
{
	int Num = Matrix[0][0];
	for (int i = 0; i < Rows; i = i + 1)
	{
		for (int j = 0; j < Colms; j++)
		{
			if (i == j && Matrix[j][i] != Num)
			{
				return false;
			}
			if (i != j && Matrix[j][i] != 0)
			{
				return false;
			}
		}

	}
	return true;
}

void PrintScalarMatrixOrNot(bool IdentityMatrix)
{
	if (IdentityMatrix)
	{
		cout << "\nYes : it's Scalar Matrix.\n";
	}
	else
		cout << "\nNo : it's Not Scalar Matrix.\n";
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

	int Matrix[3][3] = { {9,0,0}, {0,9,0},{0,0,9} };
	cout << "Matrix 1 : \n\n";
	PrintMatrix(Matrix, 3, 3);


	PrintScalarMatrixOrNot(IsMatrixScalar(Matrix, 3, 3));

	system("pause>0");
	return 0;
}
