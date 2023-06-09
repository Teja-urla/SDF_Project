#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> vec, int n){
    int dp[n + 1];
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        dp[i] = 0;
        for(int j = 0; j < i; j++)
        {
            if(vec[j] < vec[i])
            dp[i] = max(dp[j], dp[i]);
        }
        dp[i]++;
    }
    return *max_element(dp, dp + n);
}

int main(){
    vector<int> vec{10,9,2,5,3,7,101,18};
    int n = vec.size();
    int x = fun(vec, n);
    cout<<x<<endl;
}