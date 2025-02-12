class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLength = 0;
        stack<int> pathLengths;
        stringstream ss(input);
        string line;

        while(getline(ss, line))
        {
            int depth = 0;

            while(line[depth] == '\t')
            {
                depth++;
            }
            while(pathLengths.size() > depth)
            {
                pathLengths.pop();
            }

            string name = line.substr(depth);
            int length = (pathLengths.empty() ? 0 : pathLengths.top())
                + name.length()
                + (pathLengths.empty() ? 0 : 1);

            if(name.find('.') != string::npos)
            {
                maxLength = max(maxLength, length);
            }
            else
            {
                pathLengths.push(length);
            }
        }
        return maxLength;
    }
};
