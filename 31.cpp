//Next Permutation, uses a very intutive approach, with three steps!! TC: O(N), SC: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;

        //Step: 01 find the point after which we have to permute, we will do that by traversing array in reverse order. Now as the next permutation has to necessarily be larger then the current one, chosing form last we will chose the first number that is smaller in sequence, because after swapping it has to move to right, and if we move a larger number towards units place, we will end up as a smaller number which is not acceptable, so we will find first smaller in sequence!
        //larger then last one, s
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                index = i;
                break;
            }
        }

        //If no smaller found just reverse the whole array, i.e, next permutation
        if(index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        //Step: 02 now find the next smallest sequence after that found pre-constatn, so the number immediate left to that number should be greater than that number and smaller than the whole lot to the right, we will find that number and swap with that very number;
        for(int i = n-1; i > index ; i--)
        {
            if(nums[i] > nums[index])
            {   
                swap(nums[i], nums[index]);
                break;
            }
        }

        //Step: 03 reverse the remaining part and here it is next permutation!
        reverse(nums.begin()+index+1, nums.end());
    }
};

int main()
{
    Solution s1;
    vector<int> nums= {2, 1, 5, 4, 3, 0, 0};
    s1.nextPermutation(nums);

    for(int i:nums)
        cout<< i <<" ";
    cout<< endl;
}