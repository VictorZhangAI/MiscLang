class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> m;
        for(int i = 0; i < position.size(); i++)
            m[-position[i]] = (double)(target - position[i]) / speed[i];
        int res = 0; double cur = 0;
        for(auto it : m) if(it.second > cur) cur = it.second, res++;
        return res;
    }
};
