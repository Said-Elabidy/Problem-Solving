#include <iostream>
using namespace std;


union MyUnion 
{
    int intValue;
    float floatValue;
    char charValue;
};

int main()
{

    MyUnion myUnion;

    myUnion.intValue = 42;
    cout << "Integer value: " << myUnion.intValue << endl;

    myUnion.floatValue = 3.14f;
    cout << "Float value: " << myUnion.floatValue << endl;

    myUnion.charValue = 'A';
    cout << "Char value: " << myUnion.charValue << endl;


    // This will give me run time error becuase the last variable store in union was Character.
    cout << "Integer value: " << myUnion.floatValue << endl;


    system("pause>0");
    return 0;
}