
/* mulitset 

like sets only but allows duplicate (multiple)
keys to store (ordered one)

again red black implementation and log(n)
time for most of the things

multisets are good replacement for priority queues 
priority queues stores multiple items in sorted order only

*/

#include <iostream>
#include <set>
using namespace std;

void print_mst(multiset<string> &mst)
{
    cout << "-------------\n";
    for (auto item : mst)
    {
        cout << item << endl;
    }
}
int main()
{
    multiset<string> mst;

    int n;
    cout << "enter n : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mst.insert(s);
    }

    print_mst(mst);

    auto it = mst.find("anand");

    // returns first index of found item
    if (it != mst.end())
    {
        cout << "yes found" << endl;
        // mst.erase(it); //will delete only one anand to the first one only
        mst.erase("anand"); //will delete all "anand"
    }
    else
    {
        cout << "doesn't exist!!" << endl;
    }

    print_mst(mst);

    return 0;
}