class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int>  result;
        if(nums.size() == 0)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        while(left != nums.size() - 1 && nums[left] != target)
            left++;
        while(right != -1 && nums[right] != target)
            right--;
        if(left == nums.size() || right == -1)
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        else
        {
            result.push_back(left);
            result.push_back(right);
        }
        return result;
    }
};
