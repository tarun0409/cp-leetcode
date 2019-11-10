class Solution {
public:
    vector<vector<int>> upaths;
    int updatePaths(int i, int j, int m, int n)
    {
        if(i==m-1 && j==n-1)
        {
            if(upaths[i][j]==0)
            {
                upaths[i][j] = 1;   
            }
            return upaths[i][j];
        }
        if(upaths[i][j] > 0)
        {
            return upaths[i][j];
        }
        int right_value = 0;
        int down_value = 0;
        if(j < n-1)
        {
            right_value = updatePaths(i, j+1,m,n);
        }
        if(i < m-1)
        {
            down_value = updatePaths(i+1,j,m,n);
        }
        upaths[i][j] += right_value;
        upaths[i][j] += down_value;
        
        return upaths[i][j];
        
    }
    int uniquePaths(int m, int n) {
        
        for(int i=0; i<m; i++)
        {
            vector<int> temp;
            for(int j=0; j<n; j++)
            {
                temp.push_back(0);
            }
            upaths.push_back(temp);
        }
        
        return updatePaths(0,0,m,n);
        
    }
};
