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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ppre;
        ListNode* point;
        ListNode* pnext;
        ListNode temp_head(-1);
        temp_head.next = head;
        point = head;
        ppre = &temp_head;
        while(point!=NULL){
            if(point->val == val){
                ppre->next = point->next;
                point = ppre->next;
                continue;
            }
            ppre = point;
            point = point->next;

        }

        return temp_head.next;
    }
};
