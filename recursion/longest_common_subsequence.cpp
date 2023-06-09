#include<bits/stdc++.h>
using namespace std;

int fun(string str1, string str2){
    int m = str1.length(), n = str2.length();
    int dp[m + 1][n + 1];
    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(str1[i - 1] == str2[j - 1]){
                cout<<"x"<<endl;
            dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                cout<<"y"<<endl;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    int x = fun("aacabdkacaa","aacakdbacaa");
    cout<<x<<endl;
}