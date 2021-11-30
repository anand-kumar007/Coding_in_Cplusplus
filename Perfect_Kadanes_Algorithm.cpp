 int maxSubArray(vector<int>& nums) {
        
        int ans = INT_MIN;
        int a = 0;
        
        for(int item : nums)
        {
            a += item;
            ans = max(ans,a);
            a = max(a,0);
        }
        
        return ans;
    }



/*
main idea of kadane's algorithm is

if at any point of time your sum = -ve then leave that as it doesn't contribute to largest sum

-2,1,-4,3,2,14,-2

a = -2, ans = -2

But a = 0 and ans = -2 for now 

when next iteration starts 
a = 0 + 1 --> 1
ans = max(1,-2) --> 1

so on


This is applicable to array's where all the numbers are negative as well

Complexity -> O(N)
*/
