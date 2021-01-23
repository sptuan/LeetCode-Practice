class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        vector<int> x,y;
        for(int i=0; i<grid.size(); i++){
            int temp_y = 0;
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) temp_y++;
            }
            y.push_back(temp_y);
        }
        for(int i=0; i<grid[0].size(); i++){
            int temp_y = 0;
            for(int j=0; j<grid.size(); j++){
                if(grid[j][i] == 1) temp_y++;
            }
            x.push_back(temp_y);
        }
        int ans = 0;
       for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    if(y[i]>1){
                        ans++;
                        continue;
                    }
                    if(x[j]>1){
                        ans++;
                        continue;
                    }
                }
            }
        }
        return ans;
    }
};
