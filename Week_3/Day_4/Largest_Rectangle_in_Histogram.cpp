class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),h,left,width;
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                h = heights[st.top()];
                st.pop();
                left = st.empty() ? -1 : st.top();
                width = i - left - 1;
                ans = max(ans, h * width);
            }
            st.push(i);
        }
        return ans;
    }
};
