//Four Some ;-)

#include <bits/stdc++.h>
using namespace std;


//Same as three some, just one pointer extra refer to 15.cpp
vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> quads;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && nums[i-1] == nums[i]) continue;

        for(int j = i + 1; j < n; j++)
        {
            if( j > i+1 && nums[j - 1] == nums[j]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums [k];
                sum += nums[l];
                if(sum < target) k++;
                else if(sum > target) l--;
                else
                {
                    quads.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k - 1]) k++;
                    while(k < l && nums[l] == nums[l + 1]) l--;
                }
            }
        }
    }
    return quads;
                    
}


int main()
{
    vector<int> arr = { 2, 2, 2, 2};
    int n = arr.size();
    vector<vector<int>> ans = fourSum(arr, 8);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

