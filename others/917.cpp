class Solution {
public:
    string reverseOnlyLetters(string S) {
        string ans;
        string S_r ;
        for(auto &it:S){
            if((it<='z' && it>='a') || (it>='A' && it<='Z')){
                S_r.push_back(it);
            }
        }

        reverse(S_r.begin(),S_r.end());

        int pointer = 0;

        for(auto &it:S){
            if((it<='z' && it>='a') || (it>='A' && it<='Z')){
                ans.push_back(S_r[pointer]);
                pointer++;
            }
            else{
                ans.push_back(it);
            }
        }
        return ans;
    }
};
