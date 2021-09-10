

#include <iostream>
#include <map>
#include <vector>

using namespace std;
void count_freq(string s)
{
    map<char, int> m;

    for (auto i : s)
        m[i]++;

    map<char, int>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " --> " << it->second << endl;
    }
}
int main()
{
    string s = "ANACONDA";
    count_freq(s);
    return 0;
}