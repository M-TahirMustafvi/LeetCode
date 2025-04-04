//Predict if every kid in the array will have max candies even after adding extra candies
#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandy = 0;
    
    for(int i:candies)
        if( i > maxCandy)
            maxCandy = i;

    vector<bool> result;

    for (int candy : candies)
        result.push_back(candy + extraCandies >= maxCandy);

    return result;
}

int main() {
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> result = kidsWithCandies(candies, extraCandies);

    cout << "Result: ";
    for (bool val : result) {
        cout << (val ? "true" : "false") << " ";
    }

    return 0;
}
