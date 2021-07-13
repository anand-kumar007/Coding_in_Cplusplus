/*
print the length of maxm sized word in the sentenence

Hi all this is anand here.
>>5
Do or Die
>>3

*/

#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //clear the buffer bcz using the cin.getline()
    //either cin.ignore() or fflush()

    char arr[n+1];
    cout<<"enter the sentence : ";
    cin.getline(arr,n);
    cin.ignore();

    int ans=0;
    int curr=0;
    int i=0;

    //st is like curr and maxst is like ans here 
    //maxst tells where is the starting of maxword
    int st=0,maxst=0;

    while(1)
    {
       
        if(arr[i] == ' ' || arr[i] == '\0')
        {
            if(curr > ans)
            {
                ans = curr;
                maxst = st;
            }

            curr = 0;
            st = i+1;
        }

        else 
        {
            if(arr[i] =='\0')
            break;
        }
       
       //simply keep increasing
       curr++; 
       i++;    
    }

    cout<<"maxm word length is : "<<ans;

    for(int i=0; i<ans; i++)
    {
        cout<<arr[i+maxst];
    }

    return 0;

}

/*
"x" = const char *
'x' = char

Double quotes are the shortcut syntax for a c-string in C++. If you want to compare a single character, you must use single quotes instead. You can simply change your code to this:

char userInput_Text[3];

if (userInput_Text[1] == 'y') { // <-- Single quotes here.
    // Do stuff.
}
*/