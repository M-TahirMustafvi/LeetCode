//Find Min in rotated sorted array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int Min = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            //look into sorted part
            if(nums[low] <= nums[mid])
            {
                //find min in sorted part
                Min = min(Min, nums[low]);
                low = mid + 1;  //trim the search space
            }
            else
            {
                Min = min(Min, nums[mid]);
                high = mid - 1;
            }
        }
        return Min;
    }
};

int main()
{
    Solution s1;
    vector<int> nums= {3,4,5,1,2};
    cout<< s1.findMin(nums) << endl << endl;
}