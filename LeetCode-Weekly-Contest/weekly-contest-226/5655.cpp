class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> conn;
        for(auto &p:adjacentPairs){
            conn[p[0]].push_back(p[1]);
            conn[p[1]].push_back(p[0]);
        }
        
        int start;
        
        for(auto &p:conn){
            if(p.second.size()!=2) start = p.first;
        }
        //cout<<"[INFO] find start "<<start<<endl;
        
        vector<int> ans;
        int point = start;
        int counter = 0;
        unordered_map<int,bool> visited;
        while(counter != adjacentPairs.size()+1){
            ans.push_back(point);
            visited[point] = true;
            if(conn[point].size()!=2){
                point = conn[point][0];
            }
            else{
                int test = conn[point][0];
                if(visited[test] == false){
                    point = test;
                }
                else{
                    point = conn[point][1];
                }
            }
            counter ++;
        }
        return ans;
    }
};
