class Solution {
public:
    int reverse(int x) {
        long int reverse = 0;
        long int mul = 1L;
        if(x < 0)
        {
            mul = -1L;
        }
        long int y = mul*(long)x;
        while(y > 0)
        {
            reverse = (reverse*10)+(y%10);
            y /= 10;
        }
        if(x<0)
        {
            reverse *= -1;
        }
        if (reverse < -2147483648 || reverse >2147483647)
        {
            return 0;
        }
        return reverse;
    }
};
