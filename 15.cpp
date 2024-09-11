//Three Some ;-)

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> triplet(int n, vector<int> &arr) {
    
    set<vector<int>> ansSet;
    for(size_t i = 0; i < n; i++)
    {
        set<int> hashSet;
        for(size_t j = i + 1; j < n; j++)
        {
            int req = -(arr[j] + arr[i]);
            if(hashSet.find(req) != hashSet.end())
            {
                vector<int> temp = {arr[i], req, arr[j]};
                sort(temp.begin(), temp.end());
                ansSet.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

//Uses an optimal approach, where we use three pointer two from start and one from last, after sorting;
//TC: O(nlogn)
//SC: O(1)
vector<vector<int>> threeSum(vector<int> &nums) {
    //sorting
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++)
    {
        //to avoid duplicates
        if(i != 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1;
        int k = n - 1;
        //for each i j & k
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum > 0) k--;
            else if(sum < 0)    j++;
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                //to avoid duplicates
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return ans;
                    
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = threeSum(arr);
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

