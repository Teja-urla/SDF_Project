#include<bits/stdc++.h>
using namespace std;

// int fun(vector<int> vec, int n){
//     int dp[n + 1];
//     dp[0] = 1;
//     for(int i = 0; i < n; i++)
//     {
//         dp[i] = 0;
//         for(int j = 0; j < i; j++)
//         {
//             if(vec[j] < vec[i])
//             dp[i] = max(dp[j], dp[i]);
//         }
//         dp[i] += vec[i];
//     }
//     return *max_element(dp, dp + n);
// }

int bestTeamScore(vector<int>& scores, vector<int>& age) {
        vector<pair<int, int>> players;
        int n = age.size();
        for(int i = 0; i < n; i++) 
            players.push_back({age[i], scores[i]});
            sort(players.begin(), players.end());

 // problem from here is just longest increasing subsequence
        int dp[n];
        for(int i = 0; i < n; i++){
             dp[i] = 0;
            for(int j = 0; j < i; j++){
                if(players[i].second >= players[j].second)
                dp[i] = max(dp[j], dp[i]);
            }
            dp[i] += players[i].second;
        }
        return *max_element(dp, dp + n);
}

int main(){

    vector<int> scores{4,5,6,5};
    vector<int> ages{2, 1, 2, 1};
    int x = bestTeamScore(scores, ages);
    cout<<x<<endl;

    // int n = vec.size();
    // int x = fun(vec, n);
    // cout<<x<<endl;
}