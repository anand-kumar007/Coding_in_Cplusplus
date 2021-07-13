/*
when we press key on keyboard it is not sent to 
your program rather it is buffered by the operating system
till the time it is alloted to the program

on various occassions our input goes to undesired 
container if we do no handle clearing of buffer properly
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a;
    char ch[80];
    // Enter input from user
    //  4 for example
    cin >> a;
    // Get input from user -
    // "GeeksforGeeks" for example
    // cin>>ws;
    // cin.ignore();
    fflush(stdin);
    cin.getline(ch, 80);
    // Prints 4
    cout << a << endl;
    // Printing string : This does not print string
    cout << ch << endl;
    return 0;
}

/*
 whenever we need to take the char array as input
 it is necessay to clear the buffer using
 fflush(stdin)--C/C++
 cin.ignore()--C++
 cin>>ws--C++

 */
