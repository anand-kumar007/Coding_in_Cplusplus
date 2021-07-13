/*
Check if a key is present in every segment of size k in an array.
=================================================================
Given an array arr[] and size of array is n and one another key x, 
and give you a segment size k. The task is to find that the key x 
present in every segment of size k in arr[].

=================================================================
*/
#include<iostream>
using namespace std;

bool checkPresence(int arr[],int n, int segmentSize, int key);

int main()
{
    int n;
    cout<<"enter size : "; cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" array elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>*(arr+i);
    }
    int x; //key
    int s; //segmentSize
    cout<<"enter the key ";
    cin >> x;
    cout << "enter the segmentSize ";
    cin >> s;
    cout<<"array is :";
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";

    cout<<endl<<"============"<<endl;
    if(checkPresence(arr,n,s,x))
    {
        cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;

    return 0;
}

//function definition
bool checkPresence(int arr[], int n, int segmentSize, int key)
{
   int i=0;
   for(i=0; i<n; i += segmentSize)
   {
       //search key in segment starting from index i.
       int j;
       for(j=0;j<segmentSize;j++)
       {
           if(arr[i+j]==key)
           {
               break;
           }
       }

       //if loop doesn't break means No match
       if(j==segmentSize)
       return false;
   }

   //if n is multiple of segmentSize
   if(i==n)
   return true;


   //check the last segment if n is not multiple of k

   int j;
   for(j=i-segmentSize; j<n; j++)
   {
       if(arr[j]== key)
       break;
   }
  //again if loop doesn't break;
   if(j==n)
    return false;


    return true;

}

//     if(i+segmentSize<n)
//  {
//     for(int j=i; j<i+segmentSize;j++)
//     {
//         if(arr[j]==key)
//         {
//             flag = true;
//             break;
//         }

//     }

//   if(!flag) return false;
//  }
//  else
//  {
//      for(int j=i; j<n-(i+segmentSize); j++)
//      {
//          if(arr[j]==key)
//          {
//              flag = true;
//              break;
//          }

//      }
//      if(!flag) return false;
//  }
// }

// return true;