class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
        {
            return 0;
        }
        if(obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        vector<vector<long>> res;
        for(int i=0; i<obstacleGrid.size(); i++)
        {
            vector<long> temp;
            for(int j=0; j<obstacleGrid[i].size(); j++)
            {
                temp.push_back((long)(obstacleGrid[i][j]));
            }
            res.push_back(temp);
        }
        res[0][0] = 1;
        for(int i=1; i<obstacleGrid.size(); i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                res[i][0] = 0;
            }
            else if(!(res[i-1][0] == 0))
            {
                res[i][0] = 1;
            }
            else
            {
                res[i][0] = 0;
            }
        }
        for(int j=1; j<obstacleGrid[0].size(); j++)
        {
            if(obstacleGrid[0][j] == 1)
            {
                res[0][j] = 0;
            }
            else if(!(res[0][j-1] == 0))
            {
                res[0][j] = 1;
            }
            else
            {
                res[0][j] = 0;
            }
        }
        for(int i=1; i<res.size(); i++)
        {
            for(int j=1; j<res[i].size(); j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    res[i][j] = 0;
                }
                else
                {
                    res[i][j] = res[i][j-1] + res[i-1][j];
                }
            }
        }
        return res[res.size()-1][res[0].size()-1];
        
    }
};
