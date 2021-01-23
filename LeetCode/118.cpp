class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0){
            return ans;
        }
        
        for(int i=0; i<numRows; i++){
            vector<int> temp;
            if(i==0){
                temp.push_back(1);
                ans.push_back(temp);
                continue;
            }
            temp.push_back(1);
            for(int j=0;j<(ans[i-1]).size()-1;j++){
                temp.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};
