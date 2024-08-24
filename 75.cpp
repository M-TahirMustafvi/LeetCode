//Sort Colors represented as 0, 1, 2, uses ducth national flag algo, which sorts an array containing 0s and 1s!
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    //A simple algo, countes 0's 1's and 2's in array, and then replaces all elements of array, with them in 
    //order TC :O(n) SC : O(1)
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        
        for(int i:nums)
        {
            if(i == 0) count0++;
            else if(i == 1) count1++;
            else count2++;
        }
        cout<<count0<<" "<<count1<<" "<<count2<<endl;
        for(int i=0; i<count0;i++) nums[i]=0;
        for(int i=count0; i<count0 +count1;i++) nums[i]=1;
        for(int i=count0 +count1; i<nums.size();i++) nums[i] = 2;
    }

    //Dutch national flag algo works very simply uses three pointers over array, low, mid and high
    //low: tracks the boundary where the next zero should be placed
    //mid: traveses through the array, and puts o's 1's and 2's at optimum place
    //high: track the boundary where the next 2 should be placed!

    //TC :O(n)
    //SC :O(1)
    void dutchNationalFlag(vector<int>& nums)
    {
        int low = 0, mid =0, high = nums.size()-1;
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
                mid++;
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

};

int main()
{
    Solution s1;
    vector<int> arr = {2,0,2,1,1,0};
    s1.dutchNationalFlag(arr);
    for(int i:arr) cout<<i<<" ";

}