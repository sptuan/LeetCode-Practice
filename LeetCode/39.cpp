class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<vector<vector<int>>> dp(target+1);

        for(int i=0; i<candidates.size(); i++){
            if(candidates[i] > target) continue;
            vector<int> temp;
            temp.push_back(candidates[i]);
            dp[candidates[i]].push_back(temp);
        }

        for(int i=1; i<=target; i++){
            map<vector<int>,bool> hash_t;

            for(int j=0; j<candidates.size(); j++){
                if(i-candidates[j]>=0){
                    //iter in dp[i - cand]
                    for(auto it:dp[i - candidates[j]]){
                        it.push_back(candidates[j]);
                        sort(it.begin(),it.end());
                        if(hash_t[it] == false){
                            dp[i].push_back(it);
                            hash_t[it] = true;
                        }
                    }
                }
            }
        }

        return dp[target];

    }
};
