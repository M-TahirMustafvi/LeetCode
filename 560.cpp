#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Very Intutive approach, uses prefix sum technique, what it does is, stores all prefix sum with there counts,
    //now for a sum x, where x-k exists, in map, we will checkt its count and return that damn count add that to our count, and the solution will move on, in the end we will return count;
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> preSum;
        int count = 0, sum = 0;
        preSum[0] = 1;

        for(size_t i = 0; i < nums.size(); i++)
        {
           sum+=nums[i];
           count += preSum[sum - k];
           preSum[sum] +=1;
        }
        return count;
    }
};


int main()
{
    Solution s1;
    vector<int> nums= {-3, 3, 1, 1, 1};
    cout<< s1.subarraySum(nums, 3) << endl << endl;    
} 