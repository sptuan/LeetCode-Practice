class Solution {
public:
    int lengthOfLastWord(string s) {
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == ' '){
                s.pop_back();
            }
            else{
                break;
            }
        }
        int count = 0;
        for(auto &it:s){
            if(it!=' '){
                count++;
            }
            else{
                count = 0;
            }
        }

        return count;
    }
};
