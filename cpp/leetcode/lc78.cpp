class Solution {
public:
    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset)
    {
        if(index == nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);
        subset.pop_back();
        createSubset(nums, index + 1, res, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        createSubset(nums, 0, res, subset);
        return res;
    }
};
