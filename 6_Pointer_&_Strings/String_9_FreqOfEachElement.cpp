/* you will be give a string
 your task is to find the frequency of each element and print it
*/

#include <iostream>
using namespace std;
void FindEachFreq(string s);

int main()
{
    string s;
    cout << "enter a string : ";
    getline(cin, s);

    FindEachFreq(s);
    return 0;
}

void FindEachFreq(string s)
{
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }

    cout << "frequency of each element  is : " << endl;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            char ch = 'a' + i;
            cout << "freq of " << ch << " is : " << freq[i] << endl;
        }
    }
}