class Solution {
public:
    bool lt(int a, int b)
    {
        return a < b;
    }
    int partition(vector<int>& a, int lo, int hi)
    {
        int i = lo, j = hi + 1;
	while(true)
	{
		while(lt(a[++i], a[lo]))
			if(i == hi) break;

		while(lt(a[lo], a[--j]))
			if(j == lo) break;

		if(i >= j) break;
		swap(a[i], a[j]);	
	    }

	    swap(a[lo], a[j]);
	    return j;
    }
    void sorting(vector<int> &a, int lo, int hi)
    {
        if(hi <= lo) return;
	    int j = partition(a, lo, hi);
	    sorting(a, lo, j - 1);
	    sorting(a, j + 1, hi);
    }
    void sortColors(vector<int>& nums) {
        sorting(nums, 0, nums.size() - 1);
    }
};
