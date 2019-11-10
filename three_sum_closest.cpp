class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size() < 3)
        {
            return 0;
        }
        int targetSum = 0;
        int targetDiff = -1;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2; i++)
        {
            int softTarget = target - nums[i];   
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                int s = nums[i]+nums[l]+nums[r];
                if(targetDiff < 0)
                {
                    targetDiff = (target - s)>0?(target-s):(s-target);
                    if(targetDiff == 0)
                    {
                        return s;
                    }
                    targetSum = s;
                }
                else
                {
                    int tempDiff = (target - s)>0?(target-s):(s-target);
                    if(tempDiff == 0)
                    {
                        return s;
                    }
                    if(tempDiff < targetDiff)
                    {
                        targetSum = s;
                        targetDiff = tempDiff;
                    }
                }
                if(nums[l]+nums[r] > softTarget)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return targetSum;
    }
};
