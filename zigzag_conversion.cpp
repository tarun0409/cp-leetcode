class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        vector<string> row_strings;
        for(int i=0; i<numRows; i++)
        {
            row_strings.push_back("");
        }
        int curr_index = 0;
        int inc = 1;
        for(int i=0; i<s.length(); i++)
        {
            if(curr_index==0)
            {
                inc = 1;
            }
            else if(curr_index == numRows)
            {
                curr_index = numRows - 2;
                if(curr_index != 0)
                {
                    inc = -1;
                }
            }
            row_strings[curr_index]+=s[i];
            curr_index += inc;
        }
        string master = "";
        for(int i=0; i<numRows; i++)
        {
            master = master.append(row_strings[i]);
        }
        return master;
    }
};
