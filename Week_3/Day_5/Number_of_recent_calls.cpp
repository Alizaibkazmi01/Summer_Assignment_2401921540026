class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {  
    }
    
    int ping(int t) {
        v.push_back(t);
        int n=v.size();
        int ans=0;
        for(int i=n-1;i>=0;i--) {
            if((v[n-1]-v[i])<=3000) ans++;
        }
        return ans;
    }
};

