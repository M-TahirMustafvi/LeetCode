//Rotate Image: rotated a matrix by 90 degree
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Simple Approach, uses simple obserbations!
    //TC: O(n*n)
    //SC: O(n*n)
    void rotate(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        size_t cols = rows > 0 ? matrix[0].size() : 0;

        vector<vector<int>> rotated(rows, vector<int>(cols, 0));
        //Observation: orignal column will be translated as rotated row, and rotated rows = (n-1) - i
        for(int i = 0 ; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                rotated[j][(rows-1)-i] = matrix[i][j];
            }
        }

        for(int i = 0 ; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matrix[i][j] = rotated[i][j];
            }
        }
    }

    //Optimal Method, just take transpose first and then reverse rows thats it!!
    void rotateOptimal(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        //In transpose the diagonal remains same, the upper diagonal gets changed with lower diagonal!
        for(size_t i = 0; i < n; i++)
        {
            for(size_t j = i+1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

int main()
{
    vector<vector< int> > matrix = {{1, 0, 3}, {4, 5, 6}, {7, 8, 9}};
    
    Solution sol;
    sol.rotateOptimal(matrix);

    size_t n = matrix.size();
    //size_t cols = rows > 0 ? matrix[0].size() : 0;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}