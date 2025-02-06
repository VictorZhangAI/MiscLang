class Solution {
public:
    //using dp method
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        vector<int> indices = {0, 0, 0};
        vector<int> uglyArr(1, 1);

        for(int i = 1; i < n; i++)
        {
            vector<int> next_uglies = {
                uglyArr[indices[0]] * primes[0],
                uglyArr[indices[1]] * primes[1],
                uglyArr[indices[2]] * primes[2]
            };
            int min_value = *min_element(next_uglies.begin(), next_uglies.end());
            uglyArr.push_back(min_value);
            for(int j = 0; j < 3; j++)
            {
                if(next_uglies[j] == min_value)
                {
                    ++indices[j];
                }
            }
        }
        return uglyArr[n - 1];
    }
};
