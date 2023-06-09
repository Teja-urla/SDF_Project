#include<bits/stdc++.h>
using namespace std;

string FCS(string str1, string str2, int m, int n){
    // string final;
    if(m == 1)return str1;
    string dp[m + 1][n + 1];

    for(int i = 0; i < m + 1; i++)
    {
       for(int j = 0; j < n + 1; j++)
       {
            if(i == 0 || j == 0)
            {
                dp[i][j] = "";
            }
        }
    }
   
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
        if(str1[i - 1] == str2[j - 1])    {
            dp[i][j] = str1[i - 1] + dp[i - 1][j - 1];
           }
            else{
                string s1 = dp[i-1][j];
                string s2 = dp[i][j-1];
                    if(s1.length() > s2.length())
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
            }
        }
    }
    return dp[m][n];
}

    string longestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string str = FCS(s, t, s.length(), t.length());
        return str;
    }

int main()
{
    
}    