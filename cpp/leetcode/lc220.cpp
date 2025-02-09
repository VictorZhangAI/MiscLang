class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        if(n == 0 || indexDiff < 0 || valueDiff < 0) return false;

        unordered_map<int, int> buckets;

        for(int i = 0; i < n; i++)
        {
            int bucket = nums[i] / (valueDiff + 1);

            if(nums[i] < 0) --bucket;

            if(buckets.find(bucket) != buckets.end()) return true;
            else
            {
                buckets[bucket] = nums[i];
                if(buckets.find(bucket-1) != buckets.end() && nums[i] - buckets[bucket - 1] <= valueDiff)
                    return true;
                if(buckets.find(bucket+1) != buckets.end() && buckets[bucket + 1] - nums[i] <= valueDiff)
                    return true;

                if(buckets.size() > indexDiff)
                {
                    int key_to_remove = nums[i - indexDiff] / (valueDiff + 1);

                    if(nums[i - indexDiff] < 0) --key_to_remove;

                    buckets.erase(key_to_remove);
                }
            }
        }
        return false;
    }
};
