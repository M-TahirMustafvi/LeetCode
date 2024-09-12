//Max-Product SubArray
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Simple O(n^2) Brute Force
    int maxProductBrute(vector<int>& nums) {
        int n = nums.size();
        int prod = 1, maxProd = 1;
        for(int i = 0; i < n; i++)
        {
            prod = nums[i];
            maxProd = max(prod, maxProd);
            for(int j = i+1; j < n; j++)
            {
                prod*= nums[j];
                maxProd = max(prod, maxProd);
            }
        }
        return maxProd;
    }

    //Optimal, uses prefix product, and suffix product for checing max product
    //and returns that product, a simple approach, b/c if it contained odd -ve's
    //we need to rule that -ve number out, and the subarray will be prefix, or suffix to it
    //and our method will find that
    //TC: O(n)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int preMul = 1, suffMul = 1;
        int maxProduct = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            //To account for zeros's in array
            if(preMul == 0) preMul = 1;
            if(suffMul == 0) suffMul = 1;
            //pre and suff products in array
            preMul *= nums[i];
            suffMul *= nums[n - i - 1];
            //max product is traced
            maxProduct = max(maxProduct, max(preMul, suffMul));
        }
        return maxProduct;
    }
};

int main()
{
    Solution s1;
    vector<int> arr = {1, 2, -3, 0, -4, -9, 0, -4, -5};
    cout<<s1.maxProduct(arr)<<endl;
}