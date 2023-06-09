#include <bits/stdc++.h>
using namespace std;

void combinations(int *arr, int index, vector<int> vec, int target, int n) 
{
      if(target == 0)
      {
         for(auto it : vec){
            cout<<it<<" ";
         }
         cout<<endl;
         return;
      }
      else if(target < 0)return;
      else if(target != 0 and index >= n)
      {
         return;
      }
   if(arr[index] <= target){
      vec.push_back(arr[index]);
      combinations(arr, index, vec, target - arr[index], n);
      vec.pop_back();
   }
   combinations(arr, index + 1, vec, target, n);
}

int main()
{
   int target = 7;
   int arr[] = {2, 3, 5};
   int n = sizeof(arr)/sizeof(arr[0]);
   vector<int> vec;
   combinations(arr, 0, vec, target, n);
}
