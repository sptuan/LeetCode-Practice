class Solution {
public:
    string maximumTime(string time) {
        int hh1=0;
        int hh2=0;
        int mm1=0;
        int mm2=0;
        bool flag = false;
        int sp = 0;
        // search :
        for(int i=0; i<time.size(); i++){
            if(time[i] == ':'){
                sp = i;
                break;
            }
        }
        // test
        // X:
        if(sp-0 == 1){
            if(time[0] == '?'){
                hh2 = 9;
            }
            else{
                hh2 = time[0]-'0';
            }
        }
        // XX:
        else if(sp-0 == 2){
            if(time[0] == '?'){
                // ?X:XX
                if(time[1] != '?'){
                    hh2 = time[1]-'0';
                    if(hh2 > 3){
                        hh1 = 1;
                    }
                    else{
                        hh1 = 2;
                    }
                }
                // ??:XX
                else{
                    hh1 = 2;
                    hh2 = 3;
                }
            }
            else{
                // X?:XX
                hh1 = time[0] - '0';
                if(time[1] == '?'){
                    if(hh1 == 1 || hh1 == 0) hh2 = 9;
                    else if(hh1 == 2) hh2 = 3;
                }
                else{
                    hh2 = time[1] - '0';
                }
            }
        }
        
        
        
        // :X
        if(time.size() - 1 - sp == 1){
            if(time[sp+1] == '?'){
                mm2 = 9;
            }
            else{
                mm2 = time[sp+1]-'0';
            }
        }
        // :XX
        else if(time.size() - 1 - sp == 2){
            if(time[sp+1] == '?'){
                // :?X
                if(time[sp+2] != '?'){
                    mm1 = 5;
                    mm2 = time[sp+2]-'0';
                }
                // :??
                else{
                    mm1 = 5;
                    mm2 = 9;
                }
            }
            else{
                // :X?
                if(time[sp+2] == '?'){
                    mm1 = time[sp+1] - '0';
                    mm2 = 9;
                }
                else{
                    mm1 = time[sp+1] - '0';
                    mm2 = time[sp+2] - '0'; 
                }
            }
        }
        
        string ans;
        // make ans;
        ans.push_back(hh1+'0');
        ans.push_back(hh2 + '0');
        ans.push_back(':');
        ans.push_back(mm1+'0');
        ans.push_back(mm2+'0');
        return ans;
    }
};
