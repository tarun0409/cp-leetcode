class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int pings = 0;
        int leftBount = t-3000;
        v.insert(v.begin(),t);
        for(int i=0; i<v.size(); i++)
        {
            if(v[i] >= leftBount)
            {
                pings++;
            }
            else
            {
                break;
            }
        }
        return pings;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
