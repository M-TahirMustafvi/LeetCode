//majority element - created by moon on 2/12/2024
//approach can be improved by sorting first and then!! but i did brute force with eyes closed!
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int> nums) {
        int count=0;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {    for(int j=0;j<size;j++)
                if(nums[i]==nums[j])
                    count++;
            
            if(count>size/2) return nums[i];
            count=0;
        }
        return -1;
    }
};

int main()
{
    Solution s1;
    cout<<s1.majorityElement({2,2,1,1,1,2,2});
}