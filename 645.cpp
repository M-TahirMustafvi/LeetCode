//Set Mismatch, finds which number is missing, and which is getting repeated!

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:

    int max(vector<int>& nums)
    {
        int max=0;
        for(int i=0;i<nums.size();i++)
        {
            if(max<nums[i]) max=nums[i];
        }
        return max;
    }

    vector<int> findErrorNums(vector<int>& nums) {
        
        int n =nums.size();
        vector<int>v(n+1,0);
        int missing=0,duplicate = 0;

        for(int i =0;i<n;i++){
            v[nums[i]]++;
        }

        for(int i =1;i<v.size();i++){
            if(v[i]==2)duplicate = i;
            if(v[i]==0)missing = i;
        }

        return {duplicate,missing};
    }

};

int main() 
{
  Solution s1;
  vector<int> nums={1,1};
  
  vector<int> arr1=s1.findErrorNums(nums);
  for(int i=0;i<arr1.size();i++)
    cout<<arr1[i]<<" ";
  
}