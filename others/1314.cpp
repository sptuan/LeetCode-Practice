class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> ans;
        if(mat.size() == 0) return ans;
        if(mat[0].size() == 0) return ans;
        
        vector<int> ans_temp(mat[0].size());
        
        for(int i=0; i<mat.size(); i++){
            ans.push_back(ans_temp);
        }
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                int ans_temp = 0;
                //cout<<"@col"<<i<<"@con"<<j<<endl;
                for(int i_col = i - K; i_col <= i + K; i_col ++){
                    for(int j_con = j - K; j_con <= j+K; j_con ++){
                        
                        if(i_col >=0 && i_col <mat.size() &&\
                          j_con >=0 && j_con < mat[0].size()){
                            ans_temp += mat[i_col][j_con];
                        }
                    }
                }
                ans[i][j] = ans_temp;
                
                
            }
        }
        return ans;
    }
};
