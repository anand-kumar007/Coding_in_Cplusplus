/*
given a sentence you are supposed to print the each word of the 
sentence in a new line
Basically seperating the words
*/

#include <iostream>
using namespace std;
int main()
{
    string str;

    cout << "enter the sentence : ";
    getline(cin, str);

    int size = str.size();
    int iterator = 0;

    int i = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] != ' ')
        {
            cout << str[iterator++];
        }
        else
        {
            iterator = i + 1;
            cout << endl;
        }
    }

    cout << endl;
    return 0;
}