class Solution {
public:
int check(string s, int left, int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
}
    string longestPalindrome(string s) {
        if(s.size()<=1)return s; // base case incase the string is empty or contains only one char
        int start=0;
        int end=0;
        int len_max=1;
        string ans=s.substr(0,1);
        int starting_idx=0;

        for(int i=0;i<s.size()-1;i++){
            int odd=check(s,i,i);
            int even=check(s,i,i+1);
            len_max=max(odd,even);
            if(len_max>end-start+1){
                start = i - (len_max - 1) / 2;
                end = i + len_max / 2;
            }
        }
        return s.substr(start,end-start+1);
    }
};
