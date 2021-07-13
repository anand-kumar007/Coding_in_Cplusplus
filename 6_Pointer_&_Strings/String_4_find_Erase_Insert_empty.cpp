#include<iostream>
using namespace std;

int main()
{
    //compare function
    string s1 = "abc";
    string s2 = "aaa";

    if(s2.compare(s1) == 0)
     cout<<"string are equal";

     else if(s2.compare(s1) > 0)
      cout<<s2<<" string is greater lexicographically";

      else 
      cout<<s1<<" string is greater lexicographically";
      cout<<endl;

      s1.clear();  //empty the string
      if(s1.empty())
      cout<<"empty string s1";

        cout<<endl;
       //Erasing 
       string s3 = "nincompoop";
       s3.erase(3,4);
       //erase(string index, how many character to delete)
       cout<<s3<<endl;
       // ninoop  is the output

        //find("string to search") will return first index found 
       s3 = "nincompoop";
       cout<<s3.find("com")<<endl; 
       // 3 is the output

       //insert(index, "string to insert")
       s3.insert(2,"HAHA");
       cout<<s3<<endl;

       //get the size of strings
       s3 = "nincompoop"; //10 size
       cout << "size is : " << s3.size() << endl;
       cout << "size is : " << s3.length() << endl;

       //using length and size we can iterate through the strrings
       for(int i=0; i<s3.length(); i++) {
       cout<<s3[i]<<' ';
       }

       
       return 0;
}