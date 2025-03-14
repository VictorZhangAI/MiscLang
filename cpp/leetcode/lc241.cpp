class Solution {
public:

    int perform(int x, int y, char op)
    {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        bool isNumber = 1;

        for(int i = 0; i < expression.length(); i++)
        {
            if(!isdigit(expression[i]))
            {
                isNumber = 0;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for(int x : left)
                {
                    for(int y : right)
                    {
                        int val = perform(x, y, expression[i]);
                        results.push_back(val);
                    }
                }
            }
        }
        if(isNumber == 1) results.push_back(stoi(expression));
        return results;
    }
};
