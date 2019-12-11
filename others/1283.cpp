class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max_t = INT_MIN;
        int min_t = INT_MAX;
        if(nums.size() == 1){
            int temp = 0;
            if(nums[0] % threshold == 0){
                return nums[0] / threshold;
            }
            else{
                return nums[0] / threshold + 1;
            }
        }
        for(auto &it:nums){
            if(it>max_t) max_t = it;
            if(it<min_t) min_t = it;
        }

        int l = 1;
        int r = max_t;

        while(l<r){
            int sum_temp = 0;
            int test = (l - r)/2 + r;
            for(auto &it:nums){
                if(it%test == 0){
                    sum_temp += it/test;
                }
                else{
                    sum_temp += it/test + 1;
                }
            }
            //cout<<"TEST "<<test<<endl;
            if(l == test) break;
            if(r == test) break;

            if(sum_temp>threshold){
                l = test;
            }
            else{
                r = test;
            }
        }

        while(1){
            
            int sum_temp = 0;
            int test = l;
            for(auto &it:nums){
                if(it%test == 0){
                    sum_temp += it/test;
                }
                else{
                    sum_temp += it/test + 1;
                }
            }
            //cout<<"TEST+ "<<l<<" sum "<<sum_temp<<endl;
            if(sum_temp>threshold){
                l++;
            }
            else{
                break;
            }
        }
        return l;

    }
};
