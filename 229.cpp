//Majority element II
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //simple approach, elements more than n/3 time, just extended moores algo, we will just try to
    //maintain two pointers!!
    vector<int> majorityElement(vector<int>& nums) {
        int elem1 = INT_MIN, elem2 = INT_MIN;
        int n = nums.size();
        int count1 = 0, count2 = 0;
        vector<int> result;

        for(size_t i = 0; i < n; i++)
        {
            if(count1 == 0 && nums[i] != elem2)
            {
                count1 = 1;
                elem1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != elem1)
            {
                count2 = 1;
                elem2 = nums[i];
            }
            else if(nums[i] == elem1)
                count1++;
            else if(nums[i] == elem2)
                count2++;
            else   
            {
                count2--;
                count1--;    
            }
        }

        count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(elem1 == nums[i]) count1++;
            else if(elem2 == nums[i]) count2++;
        }

        int mini = int(n / 3) + 1;
        if(count1 >= mini)  result.push_back(elem1);
        if(count2 >= mini)  result.push_back(elem2);
        return result;
    }
};

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    vector<int> ans = sol.majorityElement(arr);
    for(int i: ans)
        cout<< i <<" ";
}