#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s1 ="nincompoop";

    //substr(starting_index,how_many_characters)
    string s2 = s1.substr(3,5);
    //compo
    cout<<s2<<endl;

    // convert string to integers using stoi("str")
    string s3 = "786";
    cout<<stoi(s3)+2<<endl;
    //788 is the output

    //convert integer to string using to_string
    int x=788;
    cout<<to_string(x) + "2"<<endl;
    //7883 is the answer

    // sorting the string using sort()
    // this need algorithm header file
    string s4 = "alfjalkdfhn";
    sort(s4.begin(),s4.end());
    cout<<s4<<endl;
    // aadffhjklln is output    

    return 0;
}