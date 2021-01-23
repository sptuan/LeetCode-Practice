class Solution {
public:
    int nthUglyNumber(int n) {
        //unordered_map<int,bool> hash_t;
        //bool hash_t[2123366401];
        vector<int> dp(n,0);
        int pointer2 = 0;
        int pointer3 = 0;
        int pointer5 = 0;

        dp[0] = 1;
        for(int i=1; i<n; i++){
            dp[i] = min(dp[pointer2]*2, min(dp[pointer3]*3, dp[pointer5]*5));
            cout<<dp[i]<<endl;
            if(dp[i] == dp[pointer2]*2){
                pointer2++;
            }
            if(dp[i] == dp[pointer3]*3){
                pointer3++;
            }
            if(dp[i] == dp[pointer5]*5){
                pointer5++;
            }
        }
        return dp[n-1];

    }
};
