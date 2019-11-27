class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(),0);
        stack<pair<int,int>> s;
        for(int i=0; i<T.size(); i++){
            if(s.size()==0){
                s.push(make_pair(i,T[i]));
            }
            else{
                auto top_temp = s.top();
                if(T[i]>top_temp.second){
                    ans[top_temp.first] = i - top_temp.first;
                    s.pop();
                    i--;
                    continue;
                }
                s.push(make_pair(i,T[i]));
            }
        }
        return ans;
    }
};
