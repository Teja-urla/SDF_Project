#include <bits/stdc++.h>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int i = -1, j = -1;
        int len = 0;

        while(true){
            bool f1 = false, f2 = false;
            while(j < n - 1){
                f1 = true;
                j++;
                mp[s[j]]++;
                if(mp[s[j]] == 2)
                {
                   break;
                }
                else
                {
                    len = max(j - i, len);
                }
                
            }

            while(i < j){
                f2 = true;
                i++;
                mp[s[i]]--;
                if(mp[s[i]] == 1){
                    break;
                }
            }
            if(f1 == false and f2 == false){
                break;
            }
        }
        return len;
    }

int main()
{
    int x = lengthOfLongestSubstring("abcabcbb");
    cout<<x<<endl;
}