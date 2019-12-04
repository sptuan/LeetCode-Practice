// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long high = n;
        high++;
        long long low = 0;
        long long result = guess((low+ high)/2);

        while(result != 0){
            if(result == 1){
                low = (high - low)/2 + low;
            }
            else{
                high = (high - low)/2 + low;
            }
            result = guess((high - low)/2 + low);
        }
        return int((high - low)/2 + low);
    }
};
