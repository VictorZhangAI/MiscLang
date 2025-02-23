class Solution {
public:
    int i = 0;
    int calculate(string s) {
        int num = 0, ans = 0, sign = 1;
        while(i < s.size())
        {
            char ch = s[i++];
            if(ch >= '0' && ch <= '9')
            {
                num = num * 10 + (ch - '0');
            }
            else if(ch == '(')
            {
                num = calculate(s);
            }
            else if(ch == ')')
            {
                ans += (num * sign);
                return ans;
            }
            else if(ch == '+' || ch == '-')
            {
                ans += num * sign;
                num = 0;
                sign = (ch == '-') ? -1 : 1;
            }
        }
        ans += num * sign;
        return ans;
    }
};
