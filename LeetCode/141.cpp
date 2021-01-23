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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        //int slow_counter = 0;
        do{
            if(slow->next != NULL){
                slow = slow->next;
            }
            else{
                return false;
            }

            if(fast->next!=NULL){
                fast = fast->next;
            }
            else{
                return false;
            }
            if(fast->next!=NULL){
                fast = fast->next;
            }
            else{
                return false;
            }

        }while(slow != fast);
        return true;
    }
};
