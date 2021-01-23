class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        map<string, vector<string>> hash_t;
        for(int i=0; i<products.size(); i++){
            string temp;
            for(auto &it:products[i]){
                temp.push_back(it);
                hash_t[temp].push_back(products[i]);
            }
        }
        vector<vector<string>> ans;
        string temp;
        for(auto &it:searchWord){
            temp.push_back(it);
            vector<string> ans_temp;
            int m = 3;
            if(hash_t[temp].size()<3) m = hash_t[temp].size();

            for(int j=0; j<m; j++){
                ans_temp.push_back(hash_t[temp][j]);
            }
            ans.push_back(ans_temp);
        }
        return ans;
    }
};
