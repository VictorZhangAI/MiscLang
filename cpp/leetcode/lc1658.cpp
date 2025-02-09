class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        
        int diff = sum - x;
        int maxLength = -1, currSum = 0;
        for(int l = 0, r = 0; r < nums.size(); r++)
        {
            currSum += nums[r];
            while(l <= r && currSum > sum - x) currSum -= nums[l++];
            if(currSum == diff) maxLength = max(maxLength, r - l + 1);
        }
        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};
