class Solution {
public:

    unordered_map<int, vector<int>> indices;

    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            indices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        random_device rd;
        mt19937 gen(rd());
        if(indices.find(target) != indices.end())
        {
            vector<int>& targetIndices = indices[target];
            uniform_int_distribution<int> dist(0, targetIndices.size() - 1);
            int randomIndex = dist(gen);
            return targetIndices[randomIndex];
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
