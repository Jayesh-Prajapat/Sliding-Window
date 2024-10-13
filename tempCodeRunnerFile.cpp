#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(vector<long long> &A, long long int N, long long int k)
{
    vector<long long> ans;
    queue<long long> q;

    // Process the first window of size k
    for (long long i = 0; i < k - 1; i++)
    {
        if (A[i] < 0)
        {
            q.push(A[i]);
        }
    }

    // Process the rest of the windows
    for (long long i = k - 1; i < N; i++)
    {
        if (A[i] < 0)
        {
            q.push(A[i]);
        }

        // Push the first negative element of the current window
        if (!q.empty())
        {
            ans.push_back(q.front());

            // Remove the element from the queue if it is no longer in the window
            if (q.front() == A[i - k + 1])
            {
                q.pop();
            }
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    // Example 1
    vector<long long> arr1 = {-8, 2, 3, -6, 10};
    long long int N1 = 5;
    long long int K1 = 2;
    vector<long long> result1 = printFirstNegativeInteger(arr1, N1, K1);
    for (long long num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<long long> arr2 = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N2 = 8;
    long long int K2 = 3;
    vector<long long> result2 = printFirstNegativeInteger(arr2, N2, K2);
    for (long long num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
