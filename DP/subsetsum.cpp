#include<bits/stdc++.h>
using namespace std;
// int dp[][];
// bool trap(vector<int>& arr, int sum, int n, int **dp) {
//    if(n == 0 && sum != 0)return false;
//    if(sum == 0) return true;
//    if(arr[n - 1] <= sum){
//       return trap(arr, sum - arr[n-1], n-1, dp) || trap(arr, sum, n-1, dp);
//    }
//    else{
//       return trap(arr, sum, n-1, dp);
//    }
// }

int main()
{
    vector<int> vec{1, 5, 3, 7, 4};
    int n = vec.size();
    int sum = 15;
    int dp[n + 1][sum + 1];
    for(int i = 0; i < n + 1; i++){
      for(int j = 0; j < sum + 1; j++){
         if(j == 0)dp[i][j] = true;
         else if(j != 0 and i == 0) dp[i][j] = false;
      }
    }

    for(int i = 1; i < n + 1; i++){
      for(int j = 1; j < sum + 1; j++){
         if(vec[i - 1] < j){
            dp[i][j] = dp[i - 1][j - vec[i]] || dp[i - 1][j];
         }
         else{
            dp[i][j] = dp[i - 1][j];
         }
      }
    } 
       
    if(dp[n][sum])
    {
       cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
}
