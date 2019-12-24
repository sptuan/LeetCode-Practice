class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> booked(n+1,0);
        for(int i=0; i<bookings.size(); i++){
            booked[bookings[i][0]-1] += bookings[i][2];
            booked[bookings[i][1]] -= bookings[i][2];
        }
        int sum = 0;
        for(int i=0; i<booked.size(); i++){
            sum += booked[i];
            booked[i] = sum;
        }
        booked.pop_back();
        return booked;
    }
};
