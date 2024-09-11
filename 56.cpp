//Merge Overlapping Intervals
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Merges OverLapping intervals!
    //TC: O(nlogn)
    //SC: O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        int n = intervals.size();
        for(int i = 0; i < n; i++)
        {
            //Checks for the new disjoint interval, in array, if yes add that to array
            if(merged.empty() || intervals[i][0] > merged.back()[1])
                merged.push_back(intervals[i]);
            //Now if curren index overlaps with last interval in the ans, just update that to accomodate both!
            else
                merged.back()[1] = max(intervals[i][1], merged.back()[1]);
        }
        return merged;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    Solution sol;
    vector<vector<int>> ans = sol.merge(arr);
    
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans)
        cout << "[" << it[0] << ", " << it[1] << "] ";

    cout << endl;
}