class Solution {
public:

    string find(string s, map<string, string>& p)
    {
        return p[s] == s ? s : find(p[s], p);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        for(int i = 0; i < accounts.size(); i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                parents[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }

        for(int i = 0; i < accounts.size(); i++)
        {
            string p = find(accounts[i][1], parents);
            for(int j = 2; j < accounts[i].size(); j++)
            {
                parents[find(accounts[i][j], parents)] = p;
            }
        }

        for(int i = 0; i < accounts.size(); i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                unions[find(accounts[i][j], parents)].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> res;
        for(pair<string, set<string>> p : unions)
        {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};
