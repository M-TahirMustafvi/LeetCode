//Reverse Pairs -Uses Merge Sort!
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        
        while(left <= mid && right <=high)
        {
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while(left <= mid)
            temp.push_back(nums[left++]);
        while(right <= high)
            temp.push_back(nums[right++]);
        
        for(int i = low; i <= high; i++)
            nums[i] = temp[i - low];
    }

    //Counts the pairs that satisfing arr[i] > arr[j] * 2
    int countReversals(vector<int>& nums, int low, int mid, int high)
    {
        int right = mid + 1;
        int count = 0;
        //Traverses The left Part 
        for(int i = low; i <= mid; i++)
        {
            //checks the condition, untill right reaches end
            //and we know, arrays are sorted, so if a number satisfies for left, it will
            //always satisfy the condition for right! 
            while(right <= high && nums[i] > nums[right] * 2LL)
                right++;
            count += right - (mid + 1); //counts and that will be the numbers of element we are on right!!
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high)
    {
        int count = 0;
        if(low >= high)
            return count;
        int mid = low + (high - low) / 2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countReversals(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
       return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution s1;
    vector<int> arr = {2,4,3,5,1};
    cout<<s1.reversePairs(arr);
}