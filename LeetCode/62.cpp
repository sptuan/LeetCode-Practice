class Solution {
public:
    int uniquePaths(int m, int n) {
        return ajax(m,n);
    }
private:
    int ajax(int m ,int n){
        vector<int> cache;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    cache.push_back(1);
                }
                else{
                    int temp = cache[m*i + j -1] + cache[m*(i-1) + j];
                    cache.push_back(temp);
                }


            }
        }

        return *(cache.end() - 1);
    }
};
