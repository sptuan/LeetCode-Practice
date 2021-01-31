class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<long long> past_sum;
        vector<long long> cur_sum;
        long long temp_sum = 0;
        for(int i=0; i<candiesCount.size(); i++){
            past_sum.push_back(temp_sum);
            temp_sum+=candiesCount[i];
            cur_sum.push_back(temp_sum);
        }
        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            long long fav = queries[i][0];
            long long day = queries[i][1];
            long long cap = queries[i][2];
            
            long long min_eaten = day;
            long long max_eaten = day*cap;
            // cout<<"[INFO] min eaten "<<min_eaten<<endl;
            // cout<<"[INFO] max eaten "<<max_eaten<<endl;
            // cout<<"[INFO] past_sum "<<past_sum[fav]<<endl;
            // cout<<"[INFO] cur_sum "<<cur_sum[fav]<<endl;
            bool val1 = past_sum[fav] + 1 >min_eaten+1 && past_sum[fav] + 1 >max_eaten + cap && cur_sum[fav]>min_eaten+1 && cur_sum[fav]>max_eaten+ cap;
            bool val2 = past_sum[fav] + 1 <min_eaten+1 && past_sum[fav] + 1 <max_eaten+ cap && cur_sum[fav]<min_eaten+1 && cur_sum[fav]<max_eaten+ cap;
            if(val1 || val2){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};
