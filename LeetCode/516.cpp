class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()==0) return 0;
        vector<int> dp_temp(s.size()+1);
        vector<vector<int>> dp(s.size()+1,dp_temp);
        //init dp table
        for(int i=0; i<=s.size(); i++){
            dp[0][i] = 0;
            dp[i][0] = 0;
            if(i!=0){
                dp[i][i] = 1;
            }
        }

        for(int j=2; j<=s.size(); j++){
            for(int i=j-1; i>0; i--){
                if(s[i-1]==s[j-1]){
                    dp[j][i] = dp[j-1][i+1] + 2;
                }
                else{
                    dp[j][i] = max(dp[j-1][i] , dp[j][i+1]);
                }
            }
        }
        return dp[s.size()][1];

    }
};
