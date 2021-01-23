class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp(nums.size());

        int min_temp = 1;
        int max_temp = 1;
        int max_ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int max_step, min_step;
            if(nums[i]<0){
                int temp = max_temp;
                max_temp = max(min_temp * nums[i], nums[i]);
                min_temp = min(temp * nums[i], nums[i]); 
            }
            else{
                max_temp = max(max_temp * nums[i], nums[i]);
                min_temp = min(min_temp * nums[i], nums[i]);
            }
            if(max_temp > max_ans){
                max_ans = max_temp;
            }
            //cout<<"max: "<<max_temp<<"\t min:"<<min_temp<<endl;
        }

        return max_ans;
    }
};
