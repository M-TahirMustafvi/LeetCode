//Best Time to buy and sell Stocks!!!
//The approach is pretty intutive, although i couldnt got it easily, clear as sun, the point is
//for each sell you must have bought that at any day before with minimum price now i will keep track
//of that minimum price and track the maxProfit along the array, i will check difference with each min price,
//and find profit for that transaction,and as soon as i will go on to compare it with max profit, which will
//print that profit!!

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], maxPro = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};

int main()
{
    Solution s1;
    vector<int> nums= {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<< s1.maxProfit(nums) << endl << endl;    
}