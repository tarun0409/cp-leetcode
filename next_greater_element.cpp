class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> greaterNum;
        for(int i=0; i<nums2.size(); i++)
        {
            while(!s.empty())
            {
                int j = s.top();
                if(nums[j] < nums[i])
                {
                    greaterNum[nums[j]] = nums[i];
                    s.pop();
                }
                else break;
            }
        }
        vector<int> ret;
        for(int i=0; i<nums1.size(); i++)
        {
            if(greaterNum.find(nums1[i]) == greaterNum.end()) ret.push_back(-1);
            else ret.push_back(greaterNum[nums1[i]]);
        }
        return ret;
    }
};