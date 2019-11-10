class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> s;
        if(preorder.length()==0)
        {
            return true;
        }
        vector<string> str;
        string currStr = "";
        for(int i=0; i<preorder.length(); i++)
        {
            if(preorder[i]==',' && !currStr.empty())
            {
                str.push_back(currStr);
                currStr = "";
            }
            else
            {
                currStr+=preorder[i];
            }
        }
        if(!currStr.empty())
        {
            str.push_back(currStr);
        }
        for(int i=str.size()-1; i>=0; i--)
        {
            if(str[i][0] == '#')
            {
                s.push("#");  
            }
            else
            {
                if(s.empty()) return false;
                string h1 = s.top();
                s.pop();
                if(s.empty()) return false;
                string h2 = s.top();
                s.pop();
                if(h1[0]=='#' && h2[0]=='#')
                {
                    s.push("#");
                }
                else
                {
                    return false;
                }
            }
        }
        if(!s.top().compare("#"))
        {
            s.pop();
            if(s.empty()) return true;
        }
        return false;
    }
};
