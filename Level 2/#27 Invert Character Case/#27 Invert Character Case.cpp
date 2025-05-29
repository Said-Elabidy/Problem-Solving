#include <iostream>
#include <string>
#include<cctype>
using namespace std;

char ReadCharacter(string Ask)
{
    char C1=' ';
    cout << Ask << endl;
    cin >> C1;
    return C1;
}

char InvertCharacter(char C1)
{
    bool C;
    if (C = isupper(C1))
    {
        return C1 = tolower(C1);
    }
    else
        return C1 = toupper(C1);
}
int main()
{

    char C1 = ReadCharacter("Please enter a character?");

    cout << "\n\nCharacter After Inveterd : \n";
    cout << InvertCharacter(C1);

    system("pause>0");



}

