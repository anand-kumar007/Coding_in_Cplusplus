#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin,str);

    // forward iterator
    string :: iterator it;
    
    for(it=str.begin(); it != str.end(); it++)
    {
        cout<<*it;
    }

    cout<<endl;
    //using reverse iterator
    string ::reverse_iterator rit;

    for(rit= str.rbegin(); rit != str.rend(); rit++)
    {
        cout<<*rit;
    }

    return 0;
}