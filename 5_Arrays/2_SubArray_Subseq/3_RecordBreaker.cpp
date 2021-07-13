//find the count of record breaking days 
//and print each record breaking day from the array
#include<iostream>
using namespace std;

void FindRecordBreakingDay(int arr[], int n);

int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];

    FindRecordBreakingDay(arr,n);
    return 0;
}

void FindRecordBreakingDay(int arr[], int n)
{
    int counter=0;
    bool flagP = true;
    bool flagF = true;

    for(int i=0; i<n; i++)
    {
        int key = arr[i];

        //check for the previous values
        int j=i-1;
        while(j>=0)
        {
            if(key < arr[j])
            {
                flagP = false;
                break;
            }
           
            j--;
        }
        //or just continue to next itration if FlagP = false 
        // here reset required vaiables

        //check for the following values
        j=i+1;
        while(j<n)
        {
            if(key < arr[j])
            {
               
            flagF = false;
            break;
            }

            j++;
        }

        if(flagP && flagF)
        {
            cout<<arr[i]<<" ";
            counter++;
        }
        flagP = true;
        flagF = true;
    }

    cout<<"Total count is : "<<counter;
}


//this is stupid approach and hence it is actually finding the maximum element of the array
