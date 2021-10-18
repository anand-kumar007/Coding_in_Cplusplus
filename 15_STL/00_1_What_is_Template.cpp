#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// function template
template <class T>
T Large(T n1, T n2)
{
    return (n1 > n2) ? n1 : n2;
}

// class template
template <typename T>
class Calculator
{
    T a;
    T b;

public:
    Calculator()
    {
        a = 0;
        b = 0;
    }
    Calculator(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    T add()
    {
        return a + b;
    }
    void display();
};

template <typename T>
void Calculator<T>::display()
{
    cout << "a = " << a << " b = " << b << endl;
}


//insertion sort function template
template<typename haha>
void InsertionSort(haha arr[], int n)
{
    for(int i=1; i<n;i++)
    {
        int j=i-1;
        haha key = arr[i];

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    return ;
}

int main()
{
    int a = 10, b = 23;
    float x = 3.43, y = 34.44;

    cout << Large(a, b) << endl;
    cout << Large(x, y) << endl;

    //like we use the vector template class form
    //standard library
    Calculator<float> obj1(103.23, 232.34);
    Calculator<int> obj2(10, 20);

    obj1.display();
    obj2.display();


    //the insertion sort one
    int arr1[5] = {12, 3, -23, 10, 200};
    float arr2[5] = {123.2, -3.34, -23.323, 10.23, 20.02};

    InsertionSort(arr1, 5);
    InsertionSort(arr2, 5);

    for(auto item : arr1)
        cout<<item<<" ";

    cout<<"\n--------------\n";
    for (float item : arr2)
        cout <<setprecision(5)<< item << " ";

    return 0;
}
