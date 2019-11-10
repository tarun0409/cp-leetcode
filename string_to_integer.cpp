class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        while((int)str[i]==32 && i<str.length())
        {
            i++;
        }
        int sign = 1;
        if((int)str[i]==43 || (int)str[i]==45)
        {
            if((int)str[i]==45)
            {
                sign = -1;
            }
            i++;
        }
        long num = 0;
        while(i<str.length() && ((int)str[i]>=48 && (int)str[i]<=57))
        {
            num=(num*10)+((int)str[i]-48);
            if(num >= 2147483648 && sign == 1)
            {
                return 2147483647;
            }
            else if(num > 2147483648 && sign == -1)
            {
                return -2147483648;
            }
            i++;
        }
        num *= sign;
        return (int)num;
        
    }
};
