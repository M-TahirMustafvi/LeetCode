//Binary Search - O(logn)

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

            else if(nums[mid] < target) low = mid + 1;

            else high = mid - 1;
        }

        return -1;
    }
};

int main()
{
    Solution s1;
    int target = 5;
    vector<int> nums={1, 2, 3, 4, 5};
    
    int index = s1.search(nums, target);

    cout<< target << " is found at index :" << index << endl;

}