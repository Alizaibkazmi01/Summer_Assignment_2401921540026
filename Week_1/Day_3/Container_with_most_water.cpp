class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int result = -10000;

        while (start < end) {
            int w = end - start;
            int h = min(height[start], height[end]);
            int area = h * w;
            result = max(result, area);
            if (height[start] < height[end]) start += 1;
            else end -= 1; 
        }

        return result;
    }
};
