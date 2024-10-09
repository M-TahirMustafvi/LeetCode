//First and last Occurence

//It can also be done with lower and upper bound, but for that we have to check for some cases,
//first is, if the number was not in array lower bound would have returned the next number instead of -1,
//and if it had to return last element of the array, for that we would have to check!!
//TC: O(logn)
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int firstOccurence(vector<int>& nums, int target) {
        int first = -1, low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
            { 
                first = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return first;
    }

    int lastOccurence(vector<int>& nums, int target) {
        int last = -1, low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
            { 
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return last;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurence(nums, target);
        int last = lastOccurence(nums, target);
        return {first, last};
    }
};

int main()
{
    Solution s1;
    vector<int> nums= {1, 2, 3};
    vector<int> pair = s1.searchRange(nums, 1);
    cout << pair[0] << "  " << pair[1] << endl << endl;
}