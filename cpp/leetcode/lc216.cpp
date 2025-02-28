class Solution {
public:
    vector<vector<int>> ans;
    int k;
    void getCombi(vector<int> vals, int tar, int start)
    {
        if(tar < 0) return;
        if(vals.size() == k)
        {
            if(tar == 0) ans.push_back(vals);
            return;
        }

        for(int i = start; i <= 9; i++)
        {
            if(tar - i >= 0)
            {
                vals.push_back(i);
                getCombi(vals, tar - i, i + 1);
                vals.pop_back();
            } 
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        getCombi({}, n, 1);
        return ans;
    }
};
