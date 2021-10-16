// polymorphism

#include<iostream>
using namespace std;

class One
{
    public :
    virtual int fun(int x,int y)
    
    {
        return (x++ + ++y + x<<2);
    }
};

class Two : public One
{
    public :
    int fun(int x,int y)
    {
        return (++x + y++ + x>>2);
    }
};
int main()
{
    One obj = Two();
    
    cout<<obj.fun(2,3)<<endl;
    
}

// here first ++ will be executed then + and then >>
//since no overriding takes place here simply we are doing default copying
// for overriding we'should have used the pointer of base and assigned it to derived
// One *obj = new Two(); then this would have called 
// derived class's fun but here One's fun would be called

// ie (2+4+3)>>2 ==> 36
