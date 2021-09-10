
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
    cin >> N;
    vector<int> v[N]; //an array of vectors

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for (int i = 0; i < N; i++)
        printVector(v[i]);

    return 0;
}
