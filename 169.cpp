//majority element - created by moon on 2/12/2024
//Uses sorting, after sorting middle element is always the majority element!
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int> nums) {
        int size=nums.size();
        sort(nums.begin(), nums.end());
        return nums[size/2];
    }
};

int main()
{
    Solution s1;
    cout<<s1.majorityElement({2,2,1,1,1,2,2})<<endl;
}