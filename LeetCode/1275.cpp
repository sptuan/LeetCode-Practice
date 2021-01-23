class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int state = 0;
        for(int i=0; i<moves.size(); i++){
            if(state == 0){
                space[moves[i][0]][moves[i][1]] = 2;
                state = 1;
            }
            else if(state == 1){
                space[moves[i][0]][moves[i][1]] = 3;
                state = 0;
            }
            int result = check();
            if(result == 2){
                return "A";
            }
            else if(result == 3){
                return "B";
            }
        }
        if(moves.size() == 9) return "Draw";
        else return "Pending";
    }
private:
    int space[3][3] = {0};
    int check(){
        for(int i=0; i<3; i++){
            if(space[i][0] == space[i][1] && space[i][1] == space[i][2]){
                return space[i][0];
            }
            if(space[0][i] == space[1][i] && space[1][i] == space[2][i]){
                return space[0][i];
            }

        }
            if(space[0][0] == space[1][1] && space[1][1] == space[2][2]){
                return space[0][0];
            }
            if(space[2][0] == space[1][1] && space[1][1] == space[0][2]){
                return space[2][0];
            }
        return -1;
    }
};
