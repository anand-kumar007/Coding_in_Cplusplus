#include<iostream>
using namespace std;

class Student {
    int age;
    public :

    //constructor initializes the age to 12
    Student() : age(12) {}

    void getAge() {cout<<"Age : "<<age<<endl;}
};


int main()
{
  //dynamically declare Student Object
  Student *st1 = new Student();

  //call getAge() function
  st1->getAge();

  //free the memory
  delete st1;

  return 0;  
}