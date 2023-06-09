#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    int mini = INT_MAX;
    if(dp[i][j] != -1)return dp[i][j];
    for(int k = i; k < j; k++)
    {
       mini = min(mini, arr[i - 1]*arr[k]*arr[j] + fun(arr, i, k, dp) + fun(arr, k + 1, j, dp));
    }
    dp[i][j] = mini;
    return dp[i][j];
}

int main()
{
    vector<int> arr{ 1, 2, 3};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            dp[i][j] = 0;
        }
    }
    int x =fun(arr, 1, n - 1, dp);
    cout<<x<<endl;
}