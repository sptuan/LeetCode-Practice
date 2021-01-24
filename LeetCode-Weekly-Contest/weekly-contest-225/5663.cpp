class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> dp = matrix;
        vector<int> ans;
        ans.push_back(matrix[0][0]);
        // init dp mat
        for(int i=1; i<matrix[0].size(); i++){
            dp[0][i] = dp[0][i-1] ^ dp[0][i];
            ans.push_back(dp[0][i]);
            //cout<<"[init i] "<<dp[0][i]<<endl;
        }
        for(int j=1; j<matrix.size(); j++){
            dp[j][0] = dp[j-1][0] ^ dp[j][0];
            ans.push_back(dp[j][0]);
            //cout<<"[init j] "<<dp[j][0]<<endl;
        }
        // process DP
        for(int j=1; j<matrix.size(); j++){
            for(int i=1; i<matrix[0].size(); i++){
                dp[j][i] = dp[j-1][i] ^ dp[j][i-1] ^ dp[j-1][i-1] ^ dp[j][i];
                ans.push_back(dp[j][i]);
                //cout<<"[dp] "<<dp[j][i]<<endl;
            }
        }
        // sort ans
        sort(ans.begin(), ans.end());
        //cout<<"[ans] "<<ans[ans.size()-k]<<endl;
        return ans[ans.size()-k];
    }
};
