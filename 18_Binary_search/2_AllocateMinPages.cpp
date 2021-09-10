
/* 
Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum. 

how to check if a mid value is feasible or not? Basically, we need to check if we can assign pages to all students in a way that the maximum number doesn’t exceed current value. To do this, we sequentially assign pages to every student while the current number of assigned pages doesn’t exceed the value. In this process, if the number of students becomes more than m, then the solution is not feasible. Else feasible.


*/
#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[], int total_books, int total_students, int minPages)
{
    int sum = 0;             //shows to current student how many pages we are giving(their total)
    int studentRequired = 1; //to allocate minPage(which are maxm)

    for (int i = 0; i < total_books; i++)
    {
        if (arr[i] > minPages)
            return false;

        if ((arr[i] + sum) <= minPages)
        {
            sum += arr[i];
            //keep allocating to single student
        }
        else
        {
            //if arr[i]+sum > minPages // we need more student and sum's value will change
            //bcz sum shows sumofPages for the current student

            studentRequired++;
            sum = arr[i];

            if (studentRequired > total_students)
                return false;
        }
    }

    //means the given minpossibleMaxmPages is feasible
    return true;
}

//allocate n books to m students
int minPossibleMaxmPages(int arr[], int n, int m)
{
    if (n < m)
        return -1;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int ans = INT_MAX; //since we want it's minimum value
    int start = 0, end = sum;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; //this is necessary here
        if (isPossible(arr, n, m, mid))
        {
            //if so try to get more minimum value of pages(which are maxm)
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return ans;
}
int main()
{
    // int arr[] = {2,4,8,10}; //in asc order always
    int arr[] = {12, 34, 67, 90};
    int total_books = sizeof(arr) / sizeof(arr[0]);
    int total_students = 2;

    int ans = minPossibleMaxmPages(arr, total_books, total_students);

    cout << ans << endl;
    return 0;
}

/*
{2,4,8,10} total_student = 3

(a) 2 | 4 | {8,10}
(b) {2,4} | 8 | 10
(c) 2 | {4,8} | 10


maxm pages allocated to single student
(a) 18
(b) 10
(c) 12

the minimum of these ==> 10 ans;

*/