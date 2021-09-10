
/* an array of vector can be seen as 2D array with fixed rows and
   dynamic column size for each row 

   and if both rows and columns are to be made dynamic
   vector of vector is being used 

*/

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    cout << "size : " << v.size() << endl;
    for (auto i : v)
        cout << i << " ";

    cout << endl;
}

int main()
{
    int N;
    cout << "How many rows : ";
    cin >> N;

    vector<vector<int>> v; //an array of vectors

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        // vector<int> temp;
        v.push_back(vector<int>());

        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            // temp.push_back(x);
            v[i].push_back(x);
        }

        //since v is a vector of vectors
        // v.push_back(temp);
    }

    //here we can determine the size of vector just by using
    //push back and pop backmethods

    cout << "Nested vector size : " << v.size() << endl;

    for (int i = 0; i < v.size(); i++)
        printVector(v[i]);

    return 0;
}
