#include<bits/stdc++.h>
using namespace std;
class Host {
   public :
   class Nested{
       Host h;
       public :
       Nested()
       {
           h.a = 14;
       }
       void print()
       {
          cout<<h.a<<endl;
       }
   };
};

int main()
{
    Host::Nested bar;
    bar.print();

    return 0;
}

/*
This program throws an error because first the definition of class Host(Outer One)
needs to be completed and then we can define its object as the member of some other 
classes.

error: field 'h' has incomplete type 'Host'
            Host h;
*/
