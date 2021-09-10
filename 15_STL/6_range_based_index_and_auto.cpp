/* 
range based loop 
directly the value comes into that variable
insted of their indexes and all

C++11 and its higher versions supports 

works for all the containers

note only a copy of values comes not the reference

*/

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4};
    //need to declare the value variable in for loop only
    for (int &value : v)
    {
        //use value only if no refernce you wanna use
        value++;
        cout << value << " ";
    }
    cout << endl;
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << endl;

    // auto keyword

    auto num = 0.1;
    cout << "data type of num : " << typeid(num).name() << endl;

    vector<pair<int, int>> p = {{1, 2}, {3, 4}};

    for (pair<int, int> value : p)
    {
        cout << value.first << " " << value.second << endl;
    }

    cout << endl;
    for (auto value : p)
    {
        cout << value.first << " " << value.second << endl;
    }
    cout << endl;

    // vector<int> :: iterator it;
    //just use auto and it will detemine the type by itself

    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}

// however you can make it to have reference rather than just the variable

// auto keyword automatically determines the data type of variable based on the
// value assigned to it