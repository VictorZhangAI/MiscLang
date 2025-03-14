class Solution {
public:

    vector<int> original;
    int n;

    Solution(vector<int>& nums) {
        original = nums;
        n = original.size();
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = original;

        int leftSize = n;
        for(int i = n - 1; i >= 0; i--)
        {
            int j = rand() % leftSize;
            swap(shuffled[i], shuffled[j]);
            leftSize--;
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
