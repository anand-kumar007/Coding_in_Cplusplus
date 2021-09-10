/*

unordered_set

most of operations O(1)
same limitations as of  unordered maps
like complex values can't be used as keys
since implementation is using hashmap etc

unordere<pair<int,int>> etc not allowed
unordere<set<int>> etc not allowed
only basic data type can be stored


Given n string and q queries tell if the queried
string is present among those n strings or not

N <= 10^6
|S| <= 100
Q <= 10^6

*/

#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<string> st;
    int n;
    cout << "Enter n : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        st.insert(s); //O(1)
    }

    int q;
    cout << "Enter total q : ";
    cin >> q;
    fflush(stdin);
    while (q--)
    {
        string temp;
        cin >> temp;

        auto it = st.find(temp); //O(1)
        if (it != st.end())
        {
            cout << "Yes " << endl;
        }
        else
        {
            cout << "No " << endl;
        }
    }

    return 0;
}