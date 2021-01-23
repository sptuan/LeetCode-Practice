
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> plus_counter;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                plus_counter[nums[i]*nums[j]]++;
            }
        }
        int sum = 0;
        for(auto &it:plus_counter){
            int num = it.second;
            sum += (num*(num-1)/2);
        }
        return sum*8;
    }
};