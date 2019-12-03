class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> hash_t;
        unordered_map<char,char> hash_t2;
        //auto exist = hash_t['a'];
        for(int i=0; i<s.size(); i++){
            if(hash_t.find(s[i]) == hash_t.end()){
                hash_t[s[i]] = t[i];
                //cout<<"create key "<<s[i]<<" - "<<t[i]<<endl;
            }
            else{
                //cout<<"check key "<<s[i]<<" - "<<t[i]<<endl;
                if(hash_t[s[i]] != t[i]) return false;
            }
            
            if(hash_t2.find(t[i]) == hash_t2.end()){
                hash_t2[t[i]] = s[i];
                //cout<<"create key "<<s[i]<<" - "<<t[i]<<endl;
            }
            else{
                //cout<<"check key "<<s[i]<<" - "<<t[i]<<endl;
                if(hash_t2[t[i]] != s[i]) return false;
            }            
            
        }
        return true;
    }
};
