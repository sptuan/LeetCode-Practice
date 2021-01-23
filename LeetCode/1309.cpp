class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for(int i=0; i<s.size(); i++){
            if(i+2<s.size()){
                if(s[i+2] == '#'){
                    ans.push_back('a' + (s[i] -'0')*10 +s[i+1] - '0' - 1 );
                    i = i+2;
                }
                else{
                    ans.push_back('a' + s[i] - '0' - 1);
                }
            }
            else{
                ans.push_back('a' + s[i] - '0' - 1);
            }
        }
        return ans;
    }
};
