class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        int det = tomatoSlices - 2*cheeseSlices;
        if(det < 0) return ans;
        if(tomatoSlices % 2 != 0 ) return ans;
        if(det % 2 != 0) return ans;
        if((2*cheeseSlices - tomatoSlices/2)<0) return ans;
        return {det / 2, 2*cheeseSlices - tomatoSlices/2};
    }
};
