class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<long> > dpGrid( grid.size() , vector<long> (grid[0].size()));
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(i==0 && j==0)
                {
                    dpGrid[i][j] = (long)grid[i][j];
                }
                else if(i==0 && j!=0)
                {
                    dpGrid[i][j] = dpGrid[i][j-1] + (long)(grid[i][j]);
                }
                else if(i!=0 && j==0)
                {
                    dpGrid[i][j] = dpGrid[i-1][j] + (long)(grid[i][j]);
                }
                else
                {
                    dpGrid[i][j] = (dpGrid[i-1][j] < dpGrid[i][j-1] ? dpGrid[i-1][j] : dpGrid[i][j-1]) + (long)(grid[i][j]);
                }
            }
        }
        return (int)dpGrid[grid.size()-1][grid[0].size()-1];
    }
};
