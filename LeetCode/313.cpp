class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        dp[0] = 1;
        vector<int> p(primes.size());

        for(int i=1; i<n; i++){
            vector<int> temp;
            for(int k=0; k<primes.size(); k++){
                temp.push_back(primes[k]*dp[p[k]]);
            }
            int temp_min = INT_MAX;
            for(auto &it:temp){
                if(it<temp_min){
                    temp_min = it;
                }
            }

            dp[i] = temp_min;
            for(int k=0; k<primes.size(); k++){
                if(dp[i] == temp[k]){
                    p[k]++;
                }
            }
            //cout<<dp[i]<<endl;
        }

        return dp[n-1];
    }
};
