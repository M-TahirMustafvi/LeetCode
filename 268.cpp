#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i) return nums[i]-1;
        }
        return nums.size();
    }
};

int main()
{
    vector<int> nums={3,0,1};
    Solution s1;
    cout<<s1.missingNumber(nums)<<"\n";
}