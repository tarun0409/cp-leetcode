class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        long int reverse = 0L;
        long int y = (long int)x;
        while(y > 0)
        {
            reverse = (reverse*10L) + (y%10L);
            y = y/10L;
        }
        if(reverse == x)
        {
            return true;
        }
        return false;
        
    }
};
