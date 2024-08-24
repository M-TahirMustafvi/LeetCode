//Two sum problem, there are tow ways to do so.

// One is a nested loop first, that goes through each element
//looks for potential sums, if there is any returns those indeices, althoug not implemented here but sounds
//very intutive and simple.
// TC : O(N^2)
// SC: O(1)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:

//The othere technique is below funciton which goes through vector, for every number, you check what will be the 
//other number required, by just doing "target - curr", now i now what is remaining, i will check in hash map, if 
//that very number is in map, if yes the so much so good, just print thath number, if not, puss this number in map
//as key and its indes as value and move on to next number, now as soon as you find the other number in map, it will 
//return that pair!!!
//TC :O(N)
//SC :O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        
        for(int i=0; i<nums.size(); i++)
        {
            int curr = nums[i];
            int req = target - curr;
            
            if(mpp.find(req)!= mpp.end())
                return {i, mpp[req]};
            
            else
                mpp[curr] = i;
        }
        return {-1, -1};
    }
};

int main()
{
    Solution s1;
    vector<int> nums= {1, 2, 3, 4, 5, 6};
    vector<int> result = s1.twoSum(nums, 5);
    for(int i:result)
        cout<<i<<" "; 
}