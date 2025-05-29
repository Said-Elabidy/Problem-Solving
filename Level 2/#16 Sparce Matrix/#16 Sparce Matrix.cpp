#include <iostream>
using namespace std;


int RandomNumber(int From, int To)
{
    int Num = 0;
    Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrix(int Matrix[3][3], int Rows, int Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            Matrix[j][i] = RandomNumber(0, 5);
        }
    }
}

bool IsMatrixSparce(int Matrix[3][3], int Rows, int Colms)
{
    int NumberOfZeros = 0;
    int NumberOfDigits = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (Matrix[j][i] == 0)
            {
                NumberOfZeros++;
            }
            else
                NumberOfDigits++;
        }
    }
    if (NumberOfZeros > NumberOfDigits)
        return true;
    else
        return false;
}

void PrintMatrix(int Matrix[3][3], int Rows, int Colms)
{
    cout << "\n\nMatrix 1 :\n";
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            printf("%0*d     ", 2, Matrix[j][i]);
        }
        cout << endl;
    }
}

void PrintSparceOrNot(bool Sparce)
{
    if (Sparce)
    {
        cout << "\n\nYes It's Sparce Matrix.\n\n";
    }
    else
        cout << "\n\nNo It's Not Sparce Matrix.\n\n";

}
int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrix(Matrix, 3, 3);
    PrintMatrix(Matrix, 3, 3);

    PrintSparceOrNot(IsMatrixSparce(Matrix, 3, 3));

    system("pause>0");
    return 0;

}

