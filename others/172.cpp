class Solution {
public:
    int trailingZeroes(int n) {
        int n_5 = 0;
        int temp = n;
        while(temp!=0){
            n_5 +=(temp /5);
            temp = temp / 5;
        }
        return n_5;
    }
};
