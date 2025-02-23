class Solution {
public:
    int calculate(string s) {
        auto precedence = [](char c){ return c == '*' || c == '/'; };
        stack<char> op;
        stack<int> num;
        int cur = 0;
        s += '#';
        for(auto c : s)
        {
            if(c == ' ') continue;
            else if(isdigit(c))
                cur = cur * 10 + (c - '0');
            else
            {
                num.push(cur);
                while(size(op) && precedence(c) <= precedence(op.top()))
                {
                    int num1 = num.top(); num.pop();
                    int num2 = num.top(); num.pop();
                    char curOp = op.top(); op.pop();

                    if(curOp == '*') num.push(num2 * num1);
                    else if(curOp == '/') num.push(num2 / num1);
                    else if(curOp == '+') num.push(num2 + num1);
                    else if(curOp == '-') num.push(num2 - num1);
                }
                op.push(c);
                cur = 0;
            }
        }
        return num.top();
    }
};
