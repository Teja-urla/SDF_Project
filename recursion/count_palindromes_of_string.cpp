#include<bits/stdc++.h>
using namespace std;

int count_all_palindromes(string str){
    int n = str.length();
    bool dp[n][n];
    int count = 0;
    int i, j, gap = 0;
    while(gap < n)
    {
       int i = 0;
       j = gap + i;
       int cnt = n - gap;
       while(cnt != 0)
       {
            if(i == j)dp[i][j] = true;

            else if(j - i == 1){ // 01; 12; etc
                if(str[i] == str[j]){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }

            else{
                if(str[i] == str[j] and dp[i + 1][j - 1] == true){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
            if(dp[i][j] == true) count++; 
            cnt--; 
            j++;
            i++;         
       }
       gap++;
    }
    return count;
}

int main()
{
    int x = count_all_palindromes("a");
    cout<<x<<endl;
}    

/* 

*/