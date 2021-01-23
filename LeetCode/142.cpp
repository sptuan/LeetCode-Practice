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
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        //int slow_counter = 0;
        do{
            if(slow->next != NULL){
                slow = slow->next;
            }
            else{
                return NULL;
            }

            if(fast->next!=NULL){
                fast = fast->next;
            }
            else{
                return NULL;
            }
            if(fast->next!=NULL){
                fast = fast->next;
            }
            else{
                return NULL;
            }

        }while(slow != fast);

        slow = head;

        while(slow!=fast){
            if(slow->next != NULL){
                slow = slow->next;
            }
            else{
                return NULL;
            }
            if(fast->next!=NULL){
                fast = fast->next;
            }
            else{
                return NULL;
            }

        }
        return slow;
    }
};
