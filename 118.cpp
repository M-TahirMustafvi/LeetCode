//Print Pascal Triangle upto nth row!!
#include<bits/stdc++.h>
using namespace std;

int ComputenCr(int n, int r)
{
    int res = 1;
    for(int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }   
    return res;
}


class Solution {
private:
    //Generat a single row of pascal triangle
    vector<int> generateRow(int n) {
        int elem = 1;
        vector<int> row;
        row.push_back(elem);
        for(int i = 1; i <= n; i++)
        {
            //simple formula just try to visalise a single row and you will get it!
            elem = elem * (n - i + 1);
            elem = elem / i;
            row.push_back(elem);
        }
        return row;
    }

public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        //clear as sun, just calling generateRow for each row!!
        for(int i = 0; i < numRows; i++)
        {
            triangle.push_back(generateRow(i));
        }

        return triangle;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> triage = sol.generate(4);

    
   for(const auto& row : triage) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<endl;
}