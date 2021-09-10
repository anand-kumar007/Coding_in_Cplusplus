
/* 
sub array of size k palindromic concatenation 
check if there exists a subarray of size k
such that concatenation of numbers forms a palindrome

madam,nitin,racecar,797,12233221 etc
approach1 : generate all subarray
O(N^2) time complexity 
for checking palindrome O(n)
==> total complexity ==> O(n^3)

approach2 : sliding window approach
O(N^2) time

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool isPalindrome(int num)
{
    int temp = num, number = 0;

    while (temp > 0)
    {
        number = number * 10 + temp % 10;
        temp = temp / 10;
    }

    if (num == number)
        return true;

    return false;
}

int findPalindromicSubarray(vector<int> arr, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
        num = num * 10 + arr[i];

    if (isPalindrome(num))
        return 0;

    for (int i = k; i < arr.size(); i++)
    {
        num = (num % (int)pow(10, k - 1)); // if k=4 and num = 1234 then will give 234
        num = num * 10 + arr[i];           //simply removing the first digit

        if (isPalindrome(num))
            return (i - k + 1);
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};

    int k = 4;
    int start = findPalindromicSubarray(arr, k);

    if (start != -1)
    {
        for (int i = start; i < (start + k); i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
        cout << "subarry doesn't exists!" << endl;

   

    return 0;
}