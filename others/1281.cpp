class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int plus = 1;
        int temp = n;
        while(temp != 0){
            int x = temp % 10;
            temp /= 10;
            sum += x;
            plus *= x;
        }

        return plus - sum;
    }
};
