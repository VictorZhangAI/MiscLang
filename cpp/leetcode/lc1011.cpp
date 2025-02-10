class Solution {
public:
    bool possible(vector<int>& weights, int n, int days, int cmp)
    {
        int dayCnt = 1, load = 0;

        for(int i = 0; i < n; i++)
        {
            if(load + weights[i] > cmp)
            {
                dayCnt++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return dayCnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(possible(weights, n, days, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
