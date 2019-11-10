class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size()<4)
        {
            return result;
        }
        for(int i=0; i<nums.size()-3; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<nums.size()-2; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int softTarget = target - (nums[i]+nums[j]);
                int l = j+1;
                int r = nums.size()-1;
                while(l<r)
                {
                    if(nums[l]+nums[r] == softTarget)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        result.push_back(temp);
                        l++;
                        r--;
                        while(l<r && (nums[l]==nums[l-1] && nums[r]==nums[r+1]))
                        {
                            l++;
                            r--;
                        }
                    }
                    else if(nums[l]+nums[r] < softTarget)
                    {
                        l++;
                        while(l<r && nums[l]==nums[l-1]) l++;
                    }
                    else
                    {
                        r--;
                        while(r>l && nums[r]==nums[r+1]) r--;
                    }   
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
