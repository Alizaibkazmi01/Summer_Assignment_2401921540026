class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>st;
        int i=n-1;
        while(i>=0)
        {
            int count=1;
            if(!st.empty()&&st.top().first>temp[i])
            {
                ans[i]=st.top().second-i;
                st.push({temp[i],i});
                i--;
                continue;
            }
            while(!st.empty()&&st.top().first<=temp[i])
            {
                count++;
                st.pop();
            }
            if(st.empty()==true)
            {
                ans[i]=0;
                st.push({temp[i],i});
            }
            else 
            {
                ans[i]=st.top().second-i;
                st.push({temp[i],i});
            }
            i--;
        }
        return ans;
    }
};
