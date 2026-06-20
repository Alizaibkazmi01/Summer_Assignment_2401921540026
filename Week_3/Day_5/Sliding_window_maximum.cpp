class Solution {
public:
    typedef pair<int,int> P;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,bool> removed;
        priority_queue<P> pq; // {value, index}

        // First window
        for(int i = 0; i < k; i++){
            pq.push({nums[i], i});
        }

        int l = 0, r = k - 1;
        vector<int> ans;

        while(r < n){

            // Remove invalid elements
            while(!pq.empty() && removed[pq.top().second]){
                pq.pop();
            }

            // Current max
            ans.push_back(pq.top().first);

            // Slide window
            r++;
            removed[l] = true;
            l++;

            if(r < n){
                pq.push({nums[r], r});
            }
        }

        return ans;
    }
};
