class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans;
        vector<int> ans_pre;
        if(rowIndex < 1){
            return {1};
        }
    
        
        for(int i=0; i<rowIndex+1; i++){
            vector<int> temp;
            if(i==0){
                ans.push_back(1);
                continue;
            }
            
            ans_pre = ans;
            ans.clear();
            
            ans.push_back(1);
            for(int j=0;j<ans_pre.size()-1;j++){
                ans.push_back(ans_pre[j] + ans_pre[j+1]);
            }
            ans.push_back(1);
        }
        return ans;
    }
};
