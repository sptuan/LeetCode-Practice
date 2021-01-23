/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode pre_head(0);
        pre_head.next = head;
        ListNode* pre = &pre_head;
        unordered_map<int,bool> hash_t;
        ListNode* point = head;
        while(point!=NULL){
            if(hash_t[point->val] == true){
                pre->next = point->next;
                //cout<<"DEL "<<point->val<<endl;
            }
            else{
                hash_t[point->val] = true;
                //cout<<"SKIP "<<point->val<<endl;
                pre = point;
            }
            
            point = point->next;
        }
        return pre_head.next;
    }
};
