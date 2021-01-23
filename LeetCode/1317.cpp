class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1; i<n; i++){
            int test = i;
            int test2 = n - i;
            int flag1 = 0 ;
            while(test != 0){
                if(test % 10 == 0){
                    flag1 = 1;
                    break;
                }
                test /= 10;
            }
            if(flag1 == 1) continue;
            
            int flag2 = 0;
            while(test2 != 0){
                if(test2 % 10 == 0){
                    flag2 = 1;
                    break;
                }
                test2 /= 10;
            }
            if(flag2 == 1) continue;
            ans.push_back(i);
            ans.push_back(n-i);
            return ans;
        }
        return ans;
    }
};
