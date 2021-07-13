/*
program to check if the string is palindrome
or not using recursion

*/

#include <iostream>
using namespace std;
bool isPalindrome(string s, int st, int end)
{
    if(st >= end)
    return true;
    if(s[st] != s[end])
    return false;

    return isPalindrome(s,st+1,end-1);
}

/* just the two pointer algorithm */

int main()
{
    string s = "RACECAR";
    int n = s.size();

    if(isPalindrome(s,0,n-1))
        cout<<"Yes";
    else  
        cout<<"No";    
    
    return 0;
}

/*
since crossing each character only once
so time complexity is O(N)
*/