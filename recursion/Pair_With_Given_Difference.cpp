#include<bits/stdc++.h>
using namespace std;

int check_difference(vector <int> arr, int diff){
    int n = arr.size();
    unordered_set<int> set;
    for(int i = 0; i < n; i++){
        if(set.find(arr[i] - diff) != set.end()){
            return 1;
        }
        if(set.find(arr[i] + diff) != set.end()){
            return 1;
        }
        set.insert(arr[i]);
    }
}

int main()
{
   int arr[] = {1, 2, 3};
   int n = sizeof(arr) / sizeof(arr[0]);
//    check_difference(arr, n);
}