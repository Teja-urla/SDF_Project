#include<bits/stdc++.h>
using namespace std;

void printSubarray(int nums[], int index, vector<int> &input)
{
    for (int j: input)
    {
        cout << "[" << (j + 1) << "…" << index << "] —— { ";
        copy(nums + j + 1, nums + index + 1, ostream_iterator<int>(cout, " "));
        cout << "}\n";
    }
}

void findSubarrays(int nums[], int n, int target)
{

    unordered_map<int, vector<int>> map;

    map[0].push_back(-1);

    int sum_so_far = 0;

    // traverse the given array
    for (int index = 0; index < n; index++)
    {
        sum_so_far += nums[index];

        auto itr = map.find(sum_so_far - target);
        if (map.find(sum_so_far - target) != map.end())
        {
            printSubarray(nums, index, map[itr->first]);
        }

        map[sum_so_far].push_back(index);
    }
}

int main()
{
    int nums[] = { 3, 4, -7, 1, 3, 3, 1, -4 };
    int target = 7;

    int n = sizeof(nums)/sizeof(nums[0]);
    findSubarrays(nums, n, target);

    return 0;
}