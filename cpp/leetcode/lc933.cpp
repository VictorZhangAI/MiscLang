class RecentCounter {
public:
    vector<int> records;
    int start;
    RecentCounter() : start(0) {
        
    }
    
    int ping(int t) {
        records.push_back(t);
        while(records[start] < t - 3000)
        {
            start++;
        }
        return records.size() - start;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
