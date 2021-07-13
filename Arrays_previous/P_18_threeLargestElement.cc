//find the three largest element from the array 
//in O(n) time complexity and O(1) space complexity

#include<iostream>
using namespace std;
void findThree(int arr[],int);

int main()
{
    int n;
    cout<<"size : ";
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    cout<<"three largest numbers are : ";
    findThree(arr,n);
}

void findThree(int arr[], int n)
{
    if(n<3)
    {
        cout<<"Invalid size of array";
        return ;
    }

    int first,second,three;
    first = second = three = INT32_MIN;

    for(int i=0; i<n; i++)
    {
        if(arr[i]>first)
        {
            three = second;
            second = first;
            first = arr[i];
            
        }
        else if(arr[i]>second)
        {
            three = second;
            second = arr[i];
        }

        else if(arr[i]>three)
        {
            three = arr[i];
        }
    }

    cout << "first : " << first << endl;
    cout << "second : " << second << endl;
    cout << "third : " << three << endl;
}