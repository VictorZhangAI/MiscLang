class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x < 10)
            return true;
        else
        {
            deque<int> dq; int i = 0;
            while(x != 0)
            {
                i = x % 10, x /= 10;
                dq.push_back(i);
            }
            for(int i = 0, j = dq.size() - 1; i <= j; i++, j--)
            {
                if(dq[i] != dq[j])
                    return false;
            }
            return true;
        }
    }
};
