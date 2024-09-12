//Sort an array - uses merge sort, quick sort may be in future!!
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

    void mergeSort(vector<int>& nums, int low, int high)
    {
        if(low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
public:

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 4, 3, 2, 1};
    sol.sortArray(arr);

    for(int i:arr)
        cout << i << " ";
    cout << "\n";
}