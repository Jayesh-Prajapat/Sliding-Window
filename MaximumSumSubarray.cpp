#include <bits/stdc++.h>
using namespace std;

// Max Sum Subarray of size K with allow duplicate element
long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    // code here
    long sum = 0;
    long maxi = INT_MIN;
    for (int i = 0; i < K; i++)
    {
        sum += Arr[i];
    }
    maxi = sum;
    for (int i = K; i < N; i++)
    {
        sum += Arr[i] - Arr[i - K];
        maxi = max(maxi, sum);
    }
    return maxi;
}

//  Maximum Sum of Distinct Subarrays With Length K
long long maximumSubarraySum(vector<int> &nums, int k)
{
    long ans = 0, sum = 0;             // initialize the maximum sum (ans) and current sum(sum)
    unordered_map<int, int> mp;        // Map to count the frequency of elements in the current window
    int i = 0, j = 0, n = nums.size(); // Initialize the window pointers (i,j) ans size of nums array (n)

    // iterate through the array with the end pointer 'j'
    while (j < n)
    {
        sum += nums[j];  // add the element to the sum
        mp[nums[j++]]++; // Increment the frequency count of the current element and move 'j' forward

        // cheak if the current window size is equal to 'k'
        if (j - i == k)
        {
            // if all elements in the window are unique (size of map equal), update the window sum
            if (mp.size() == k)
            {
                ans = max(ans, sum);
            }
            // slide the window: decreament the frequency of the element at the start of the window
            mp[nums[i]]--;
            // subtract the element at the start of the window from the sum
            sum -= nums[i];
            // if the frequency of the element becomes 0, remove it from the map
            if (mp[nums[i]] == 0)
            {
                mp.erase(nums[i]);
            }
            // Move the start pointer 'i' forward
            i++;
        }
    }
    // Return the maximum sum forward
    return ans;
}

int main()
{
    vector<int> Arr = {1, 5, 4, 2, 9};
    cout << "RESULT : " << maximumSumSubarray(3, Arr, Arr.size())<<endl;
    cout << "RESULT : " << maximumSubarraySum(Arr, 3);
}