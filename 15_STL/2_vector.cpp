/* vector */

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
void change(vector<int> &v);

int main()
{
    vector<int> v1(5);
    printVector(v1); //five 0
    v1.push_back(3);
    printVector(v1); //five 0 and @ last 3 (that means appended at the last)

    vector<int> v2(4, -1);
    printVector(v2); // -1 four times

    vector<int> v3;
    cout << v3.size() << " ";  //0
    v3.push_back(1);           //O(1) time
    cout << v3.size() << endl; //1 and so on

    v1.pop_back(); //O(1) time
    v1.pop_back();
    printVector(v1);

    v3 = v2; //direct copying unlike arrays and takes O(N) time
    printVector(v2);
    v2.push_back(4); //see only the copy is created
    printVector(v3); //no change in v3 is reflected
    printVector(v2);

    change(v2);
    printVector(v2);

    vector<int> &v11 = v1; //now v11 is sames as v1 with just different name

    return 0;
}


void change(vector<int> &v)
{
    v.push_back(100);
    v.push_back(200);

    return;
}

// note while passing vector as input
// they are passed as simple args

// so a copy is created for them which leads to
// expensive operation O(N) and no changes are reflected back in case of this (unlike array)

// so it's always recommended to pass vector as reference &

// we cannot copy array one to two directly by assigning a1 = a2 

// this can only be done if they are of same size and not the copying happens

// rather a1's pointer point to a2 array's pointer