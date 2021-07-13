#include<iostream>
using namespace std;

int main()
{
    
    string str1 = "geeksforgeeks is for geeks";
    string str2 = "geeksforgeeks rocks";
    // Declaring character array
    char ch[80];
    
    // using copy() to copy elements into char array
    // copies "geeksforgeeks"
    str1.copy(ch, 13, 0);

    ch[13]='\0';
    // using swap() to swap string content
    str1.swap(str2);

    int i=0;
    while(ch[i] !='\0')
    
    { cout<<ch[i]<<" ";
      i++;
    }
    cout<<endl;

    cout << str1 << endl; //geeksforgeeks rocks
    cout<<str2<<endl; //geeksforgeeks is for geeks



    return 0;
}


// copy("char array",length_to_be_copied,startposition)
// str1.copy(str2)