class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> result;

        if(m > n) return result;

        vector<int> freqP(26, 0), window(26, 0);

        for(char c : p){
            freqP[c - 'a']++;
        }

        for(int i = 0; i < m; i++){
            window[s[i] - 'a']++;
        }

        if(freqP == window) result.push_back(0);

        for(int i = m; i < n; i++){
            window[s[i] - 'a']++;
            window[s[i - m] - 'a']--;

            if(freqP == window){
                result.push_back(i - m + 1);
            }
        }

        return result;
    }
};
