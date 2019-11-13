class Solution {
public:
    string removeVowels(string S) {
        string ans;
        for(auto &it:S){
            if(it!='a' && it!='e' && it!='i' && it!='o' && it!='u'){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
