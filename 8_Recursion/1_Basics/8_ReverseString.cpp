/*
"binod" --> "donib"
*/
#include <iostream>
#include<string>
using namespace std;
void Reverse(string str)
{
    if(str.size()==0)
    return ;
    cout<<str[str.size()-1];
    str.pop_back();
    Reverse(str);
}
void reverse(string s)
{
    if(s.length()==0)
    return ;
    string ros = s.substr(1);
    //from index 1 to last take in ros
    reverse(ros);
    cout<<s[0];
}
int main()
{
    string str ="binod";
    Reverse(str);
    return 0;
}

/*
This function takes two values pos and len as an argument and returns a newly constructed string object with its value initialized to a copy of a sub-string of this object. Copying of string start from pos and done till pos+len means [pos, pos+len).

Important points:

The index of the first character is 0 (not 1).
If pos is equal to the string length, the function returns an empty string.
If pos is greater than the string length, it throws out_of_range. If this happen, there are no changes in the string.
If for the requested sub-string len is greater than size of string, then returned sub-string is [pos, size()).

*/