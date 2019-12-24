class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=1) return true;
        double target_k = double(coordinates[1][1] - coordinates[0][1]) \
                / double(coordinates[1][0] - coordinates[0][0]);

        for(int i=0; i<coordinates.size()-1; i++){
            double k = double(coordinates[i+1][1] - coordinates[i][1]) \
                / double(coordinates[i+1][0] - coordinates[i][0]);
            if(k!=target_k) return false;
        }  
        return true;
    }
};
