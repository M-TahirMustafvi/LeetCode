//Search in rotated sorted array with duplicates!
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;

            //array can be left or right rotated, and if mid=left=right, only then
            //duplicates will cause an issue, following is the edge case handeled
            if(nums[mid] == nums[high] && nums[mid] == nums[low])
            {
                high--;
                low++;
                continue;
            }
            //if left part of the array is sorted
            if(nums[low] <= nums[mid])
            {
                //look for target in sorted half
                if(nums[low] <= target && target <=nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(nums[mid] <= target && target <= nums[high])
                    low = mid+1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s1;
    vector<int> nums= {3, 1, 2, 3, 3, 3, 3};
    int index = s1.search(nums, 2);
    cout << index << endl << endl;
}