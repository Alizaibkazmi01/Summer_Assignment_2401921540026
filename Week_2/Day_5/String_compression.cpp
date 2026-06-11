class Solution {
public:
    int compress(vector<char>& chars) {
        char curch = chars[0];
        int count = 0;
        int st = 0;
        for(int i=0;i<chars.size();i++){
            if(curch == chars[i]){
                count++;
            }
            else {
                chars[st] = curch;
                st++;
                if(count > 1){
                    string str = to_string(count);
                    for(char ch: str){
                        chars[st] = ch;
                        st++;
                    }
                }
                count = 1;
                curch = chars[i];

            }
        }
        chars[st]= curch;
        st++;
        if(count > 1){
            string str = to_string(count);
            for(char ch: str){
                chars[st] = ch;
                st++;
            }
        }
        return st;
    }
};
