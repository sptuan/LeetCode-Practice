class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0; i<points.size()-1; i++){
            int dx = abs(points[i+1][0] - points[i][0]);
            int dy = abs(points[i+1][1] - points[i][1]);
            //cout<<"dx "<<dx<<" dy "<<dy<<endl;
            //cout<<"+= "<<min(dx, dy) + abs(dx - dy)<<endl;
            ans += min(dx, dy) + abs(dx - dy);
        }
        return ans;
    }
};
