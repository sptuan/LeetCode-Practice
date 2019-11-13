/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans=0;
        unordered_map<int,Employee*> hash_t;
        queue<Employee*> q;
        
        
        for(auto &em:employees){
            hash_t[em->id] = em;
        }
        
        q.push(hash_t[id]);
        while(q.size()!=0){
            auto temp = q.front();
            q.pop();
            ans+=temp->importance;
            for(auto &it:(temp->subordinates)){
                q.push(hash_t[it]);
            }
        }
        
        return ans;
    }
};
