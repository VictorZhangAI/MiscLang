class Solution {
public:
    int arr[31];
    int fib(int n) {
        if(n == 0)
            return 0;
        arr[0] = arr[1] = 1;
        for(int i = 2; i < 31; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n - 1];
    }
};
