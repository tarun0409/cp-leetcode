class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0 || triangle[0].size()==0)
        {
            return 0;
        }
        vector<vector<int>> dp;
        vector<int> temp;
        temp.push_back(triangle[0][0]);
        dp.push_back(temp);
        for(int i=1; i<triangle.size(); i++)
        {
            vector<int> row;
            for(int j=0; j<triangle[i].size(); j++)
            {
                int li = j-1;
                int ci = j;
                // int ri = j+1;
                int currVal = triangle[i][j];
                int currMin = INT_MAX;
                if(li>=0 && li<dp[i-1].size() && currVal + dp[i-1][li] < currMin) currMin = currVal + dp[i-1][li];
                if(ci>=0 && ci<dp[i-1].size() && currVal + dp[i-1][ci] < currMin) currMin = currVal + dp[i-1][ci];
                // if(ri>=0 && ri<dp[i-1].size() && currVal + dp[i-1][ri] < currMin) currMin = currVal + dp[i-1][ri];
                row.push_back(currMin);
            }
            dp.push_back(row);
        }
        int currMin = dp[dp.size()-1][0];
        for(int j=1; j<dp[dp.size()-1].size(); j++)
        {
            if(dp[dp.size()-1][j] < currMin) currMin = dp[dp.size()-1][j];
        }
        return currMin;
    }
};
