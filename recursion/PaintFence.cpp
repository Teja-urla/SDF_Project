#include <bits/stdc++.h>
using namespace std;

int fun(int n, int k)
{
    if(n == 1 || n == 0) return 0;
    int dp1[n + 1], dp2[n + 1];
    int tot = 0;
    dp1[2] = k;
    dp2[2] = k * (k - 1);
    int total = dp1[2] + dp2[2];
    for(int i = 3; i <= n; i++)
    {
        dp1[i] = dp2[i - 1];
        dp2[i] = total * (k - 1);
        total = dp1[i] + dp2[i];
    }
    return total;
}

int main()
{
    int x = fun(2, 2);
    cout<<x<<endl;
}