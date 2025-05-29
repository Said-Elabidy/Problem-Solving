#include <iostream>
using namespace std;


bool IsPalidromMatrix(int Matrix[3][3], int Rows, int Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        if (Matrix[i][0] != Matrix[i][Colms-1])
        {
            return false;
       }
    }
    return true;
}

void PrintPalindromOrNot(bool Palindrom)
{
    if (Palindrom)
    {
        cout << "\n\nYes , it is Palindrom Matrix\n";
    }
    else
        cout << "\n\nNo , it is not Palindrom Matrix\n";

}
void PrintMatrix(int Matrix[3][3], int Rows, int Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            printf("%0*d     ", 2, Matrix[j][i]);
        }
        cout << endl;
    }
}

int main()
{
    int Matrix[3][3] = { {1,5,1}, {4,7,4}, {6,2,6} };
    //int Matrix[3][3] = { {7,5,1}, {6,7,4}, {6,2,2} };

    cout << "Matrix 1 :\n\n";

    PrintMatrix(Matrix, 3, 3);

    PrintPalindromOrNot(IsPalidromMatrix(Matrix, 3, 3));

    system("pause>0");

}

