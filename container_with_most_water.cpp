class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_area = 0;
        
        while(i < j)
        {
            int h = j-i;
            int area = h*(height[i] < height[j]?height[i]:height[j]);
            if(area > max_area)
            {
                max_area = area;
            }
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
        
    }
};
