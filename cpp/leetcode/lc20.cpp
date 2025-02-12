class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for(int i = 0; i <= s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                sc.push(s[i]);
            if(s[i] == ')')
            {
                if(sc.empty() || sc.top() != '(') return false;
                sc.pop();
            }
            if(s[i] == ']')
            {
                if(sc.empty() || sc.top() != '[') return false;
                sc.pop();
            }
            if(s[i] == '}')
            {
                if(sc.empty() || sc.top() != '{') return false;
                sc.pop();
            }
        }
        if(sc.empty())
            return true;
        else
            return false;
    }
};
