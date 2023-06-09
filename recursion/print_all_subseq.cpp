#include <bits/stdc++.h>
using namespace std;

void printSubsequences(vector<int> arr, int n, vector<int> vec, int index){
    if(index == n){
        if(vec.empty()){
            cout<<"{}"<<endl;
            return;
        }
        for(auto it : vec){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    // picking the element and pushing into the vector
    vec.push_back(arr[index]);
    printSubsequences(arr, n, vec, index + 1);
    // popping the element i.e not picking the element into the vector
    vec.pop_back();
    printSubsequences(arr, n, vec, index + 1);
}

int main()
{
    vector<int> arr{10, 5, 2, 6};
    int n = arr.size();
    vector<int> vec;
    printSubsequences(arr, n, vec, 0);
}