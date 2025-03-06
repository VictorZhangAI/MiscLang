class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int u, m = 0;
        if(x > y)
        {
            u = x;
        }
        else
        {
            u = y;
        }
        if(x + y < target)
        {
            return false;
        }

        for(int i = 1; i <= u; i++)
        {
            if(x % i == 0 && y % i == 0)
            {
                m = max(i, m);
            }
        }
        if(target % m == 0)
        {
            return true;
        }
        return false;
    }
};
