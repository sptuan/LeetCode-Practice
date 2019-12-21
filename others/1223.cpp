class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        
        vector<vector<vector<int>>>  dp(n+1,vector<vector<int>>(6,vector<int>(16,0)));
        //init
        //dp_sum[length][case]
        //int  dp_sum[n+1][6] = {0};
        //vector<vector<int>> dp_sum(n+1, vector<int>(6,0));

        vector<int> dp_sum(6,0);
        vector<int> dp_sum_new(6,0);
        for(int i=0; i<6; i++){
            dp[0][i][0] = 1;
            dp_sum[i] = 1;
        }
        //seq length n
        for(int len_i=1; len_i<n+1; len_i++){
            //6 cases
            for(int i=0; i<6; i++){
                dp_sum_new[i] = 0;
            }
            for(int case_i = 0; case_i<6; case_i++){
                // max continious for each case
                for(int cons_i=0; cons_i<min(len_i,rollMax[case_i]); cons_i++){
                    if(cons_i == 0){
                        //cout<<"cons: 0 "<<endl;
                        dp[len_i][case_i][cons_i] = dp_sum[case_i];
                    }
                    else{
                        //cout<<"cons:"<<cons_i<<endl;
                        dp[len_i][case_i][cons_i] = dp[len_i-1][case_i][cons_i-1];
                    }
                    for(int sum_i=0; sum_i<6; sum_i++){
                        if(sum_i != case_i){
                            dp_sum_new[sum_i] += dp[len_i][case_i][cons_i];
                            dp_sum_new[sum_i] %= (1000000000 + 7);
                        }
                    }
                    //cout<<"Len:"<<len_i<<" Case: "<<case_i<<"Cons: "<<cons_i<<" \t dp: "<<dp[len_i][case_i][cons_i]<<endl;
                }
            }
            dp_sum = dp_sum_new;
        }
        long long ans = 0;
        for(int case_i =0; case_i<6; case_i++){
            for(int cons_i =0; cons_i<min(rollMax[case_i], n); cons_i++){
                //cout<<"++ Case: "<<case_i<<"Cons: "<<cons_i<<endl;
                ans += dp[n][case_i][cons_i];
                ans %= (1000000000 + 7);
            }
        }



        return ans;
    }
};
