//Rearrange Array by sign, very simple no master explanation needed, refined by Tahir on 7, september 24
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positves;
        vector<int> negatives;

        for(int i:nums)
        {
            if(i >= 0)
                positves.push_back(i);
            else
                negatives.push_back(i);
        }

        for(int i = 0; i < nums.size()/2; i++)
        {
            nums[2*i] = positves[i];    //even indexes
            nums[2*i+1] = negatives[i]; //odd indexes
        }
        return nums;
    }
};

int main()
{
    vector<int> arr={3, 1, -2, -5, 2, -4};
    Solution s1;
    vector<int> sol = s1.rearrangeArray(arr);
    for(int i: sol)
        cout<< i << " ";
}