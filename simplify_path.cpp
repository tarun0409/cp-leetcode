class Solution {
public:
    
    string simplifyPath(string path) {
        stack<string> s;
        string currStr = "";
        for(int i=0; i<path.length(); i++)
        {
            if(path[i] == '/')
            {
                if(!currStr.empty())
                {
                    if(!currStr.compare("..") && !s.empty()) //if current string is ..
                    {
                        s.pop();
                    }
                    else if(currStr.compare("..") && currStr.compare(".")) //if current string is not .
                    {
                        s.push(currStr);
                    }
                }
                currStr = "";
            }
            else
            {
                currStr += path[i];
            }
        }
        if(!currStr.empty())
        {
            if(!currStr.compare("..") && !s.empty()) //if current string is ..
            {
                s.pop();
            }
            else if(currStr.compare("..") && currStr.compare(".")) //if current string is not .
            {
                s.push(currStr);
            }
        }
        string resultPath = "/";
        stack<string> s2;
        while(!s.empty())
        {
            s2.push(s.top());
            s.pop();
        }
        while(!s2.empty())
        {
            resultPath+=s2.top();
            s2.pop();
            if(!s2.empty())
            {
                resultPath+='/';   
            }
        }
        return resultPath;
        
    }
};
