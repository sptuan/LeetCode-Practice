class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int a,b;
        vector<int> ans;
        for(int i=0; i<nums.size()/2; i++){
            if(2*i + 1 >=nums.size()){
                break;
            }
            a = nums[2*i];
            b = nums[2*i + 1];
            for(int j=0; j<a; j++){
                ans.push_back(b);
            }
            
        }
        return ans;
    }
};
