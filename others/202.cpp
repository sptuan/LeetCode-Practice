class Solution {
public:
    bool isHappy(int n) {
        map<int,bool>  hash_t;

        while(1){
            if(hash_t[n] == true) return false;

            int temp = n;
            int sum = 0;
            hash_t[n] = true;

            while(temp!=0){
                int a = temp%10;
                sum +=a*a;
                temp = temp/10;
            }
            if(sum == 1) return true;
            n = sum;
        }
    }
};
