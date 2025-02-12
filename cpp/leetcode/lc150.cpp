class Solution {
public:
    long resolves(int a, int b, char op)
    {
        if(op == '+') return a + b;
        else if(op == '-') return a - b;
        else if(op == '*') return a * b;
        else return a / b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        int n = tokens.size();
        for(int i = 0; i < n; i++)
        {
            if(tokens[i].size() == 1 && tokens[i][0] < 48)
            {
                long integer2 = s.top();
                s.pop();
                long integer1 = s.top();
                s.pop();
                string op = tokens[i];
                long ans = resolves(integer1, integer2, op[0]);
                s.push(ans);
            }
            else
                s.push(stol(tokens[i]));
        }
        return s.top();
    }
};
