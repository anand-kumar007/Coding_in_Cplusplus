/*
you are given a string find the maxm frequency element 
print its frequency and the element alongside it.
*/

#include<iostream>
#include<algorithm>
using namespace std;
void findMaxFrequency(string s);

int main()
{
    string s;
    cout<<"enter a string with repeated characters in it : ";
    // cin.getline(s, total length); 
    // bcz needed total length as third arg so not preferred

    getline(cin,s);
    findMaxFrequency(s);
    return 0;
}

void findMaxFrequency(string s)
{
    int freq[26];
    for(int i=0; i<26; i++) {
      freq[i] = 0;
    }

    for(int i=0; i<s.length(); i++)
    {
        // freq[s[i] - 97]++; both are same
        freq[s[i] - 'a']++;
    }

    //find the maxium value in freq array
    int maxfreq=0;
    char ans = 'a'; //let

    for(int i=0; i<26; i++)
    {
        if(maxfreq < freq[i])
        {
            maxfreq = freq[i];
            ans = i + 'a';
        }
    }

    cout << "maximum freq is : " << maxfreq << endl;
    cout << "maximum freq element is : " << ans << endl;

    return ;
}