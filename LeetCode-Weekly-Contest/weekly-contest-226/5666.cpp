class Solution {
public:
    bool checkPartitioning(string s) {
        return check(s, 0, s.size()-1, 3);
    }
    bool check(string &s, int l, int r, int rest){
        if(r<l) return false;
        if(rest==1){
            return checkPart(s,l,r);
        }
        for(int i=l; i<r; i++){
            bool test = checkPart(s, l ,i);
            if(test == true){
                if(check(s, i+1, r, rest-1) == true) return true;
            }
        }
        return false;
    }
    
    bool checkPart(string &s, int l, int r){
        auto p = make_pair(l,r);
        if(tested[p]==true){
            return hmap[p];
        }
        tested[p]=true;
        
        if(r<l) return false;
        while(l<r){
            if(s[l]!=s[r]){
                hmap[p] = false;
                return false;
            } 
            l++;
            r--;
        }
        hmap[p] = true;
        return true;
    }
    
    map<pair<int,int>,bool> hmap;
    map<pair<int,int>,bool> tested;
};
