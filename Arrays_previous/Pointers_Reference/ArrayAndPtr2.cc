// array name as pointer (note there are cases when array names doesn't act as ptr(but very few))

// C++ Program to insert and display data entered by using pointer notation.

#include <iostream>
using namespace std;

int main()
{
    float arr[5];
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; ++i)
    {   
       //arr is an indexing pointer so on adding it points to next index not to next memory location 
       cin>>*(arr +i);
       // arr++;   //illegal
    }
    cout << "Displaying data: " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << *(arr + i) << endl;
    }

    return 0;
}