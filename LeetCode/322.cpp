class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int i=0; i<=amount; i++){
            for(int coins_i =0; coins_i < coins.size(); coins_i++){
                int temp = i - coins[coins_i];
                if(temp >= 0){
                    if(dp[temp]!=-1){
                        if(dp[i] == -1) dp[i] = dp[temp] + 1;
                        else{
                            if(dp[i]> dp[temp]+1) dp[i] = dp[temp]+1;
                        }
                    }
                }
            }
            //cout<<dp[i]<<endl;
        }

        return dp[amount];


    }
};
