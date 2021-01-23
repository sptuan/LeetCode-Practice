class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        if(s.size() == 0) return 0;
        int max_substr = 1;
        for(int i=0; i<s.size(); i++){
            int dp[s.size()];
            dp[i] = 1;
            unordered_map<int,bool> hash_t;
            hash_t[s[i]] = true;

            for(int j=i+1; j<s.size(); j++){
                if(dp[j-1] == 0){
                    break;
                }
                else{
                    if(hash_t[s[j]] == true){
                        dp[j] = 0;
                        break;
                    }
                    else{
                        hash_t[s[j]] = true;
                        int temp = j-i+1;
                        if(temp>max_substr) max_substr = temp;
                        dp[j] = 1;
                    }
                }
            }
            
        }
        return max_substr;

    }
};
