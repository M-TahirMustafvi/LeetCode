//Set Matrix Zero, sets matrix that row and col zero that has atleast one zero!
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    //Approach is 2 steps first records those zeros separately and then sets corresponding rows and cols zero!
    //TC: O(n*m)
    //SC: 0(n + m)
    void setZeroesBetter(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        size_t cols = rows > 0 ? matrix[0].size() : 0 ;
        vector<int> checkRows(cols, 1); //To mark Rows
        vector<int> checkCols(rows, 1); //To mark Cols

        //Sets Corresponding indexes of checkRows and checkCols as zero, where each index represents a row and a 
        //Column respectively!
        for(int i = 0 ; i < rows; i++)
        {
            for(int j = 0; j < cols ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    checkRows[j] = 0;   //Actually marks for rows, so it has to behave as a column
                    checkCols[i] = 0;   //Actually marks for cols, so it has to behave as a row
                }
            }
        }

        //Uses those indexes to set whole matrix's rows and cols zero!!
        for(int i = 0 ; i < rows; i++)
        {
            for(int j =0; j < cols ; j++)
            {
                if(checkRows[j] == 0 || checkCols[i] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
    
    //Approach Better: Uses first row and first column to manage hash arrays more fast and accurate, but the [0][0] index is an edge case should be handeled perfectly!
    //TC: O(n*m)
    //SC: 0(1)
    void setZeroesBest(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        size_t cols = rows > 0 ? matrix[0].size() : 0 ;
        int col0 = 1;
        
        //Sets Hash Rows
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                //For Each index
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    
                    //If it is first row just don't use [0][0] index use another col0 variable
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        //Refills the array with necessary zero;
        for(int i = 1; i < rows; i++)
        {
            for(int j = 1; j < cols; j++)
            {
                if(matrix[0][j] == 0 || matrix[i][0] ==0)
                    matrix[i][j] = 0;
            }
        }

        //Fills Hash column
        if(matrix[0][0] == 0)
        {
            for(int i= 0; i < cols; i++)
                matrix[0][i] = 0;
        }

        //Fills hash row
        if(col0 == 0)
         {
            for(int i= 0; i < rows; i++)
                matrix[i][0] = 0;
         }   
    
    }
};

int main()
{
    vector<vector< int> > matrix = {{1, 0, 3}, {4, 5, 6}, {7, 8, 9}};
    
    Solution sol;
    sol.setZeroesBest(matrix);

    size_t rows = matrix.size();
    size_t cols = rows > 0 ? matrix[0].size() : 0;

    for(int i = 0 ; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}