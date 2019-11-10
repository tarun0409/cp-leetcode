class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size() < 3)
        {
            return result;
        }
        for(int i=0; i<nums.size()-2; )
        {
            int l = i+1;
            int r = nums.size()-1;
            int val = -1*nums[i];
            while(l<r)
            {
                if(nums[l] + nums[r] == val)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    result.push_back(temp);
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1])
                    {
                        l++;
                    }
                    while(r>l && nums[r] == nums[r+1])
                    {
                        r--;
                    }
                }
                else if(nums[l] + nums[r] < val)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            i++;
            while(i<nums.size() && nums[i] == nums[i-1])
            {
                i++;
            }
        }
        sort(result.begin(), result.end());
        return result;
        
    }
};
