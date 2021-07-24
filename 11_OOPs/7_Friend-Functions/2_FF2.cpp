/*
given boss and employee make a friend function to 
tell the salary of both the boss and employee

need to declare it in both the classes

*/
#include <iostream>
using namespace std;

class Employee; //gotta use in boss class

class Boss
{
private:
    int salary;
    friend void totalSalary(Boss, Employee);

public:
    Boss(int x = 0)
    {
        salary = x;
    }
};

class Employee
{
    int salary;
    friend void totalSalary(Boss, Employee);

public:
    Employee(int y = 0)
    {
        salary = y;
    }
};

//the friend function
void totalSalary(Boss b, Employee e)
{
    cout << "Boss salary + Employee salary : " << b.salary + e.salary << endl;
}

int main()
{
    Boss B(200);
    Employee E(100);

    totalSalary(B, E);
    return 0;
}