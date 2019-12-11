class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<int> group_by_num[groupSizes.size()+1];
        for(int i=0; i<groupSizes.size(); i++){
            group_by_num[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for(int i=0; i<groupSizes.size()+1; i++){
            if(group_by_num[i].size()==0) continue;
            vector<int> temp;
            for(int j=0; j<group_by_num[i].size(); j++){
                temp.push_back(group_by_num[i][j]);
                if(temp.size() == i){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
    return ans;
    }
};
