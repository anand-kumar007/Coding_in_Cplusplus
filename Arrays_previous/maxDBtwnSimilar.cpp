#include<iostream>
using namespace std;
int MaxmDistanceBetweenSimilarElement(int a[] , int);


int main()
{
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int distance = MaxmDistanceBetweenSimilarElement(arr,n);
    cout<<"max_distance is : "<<distance<<endl;

    return 0;
}


int MaxmDistanceBetweenSimilarElement(int arr[], int n)
{
    int i, j, k = 0, m;
    // k keeps track of the largest difference
    // m focuses on the current difference for each element
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                m = j - i; //difference is index(j) - index(i)
            }
            if (k < m)
                k = m;
        }
    }
    return k;
}