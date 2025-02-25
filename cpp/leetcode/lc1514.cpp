class Solution {
public:
    vector<vector<pair<double, int>>> adj;

    void create_adj(int n, vector<vector<int>>& edges, vector<double>& succProb)
    {
        adj.resize(n);
        int eN = edges.size();
        for(int i = 0; i < eN; i++)
        {
            int v0 = edges[i][0], v1 = edges[i][1];
            adj[v0].push_back({succProb[i], v1});
            adj[v1].push_back({succProb[i], v0});
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, 0);
        create_adj(n, edges, succProb);
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;

        pq.push({1.0, start_node});
        prob[start_node] = 1.0;

        while(!pq.empty())
        {
            auto [cur_prob, i] = pq.top();
            pq.pop();

            if(i == end_node)
                return cur_prob;
            
            for(auto [next_prob, j] : adj[i])
            {
                double new_prob = cur_prob * next_prob;
                if(new_prob > prob[j])
                {
                    prob[j] = new_prob;
                    pq.push({new_prob, j});
                }
            }
        }
        return 0.0;
    }
};
