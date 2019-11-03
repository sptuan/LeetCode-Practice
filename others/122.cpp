class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp_table0;
        vector<int> dp_table1;
        dp_table0.push_back(0);
        dp_table1.push_back(INT_MIN);

        for(int i=0; i<prices.size(); i++){
            dp_table0.push_back(max(dp_table0[i], dp_table1[i] + prices[i]));
            //cout<<"Day "<<i<<" NONE: "<<max(dp_table0[i], dp_table1[i] + prices[i])<<endl;
            dp_table1.push_back(max(dp_table0[i] - prices[i], dp_table1[i]));
            //cout<<"Day "<<i<<" HAVE: "<<max(dp_table0[i] - prices[i], dp_table1[i])<<endl;
        }
        return dp_table0[prices.size()];
    }
};
