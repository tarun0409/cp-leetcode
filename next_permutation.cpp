class Solution {
public:
    int binSearch(vector<int> nums, int l, int r, int key)
    {
        int index = -1; 
        while (l <= r) 
        { 
            int mid = l + (r - l) / 2; 
            if (nums[mid] <= key) r = mid - 1; 
            else 
            { 
                l = mid + 1; 
                if (index == -1 || nums[index] >= nums[mid]) index = mid; 
            }    
        } 
        return index; 
    }
    void nextPermutation(vector<int>& nums) {
        int i=-1;
        for(int j=nums.size()-2; j>=0; j--)
        {
            if(nums[j] < nums[j+1])
            {
                i=j;
                break;
            }
        }
        if(i<0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        int index = binSearch(nums,i+1,nums.size()-1,nums[i]);
        
        int temp = nums[index];
        nums[index] = nums[i];
        nums[i] = temp;
        reverse(nums.begin()+(i+1),nums.end());
        
    }
};
