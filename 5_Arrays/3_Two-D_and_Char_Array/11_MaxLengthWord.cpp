/*
enter the length of sentence : 10
Enter the word : Do Or Die
ans is : 3

*/

#include <climits>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter the length of sentence : ";
    cin >> n;

    fflush(stdin);
    cout << "Enter the word : ";
    char ch[n + 1];
    cin.getline(ch, n);
    fflush(stdin);

    //apply the logic
    int i = 0, curr = 0, ans = INT_MIN;

    

    while (1)
    {
        if (ch[i] == ' ' || ch[i] == '\0')
        {
            if(curr > ans)
            {
              ans = curr;
              curr = 0;
              
            }

            if (ch[i] == '\0')
            {
                break;
            }
        }
        else
        {
            curr++;
        }
        i++;
    }

    cout << "ans is : " << ans << endl;
    cout<<endl;
    return 1;
}
