class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0)
        {
            string max_palindrome = "";
            return max_palindrome;
        }
        bool dyn_table[n][n];
        memset(dyn_table,0,sizeof(dyn_table));
        for(int i=0; i<n; i++)
        {
            dyn_table[i][i] = true;
        }
        int max_length = 1;
        int start = 0;
        for(int i=0; i<n-1; i++)
        {
            if(s[i]==s[i+1])
            {
                start = i;
                dyn_table[i][i+1] = true;
                max_length = 2;
            }
        }
        for(int k=3; k<=n; k++)
        {
            for(int i=0; i<n-k+1; i++)
            {
                int j = i+k-1;
                if(dyn_table[i+1][j-1] && (s[i]==s[j]))
                {
                    dyn_table[i][j] = true;
                    start = i;
                    max_length = k;
                }
            }
        }
        string max_palindrome = "";
        for(int i=start; i<(start+max_length); i++)
        {
            max_palindrome += s[i];
        }
        
        return max_palindrome;
        
    }
};
