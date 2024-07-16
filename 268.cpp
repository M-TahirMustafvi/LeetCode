//Uses the approach of Gauss to find sum of first n numbers, and compares the sum with sum of array to 
//get result!
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int summation = size * (size + 1)/2;
        int arrsum = 0;
        for(int i: nums)
            arrsum += i;
        return summation - arrsum;
    }
};

int main()
{
    vector<int> nums={3,0,1};
    Solution s1;
    cout<<s1.missingNumber(nums)<<"\n";
}