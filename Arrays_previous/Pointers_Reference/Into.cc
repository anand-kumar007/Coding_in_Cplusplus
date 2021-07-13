#include<iostream>
using namespace std;

int main()
{
    string food = "Pizza";
    //pointer to food
    string* ptr = &food;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
 

    //if we reassign the pointer then the previous value will also get changed

    *ptr = "Hamburger";
    cout<<*ptr<<endl;
    cout<<food<<endl;  //would give "Hamburger"


    //reference to food
    string& meal = food;
    cout<<meal<<endl; //will give "Pizza"
    cout<<food<<endl;

    
    return 0;
}