class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> bucket;
        int temp_max = 0;
        for(int i=lowLimit; i<=highLimit; i++){
            int sum = 0;
            int temp = i;
            while(temp != 0){
                sum += temp % 10;
                temp = temp / 10;
            }
            bucket[sum]++;
            if(bucket[sum]>temp_max) temp_max = bucket[sum];
        }
        return temp_max;   
    }
};
