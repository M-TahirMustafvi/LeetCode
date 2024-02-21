#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
     
        return n > 0 && ((n & (n - 1)) == 0);
    }
};

int main()
{
    int x;
    cin>>x;
    Solution s1;
    cout<< s1.isPowerOfTwo(x)<<endl;
    return 0;
}
