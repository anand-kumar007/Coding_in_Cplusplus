
/* nesting of maps and sets */

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void print_map(map<pair<string, string>, vector<int>> &m)
{
    for (auto &value : m)
    {
        cout << value.first.first << " " << value.first.second << endl;
        for (int i = 0; i < value.second.size(); i++)
        {
            cout << value.second[i] << " ";
        }
        cout << endl;
    }
}

//store the firstname,lastname,and marks in various subjects
//number of subjects may vary for each student
int main()
{

    map<pair<string, string>, vector<int>> m;

    int n;
    cout << "enter total student : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int sub_count;
        cout << "fn and ln and total subjects of student " << i + 1 << " : ";
        cin >> fn >> ln >> sub_count;

        cout << "enter marks in " << sub_count << " subjects : ";
        for (int j = 0; j < sub_count; j++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }

    cout << "------------------------\n";
    print_map(m);

    return 0;
}

/*

    map<pair<int, int>, int> m1;
    map<set<int>, int> m2;

    pair<int,int> p1,p2;
    p1 = {1, 2};
    p2 = {10, 1};

    cout<< (p1<p2)<<endl; //true since p1.first <p2.first
    //if first item is same then comparison happens for second 
    // return (p1.first<p2.first || p1.second <p2.second)

    set<int> s1,s2;
    s1 = {1,2,3,4};
    s2 = {10,-1};

    cout<< (s1<s2) <<endl;
    //if all elements satisfy this then true else false

    //and same for vectors also comparison can be done
    //so red-black tree implementation of sets,pair,vector can be done
    //easily and hence in maps they can be used directly !!


*/


/*
remember not to create unnecessary copies as much as possible 

pair as keys in maps is widely used 

map stores in sorted order
*/