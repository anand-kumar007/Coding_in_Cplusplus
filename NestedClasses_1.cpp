#include<bits/stdc++.h>
using namespace std;
class Host {
   public :
   class Nested{
       public :
       void print()
       {
           cout<<"Hey there, how are you!"<<endl;
       }
   };
};

int main()
{
    Host::Nested bar;
    bar.print();

    return 0;
}
