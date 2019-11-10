class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1 && nums[0] == val) return 0;
        int j=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
        
    }
};
