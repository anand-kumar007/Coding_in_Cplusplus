// String Stream
#include <bits/stdc++.h>
using namespace std;

void printFrequency(string st);
int main()
{
    string s = "Anand is good. Anand is fine. Anand loves travelling.";
    printFrequency(s);
    return 0;
}

void printFrequency(string st)
{
    map<string,int> FW; //to store frequency of each work
    stringstream s(st); 
    string word;
    int count;

    while(s >> word)
        FW[word]++;

    cout<<"total distinct words are : "<<FW.size()<<endl;

    for(auto val : FW)
    {
        cout<<val.first << " --> "<<val.second<<endl;
    }    

    return ;
}