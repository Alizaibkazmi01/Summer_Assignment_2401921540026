class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        vector<int> ans;

        while (start <= end) {
            if (abs(nums[start]) >= abs(nums[end])){
                ans.push_back(nums[start]*nums[start]);
                 start++;
            }else{
                ans.push_back(nums[end]*nums[end]);
                end--;
            }
           
        }

     reverse(ans.begin(), ans.end());

     return ans;
    }
};
