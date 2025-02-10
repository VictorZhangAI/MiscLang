class Solution {
public:
    int solve(vector<int>& arr, int mid)
    {
        int cnt = 1;
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(sum + arr[i] <= mid)
                sum += (long long)(arr[i]);
            else
            {
                cnt++;
                sum = (long long)(arr[i]);
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int cnt = solve(nums, mid);
            if(cnt > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
