class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0) return 0;
        if(k>=prices.size()/2) {
            int dp0 = 0;
            int dp1 = INT_MIN;
            for(int i=0; i<prices.size(); i++){
                int dp0_temp = dp0;
                int dp1_temp = dp1;
                dp0 = max(dp0,dp1+prices[i]);
                dp1 = max(dp1, dp0-prices[i]);
            }
            return dp0;
        }

        int dp[prices.size()][k+1][2];
        for(int i=0; i<prices.size(); i++){
            for(int j=0; j<k+1; j++){
                if(i==0){
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }
                if(j==0){
                    dp[i][j][0] = dp[i-1][j][0];
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i]);
                }
                else{
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i]);
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i]);                    
                }
            }
        }
        int temp = 0;
        for(int i=0; i<k+1; i++){
            //cout<<dp[prices.size()-1][i][0]<<endl;
            if(dp[prices.size()-1][i][0] > temp) temp = dp[prices.size()-1][i][0];
        } 
        return temp;
    }
};
