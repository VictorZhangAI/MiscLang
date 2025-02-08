class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = "";
        int i = 0;

        while(i < strs[0].size())
        {
            for(int j = 0; j < strs.size(); j++)
            {
                if(strs[j][i] != strs[0][i])
                {
                    return prefix;
                }
            }
            prefix += strs[0][i];
            i++;
        }
        return prefix;
    }
};
