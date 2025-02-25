class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto time : times)
        {
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> network(n + 1, INT_MAX);
        network[k] = 0;

        while(!pq.empty())
        {
            auto [cur_time, cur] = pq.top();
            pq.pop();

            for(auto [new_cur, weight] : adj[cur])
            {
                int new_time = cur_time + weight;

                if(new_time < network[new_cur])
                {
                    network[new_cur] = new_time;
                    pq.push({new_time, new_cur});
                }
            }
        }

        int min_time = 0;
        for(int i = 1; i <= n; i++)
        {
            if(network[i] == INT_MAX) return -1;
            min_time = max(min_time, network[i]);
        }
        return min_time;
    }
};
