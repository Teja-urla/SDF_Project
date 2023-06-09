#include<bits/stdc++.h>
using namespace std;

    string longestPalindrome(string str) {
    int n = str.length();
    bool dp[n][n];
    int count = 0;
    int i, j, gap = 0;
    int max_count = INT_MIN;
    int start, end;
    while(gap < n)
    {
       int i = 0;
       j = gap + i;
       int cnt = n - gap;
       while(cnt != 0)
       {
            if(i == j)
            {
               dp[i][j] = true;
                if(max_count < j - i)
                    {
                        start = i;end = j;
                        max_count = j - i;
                    }
            }

            else if(j - i == 1){ // 01; 12; etc
                if(str[i] == str[j]){
                    dp[i][j] = true;
                    if(max_count < j - i)
                    {
                        start = i;end = j;
                        max_count = j - i;
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }

            else{
                if(str[i] == str[j] and dp[i + 1][j - 1] == true){
                    dp[i][j] = true;
                    if(max_count < j - i)
                    {
                        start = i;end = j;
                        max_count = j - i;
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }
            cnt--; 
            j++;
            i++;         
       }
       gap++;
    }
    string finstr;
    for(int i = start; i <= end; i++)
    {
        finstr += str[i];
    }
    return finstr;          
    }

int main()
{
    string x = longestPalindrome("a");
    cout<<x<<endl;   
}    