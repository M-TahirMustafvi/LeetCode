//Searching in rotated sorted array!
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
        return -1;
    }
};

int main()
{
    Solution s1;
    vector<int> nums= {4, 5, 6, 1, 2, 3};
    int index = s1.search(nums, 2);
    cout << index << endl << endl;
}