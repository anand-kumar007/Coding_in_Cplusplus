
/*
Problem
Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

Output format:
You must print the required list.

Constraints:
1 <= N <= 105
1 <= | Length of the name | <= 100
1 <= Marks <= 100

Sample Input
3
Eve 78
Bob 99
Alice 78
Sample Output
Bob 99
Alice 78
Eve 78
Time Limit: 2
Memory Limit: 256

*/

#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

void print_map(map<int, multiset<string>> &marks_map);

int main()
{
    //marks and name list corresponding
    //we want in descending order of marks and if marks are same
    //decide on alphabetical order of names
    //map stores in asc order but we can print in reverse order or apply
    //some little trick of storing the negative marks and while printing just
    //multiply with the -1*marks

    //since two marks and names can be same so multiset
    map<int, multiset<string>> marks_map;

    int n;
    cout << "enter total students : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "name and marks for student " << i + 1 << " : ";
        int marks;
        string name;
        cin >> name >> marks;

        // marks_map[marks].insert(name);

        //for storing negative marks
        marks_map[-1 * marks].insert(name);
    }

    // print_map(marks_map); //reverse printing

    cout << "---------------------" << endl;

    //using negative marks to store
    for (auto students_mark_pair : marks_map)
    {
        int marks = students_mark_pair.first;
        auto students = students_mark_pair.second;

        for (auto student : students)
        {
            cout << student << " " << (-1 * marks) << endl;
        }
    }
    return 0;
}

void print_map(map<int, multiset<string>> &marks_map)
{
    auto it = marks_map.end();
    --it;
    cout << "---------------------" << endl;
    while (true)
    {
        auto &students = (*it).second;
        int marks = (*it).first;
        //list of names
        for (auto student : students)
        { //marks
            cout << student << " " << marks << endl;
        }

        if (it == marks_map.begin())
            break;

        it--;
    }
}