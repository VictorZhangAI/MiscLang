class SegTree
{
public:
    int tree_size;
    vector<int> tree;

    void build(int lx, int rx, int ni, const vector<int>& nums)
    {
        if(rx - lx == 1)
        {
            if(lx < nums.size())
                tree[ni] = nums[lx];
            return;
        }

        int m = (lx + rx) >> 1;
        build(lx, m, ni * 2 + 1, nums);
        build(m, rx, ni * 2 + 2, nums);

        tree[ni] = max(tree[ni * 2 + 1], tree[ni * 2 + 2]);
    }

    int query(int l, int r, int lx, int rx, int ni)
    {
        if(r <= lx || l >= rx)
            return -1e4;

        if(l <= lx && r >= rx)
            return tree[ni];

        int m = (lx + rx) >> 1;
        return max(query(l, r, lx, m, ni * 2 + 1),
                    query(l, r, m, rx, ni * 2 + 2));
    }

    SegTree(int n)
    {
        tree_size = 1;
        while(tree_size < n)
            tree_size <<= 1;

        tree = vector<int>(tree_size * 2);
    }

    void build(const vector<int>& nums)
    {
        build(0, tree_size, 0, nums);
    }

    int query(int l, int r)
    {
        return query(l, r + 1, 0, tree_size, 0);
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        SegTree seg_tree(n);
        seg_tree.build(nums);

        vector<int> ans(nums.size() - k + 1);
        for(int i = 0; i <= nums.size() - k; i++)
            ans[i] = seg_tree.query(i, i + k - 1);

        return ans;
    }
};
