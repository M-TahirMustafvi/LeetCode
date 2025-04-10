// Candies in flower bed
#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty.
                bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                // If both plots are empty, we can plant a flower here.
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        return count >= n;
    }
};

int main() {
    Solution solution;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    if (solution.canPlaceFlowers(flowerbed, n)) {
        cout << "Yes, you can plant " << n << " flowers." << endl;
    } else {
        cout << "No, you cannot plant " << n << " flowers." << endl;
    }

    return 0;
}