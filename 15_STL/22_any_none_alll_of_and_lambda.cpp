
/* 
all returns true or false boolean value
all_of
none_of
any_of

lambda function [](int a, int b) { return ;}

*/

#include <iostream>
#include <vector>
#include <algorithm>

bool is_positive(int x)
{
    return x > 0;
}

bool is_negative(int x)
{
    return x < 0;
}
using namespace std;
int main()
{
    // lambda function
    cout << [](int a, int b)
    { return a + b; }(13, 20)
         << endl;

    auto fun = [](int a, int b)
    { return a * b; };

    cout << fun(9, 10) << endl;

    vector<int> v = {1, 2, 3};

    //check if all are greater than 3
    cout << all_of(v.begin(), v.end(), [](int x)
                   { return x > 3; })
         << endl; //0

    cout << all_of(v.begin(), v.end(), is_positive) << endl; //1

    //any_of
    cout << any_of(v.begin(), v.end(), is_negative) << endl; //0

    //none_of
    //if none of them satisfy then only return true
    cout << none_of(v.begin(), v.end(), is_positive) << endl; //0
    cout << none_of(v.begin(), v.end(), is_negative) << endl; //1

    cout << any_of(v.begin(), v.end(), [](int x)
                   { return x % 2 == 0; })
         << endl; //1
    return 0;
}