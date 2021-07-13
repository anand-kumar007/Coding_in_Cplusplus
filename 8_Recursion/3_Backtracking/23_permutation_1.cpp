
#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>> ans;
void permute(vector<int> a, int idx)
{
    if(idx == a.size())
    {
        ans.push_back(a);
        return ;
    }

    for(int i=idx; i<a.size(); i++)
    {
        swap(a[idx],a[i]);
        permute(a,idx+1);
        swap(a[idx],a[i]);

    }
}
int main()
{
    int n;
    cin>>n;

    vector<int> a(n);
    cout<<"enter the elements : ";
    for(auto &i : a)
        cin>>i;
    
    //calculate permutation
    permute(a,0);

    //print the ans
    for(auto v : ans)
    {
        for(auto i : v)
        {
            cout<<i<<" ";
        }cout<<endl;
    }
    return 0;
}