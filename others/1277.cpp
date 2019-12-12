class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n=matrix[0].size();
        int max_mn;
        if(m>n) max_mn = n;
        else max_mn = m;

        int dp[m][n][max_mn+1];
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j=0; j< n; j++){
                dp[i][j][1] = matrix[i][j];
            }
        }
        
        for(int size=2; size<=max_mn; size++){
            for(int i=0; i<= m - size; i++){
                for(int j=0; j<=n-size; j++){
                    dp[i][j][size] = min(dp[i][j][size-1], min(dp[i+1][j][size-1], min(dp[i][j+1][size-1], dp[i+1][j+1][size-1])));
                }
            }
        }

        for(int size=1; size<=max_mn; size++){
            for(int i=0; i<= m - size; i++){
                for(int j=0; j<=n-size; j++){
                    if(dp[i][j][size] == 1) ans++;
                }
            }
        }

        return ans;
    }
};
