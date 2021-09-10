/* sets 
1. ordered sets
2. unordered sets
3. multisets 

they are mostly like maps only
except they don't have value things

internal implementation and various complexity
for accessing and inseting are same as that of maps
log(n)

Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it. The value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element. 


*/

#include <iostream>
#include <set>
using namespace std;

void print_set(set<string> &st)
{
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << endl;
    }

    // for(auto item : st)
    // {
    //     cout<<item<<endl;
    // }
}
int main()
{
    set<string> s;

    //insertion(in random order)
    s.insert("anand");
    s.insert("anand"); //log(n)
    s.insert("sam");
    s.insert("Radha");
    s.insert("Sohan");

    print_set(s);
    cout << "-------------" << endl;
    //accessing

    // auto it = s.find("anan");
    auto it = s.find("anand"); //log(n)
    if (it != s.end())
    {
        // cout<< *it <<endl;
        // s.erase(it);
        s.erase("anand");

        print_set(s);
    }
    else
    {
        cout << "doesn't exists !!" << endl;
    }

    return 0;
}