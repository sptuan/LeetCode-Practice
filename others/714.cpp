class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1) return 0;

        int dp[prices.size()][2];

        for(int i=0; i<prices.size(); i++){
            if(i==0){
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
                continue;
            }
           
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] -fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }

        return dp[prices.size()-1][0];
    }
};
