class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<string> substrings;
        string curr_string = "";
        int curr_index = 0;
        int index[128];
        for(int i=0; i<128; i++)
        {
            index[i] = -1;
        }
        while(curr_index < s.length())
        {
            int i = (int)s[curr_index];
            // if(c < 97 || c > 122)
            // {
            //     break;
            // }
            // int i = c - 97;
            if(index[i]==-1)
            {
                index[i] = curr_index;
                curr_string += s[curr_index];
            }
            else
            {
                substrings.push_back(curr_string);
                curr_string = "";
                curr_index = index[i];
                for(int i=0; i<128; i++)
                {
                    index[i] = -1;
                }
            }
            curr_index++;
        }
        substrings.push_back(curr_string);
        int max_len = 0;
        for(int i=0; i<substrings.size(); i++)
        {
            string t = substrings[i];
            if(t.length() > max_len)
            {
                max_len = t.length();
            }
        }
        return max_len;
    }
};
