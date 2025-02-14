class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(char digit : num)
        {
            while(!s.empty() && k > 0 && s.top() > digit)
            {
                s.pop();
                k--;
            }
            s.push(digit);
        }

        while(k > 0 && !s.empty())
        {
            s.pop();
            k--;
        }
        string result;

        while(!s.empty())
        {
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());

        int pos = result.find_first_not_of('0');
        result = (pos == string::npos) ? "0" : result.substr(pos);
        return result;
    }
};
