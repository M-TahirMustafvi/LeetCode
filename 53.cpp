//Max SubArray Sum - Created by Moon on 27-08-24 at 1:35 AM
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Simple Brute Force Solution - O(n^2)
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int maxSum = 0;

        for(int i = 0; i < size; i++)
        {   
            int sum = 0;
            for(int j = i; j < size; j++)
            {
                sum += nums[j];
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }

    //Kanade's Algo, uses two helpers sum and maxSum, whenever sum < 0 it bounds it 0, and if it is greater than
    //previous sum it is max Sum.   Intution:: In my view as we are taking running sum, it will also cover that p
    //ossible sub array, with sum = maxSum and we will capture that, in running summ we are not missing any possi
    //ble situation where max sum is missed , and we are at it, our goal i.e, damn max array summ!!!
    int maxSubArrayKanade(vector<int>& nums) {
        int sum = 0; int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if(sum > maxSum)
                maxSum = sum;

            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }


    //Extenion of above problem, printing that particular sub array that was captured through Kanade's Algo!
    int maxSubArrayKanadePrint(vector<int>& nums) {
          int sum = 0, max = INT_MIN;
          int sumStart = -1, sumEnd = -1, start = -1;
          for(int i =0; i < nums.size(); i++)
          {
            sum += nums[i];
            
            if(sum > max)
            {  
                max = sum;
                sumStart = start;
                sumEnd = i; 
            }

            if(sum < 0)
            {   
                sum = 0;
                start = i+1;
            }
          }

          for(int i = sumStart; i <= sumEnd; i++)
          {
            cout<<nums[i]<< " ";
          }
          cout << endl;
          return max;
    }

};


int main()
{
    Solution s1;
    vector<int> nums= {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<< s1.maxSubArrayKanadePrint(nums) << endl << endl;    
    
}