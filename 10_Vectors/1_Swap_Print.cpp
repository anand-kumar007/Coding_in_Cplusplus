/*
vector are like dynamic arrays 
*/

#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> v)
{
    //element is an item of vector v now
    for (auto element : v)
        cout << element << " ";

    cout << endl;
    return;
}

void Intechange(vector<int> a, vector<int> b)
{
    //will swap two vectors even if they are unequal
    swap(a, b);
    cout << "v1 vector is : " << endl;

    Print(a);
    cout << "v2 vector is : " << endl;
    Print(b);

    return;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    cout << "v1 vector is : " << endl;

    //print using iterator(it would be a pointer)
    vector<int>::iterator it;

    for (it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //deleting last element

    v1.pop_back();

    cout << "after deleting last element v1 vector is : " << endl;

    //print using simple method
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "Befor swapping " << endl;
    //Interchange their values
    vector<int> v2(4, 10);
    cout << "v2 vector is : " << endl;
    Print(v2);
    cout << "v1 vector is : " << endl;
    Print(v1);

    cout << "after swapping ";
    Intechange(v1, v2);

    return 0;
}